#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main() {
	alarm(60);
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

	srand(time(NULL));
	char c_filename[64], bin_filename[64];
	int random = rand();
	sprintf(c_filename, "/tmp/program_%d.c", random);
	sprintf(bin_filename, "/tmp/program_%d", random);

	FILE *fp = fopen(c_filename, "w");
	fprintf(fp, "#include %s", include_file);
	fprintf(fp, "int main() {");
	fprintf(fp, "	printf(\"Hello World\");");
	fprintf(fp, "}");
	fclose(fp);
	
	char command[128];
	sprintf(command, "gcc -o %s %s", bin_filename, c_filename);
	system(command);

	system(bin_filename);

	// sprintf(command, "rm %s %s -f", bin_filename, c_filename);
	sprintf(command, "rm %s -f", bin_filename);
	system(command);
}
