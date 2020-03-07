#include <stdio.h>
int main(int argc, char **argv) {
	register int i = 0,j,k,l,m;
	if (argc != 2) {
		printf("Usage: %s [string]",*argv);
		return 1;
	}
	while (argv[1][++i]!=0);
	for (j=0; j<i; j++) {
		l = k = argv[1][j];
		k >>= 3;
		l &= (1<<k)+1;
		if (k != 0) {
			if (k == 1)
				printf("++++++++");
			else {
				printf("++++++++[>");
				for (m=0; m<k; m++)
					putchar('+');
				printf("<-]>");
			}
		}
		for (m=0; m<l; m++)
			putchar('+');
		putchar('.');
		if (j != i-1)
			putchar('>');
	}
	return 0;
}
// 需要优化