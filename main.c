#include <stdio.h>
int main(int argc, char **argv) {
	register int i=0,j,k,m;
	if (argc!=2) {
		printf("Usage: %s [string]",*argv);
		return 1;
	}
	while (argv[1][++i]!=0);
	for (j=0; j<argv[1][0]; j++)
		putchar('+');
	for (j=1; j<i; j++) {
		k=argv[1][j]-argv[1][j-1];
		if (k>0)
			for (m=k; m>0; m--)
				putchar('+');
		else
			for (m=k; m<0; m++)
				putchar('-');
		putchar('.');
	}
	return 0;
}
