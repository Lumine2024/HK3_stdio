#pragma once
#pragma comment(lib, "hk3_stdio.lib")
#pragma warning(push)
#pragma warning(disable:6031)
#ifndef nullptr
#define nullptr (void*)0
#endif
#ifdef __cplusplus
extern "C" {
#endif
typedef unsigned int size_t;
typedef char *va_list;
typedef unsigned short wchar_t;
__declspec(dllimport) int __cdecl puts(const char *str);
__declspec(dllimport) int __cdecl __stdio_common_vsprintf_s(unsigned __int64 options, char *buffer, size_t buffercnt, const char *format, void *null_ptr, va_list args);
int __cdecl printf(const char *format, ...) {
	va_list arg = (va_list)((char *)&format + sizeof(format));
	char buffer[1024];
	int a = __stdio_common_vsprintf_s(0, buffer, 1024, format, (void *)0, arg);
	puts(buffer);
	return a;
}
__declspec(dllimport) char *__cdecl gets(char *str);
__declspec(dllimport) int __cdecl __stdio_common_vsscanf(unsigned __int64 options, const char *buffer, size_t buffercnt, const char *format, void *null_ptr, va_list args);
int __cdecl scanf(const char *format, ...) {
	va_list arg = (va_list)((char *)&format + sizeof(format));
	char buffer[1024];
	gets(buffer);
	return __stdio_common_vsscanf(0, buffer, 1024, format, (void *)0, arg);
}
typedef struct _iobuf {
	void *ptr;
} FILE;
const int EOF = -1;
__declspec(dllimport) FILE *__cdecl fopen(const char *filename, const char *mode);
__declspec(dllimport) int __cdecl fclose(FILE *stream);
__declspec(dllimport) char *__cdecl fgets(char *str, int n, FILE *stream);
__declspec(dllimport) int __cdecl fputs(const char *str, FILE *stream);
__declspec(dllimport) int __cdecl fflush(FILE *stream);
int __cdecl fprintf(FILE *stream, const char *format, ...) {
	va_list arg = (va_list)((char *)&format + sizeof(format));
	char buffer[1024];
	int a = __stdio_common_vsprintf_s(0, buffer, 1024, format, (void *)0, arg);
	fputs(buffer, stream);
	return a;
}
int __cdecl fscanf(FILE *stream, const char *format, ...) {
	va_list arg = (va_list)((char *)&format + sizeof(format));
	char buffer[1024];
	fgets(buffer, 1024, stream);
	return __stdio_common_vsscanf(0, buffer, 1024, format, (void *)0, arg);
}
int __cdecl sprintf(char *buffer, const char *format, ...) {
	va_list arg = (va_list)((char *)&format + sizeof(format));
	return __stdio_common_vsprintf_s(0, buffer, 1024, format, (void *)0, arg);
}
int __cdecl sscanf(const char *buffer, const char *format, ...) {
	va_list arg = (va_list)((char *)&format + sizeof(format));
	return __stdio_common_vsscanf(0, buffer, 1024, format, (void *)0, arg);
}
#ifdef __cplusplus
}
#endif
#pragma warning(pop)