/**
 * Example of FreeType2 library.
 *
 * How to build:
 * gcc example.c -o example -I/usr/include/freetype2 -lfreetype example.c
 */

#include <ft2build.h>
#include FT_FREETYPE_H

int main(int argc, char** argv) {
	FT_Library library;
	FT_Face face;

	/* Error handling is non-existent in this example. */
	FT_Error error;

	char* filename;

	if (argc != 2) {
		fprintf(stderr, "usage: %s font\n", argv[0]);
		exit(1);
	}

	/* First argument. */
	filename = argv[1];

	/* Initialize library. */
	error = FT_Init_FreeType(&library);

	/* Create face object. */
	error = FT_New_Face(library, filename, 0, &face);

	const short em_size = face->ascender - face->descender;
	const float descender = -(float)face->descender / em_size;
	const float ascender = 1.0f - descender;

	printf("Descender: %d (%4.2f)\n"
	       "Ascender: %d (%4.2f)\n",
	       face->descender,
	       descender,
	       face->ascender, ascender);

	FT_Done_Face(face);
	FT_Done_FreeType(library);

	return 0;
}
