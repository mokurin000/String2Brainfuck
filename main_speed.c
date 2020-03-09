#include <stdio.h>
// #define DEBUG

int _Abs(register int a, register int b) {
	register int t = a-b;
	a = t < 0 ? -t : t;
	return a;
}

int main(int argc, char **argv) {
	register int i = 0,j,k,l,m,last = 0;
	if (argc != 2) {
		printf("Usage: %s [string]",*argv);
		return 1;
	}
	while (argv[1][++i]!=0)
		continue;
	for (j=0; j<i; j++) {
		register int t;
		t = argv[1][j];
		l = k = t-last;
		last = t;
#ifdef DEBUG
		printf("\n%d, %d, %d, %d\n",last,k,j,i);
#endif

		if (k >= 0) {
			k >>= 3; // k /= 8
			l &= 7; //在更多的机器工作，求余
			if (k == 1)
				printf(">++++++++");
			else {
				if (k != 0) {
					printf("++++++++[>");
					for (m=0; m<k; m++)
						putchar('+');
					printf("<-]>");
				} else {
					putchar('>');
				}
			}
			for (m=0; m<l; m++)
				putchar('+');
			putchar('.');
		} else {
			k = -k;
			l = -l;
			k >>= 3; // k /= 8
			l &= 7; //在更多的机器工作，求余
			if (k == 1)
				printf(">--------");
			else {
				printf("++++++++[>");
				for (m=0; m<k; m++)
					putchar('-');
				printf("<-]>");
			}
			for (m=0; m<l; m++)
				putchar('-');
			putchar('.');
		}
#ifdef DEBUG
		printf("\n%d, %d, %d\n",m,k,l);
#endif

		putchar('<');
	}

}
