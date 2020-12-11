#include<stdio.h>
#include<stdlib.h>

int main() {
	puts("I am writing Hello World program... but... what is #include?");

	puts("");
	puts("#include (Please tell me here)");
	puts("int main() {");
	puts("	printf(\"Hello World\");");
	puts("}");
	puts("");

	printf("Enter your program:"); fflush(stdout);
	char include_file[30];
	fgets(include_file, 30, stdin);

	puts("");
	printf("#include %s", include_file);
	puts("int main() {");
	puts("	printf(\"Hello World\");");
	puts("}");
	puts("");

	FILE *fp = fopen("/tmp/program.c", "w");
	fprintf(fp, "#include %s", include_file);
	fprintf(fp, "int main() {");
	fprintf(fp, "	printf(\"Hello World\");");
	fprintf(fp, "}");
	fclose(fp);

	system("rm /tmp/program -f");
	system("gcc /tmp/program.c -o /tmp/program");
	system("/tmp/program");
}
