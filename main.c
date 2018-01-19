#include <stdio.h>
#include <math.h>
#include <time.h>

#include "randomsequence_c.h"

int main(){
	srand(time(NULL));
	int sb = rand();
	int so = rand();
	printf("%d,%d ---------\n",sb,so);
	struct RandomSeq *rs = createRandomSeq(sb,so);
	for (int i = 0; i < 12; i++) {
		printf("%d\n",next(rs));
	}
	destoryRandomSeq(rs);
	rs = NULL;
}
