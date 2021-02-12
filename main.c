/*
 * (c) 2021, Sarah Klocke <sarah.klocke@outlook.com>
 *
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See the
 * LICENSING file or http://www.wtfpl.net/ for more details.
 */

#include <stdio.h>
#include <string.h>

int main(int argc, const char** argv) {
  char current_char;
  char current_char_value;
  char current_byte = 0;
  int i;

  FILE* in_file = NULL;
  FILE* out_file = NULL;

  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
      printf("h2b (hex2binary) version 1.0\n");
      printf("General usage: %s [input...] [-o <output...>]\n", argv[0]);
      printf("\n");

      printf("General arguments:\n");
      printf("------------------\n");
      printf("-h | --help:    Print this message and quit.\n");
      printf("-v | --version: Print the version and quit.\n");
      printf("     --license: Print the license and quit.\n");
      printf("\n");

      printf("File arguments:\n");
      printf("------------------\n");
      printf("[file]:                Reads from the specified file. If not provided, stdin is used.\n");
      printf("-o | --output <file>:  Use <file> as the output file. If not provided, stdout is used.\n");

      return 0;
    } else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0) {
      printf("h2b (hex2binary) version 1.0\n");

      return 0;
    } else if (strcmp(argv[i], "--license") == 0) {
      printf("Copyright (c) 2021 Sarah Klocke <sarah.klocke@outlook.com>\n");
      printf("This work is free. You can redistribute it and/or modify it under the terms of the\n");
      printf("Do What The Fuck You Want To Public License, Version 2, as published by Sam Hocevar.\n");
      printf("See http://www.wtfpl.net/ for more details.\n");

      return 0;
    } else if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--output") == 0) {
      if (i + 1 == argc) {
        fprintf(stderr, "Usage: %s [input...] [-o <output...>]\n", argv[0]);

        return 1;
      }

      i++;
      out_file = fopen(argv[i], "wb");

      if (out_file == NULL) {
        perror("Couldn't open the output file");

        return 3;
      }
    } else {
      if (in_file != NULL) {
        fprintf(stderr, "Usage: %s [input...] [-o <output...>]\n", argv[0]);

        return 1;
      }

      in_file = fopen(argv[i], "r");

      if (in_file == NULL) {
        perror("Couldn't open the input file");

        return 2;
      }
    }
  }

  if (in_file == NULL) {
    in_file = stdin;
  }

  if (out_file == NULL) {
    out_file = stdout;
  }

  i = 0;
  while (!feof(in_file)) {
    fread(&current_char, 1, 1, in_file);

    if (current_char >= '0' && current_char <= '9')
      current_char_value = current_char - '0';
    else if (current_char >= 'a' && current_char <= 'f')
      current_char_value = current_char - 'a' + 0xa;
    else if (current_char >= 'A' && current_char <= 'F')
      current_char_value = current_char - 'A' + 0xa;
    else /* Skip characters that aren't hexadecimal digits. I.e., we don't want to process whitespace. */
      continue;

    current_byte = (current_byte << 4) + current_char_value;

    if (i)
      fwrite(&current_byte, 1, 1, out_file);

    i = (++i) % 2;
  }

  fclose(in_file);
  fclose(out_file);
}
