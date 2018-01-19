#ifndef __RANDOM_C_SEQUENCE_H__
#define __RANDOM_C_SEQUENCE_H__

#include <stdlib.h>

struct RandomSeq{
	unsigned int m_index;
	unsigned int m_intermediateOffset;
};

unsigned int permuteQPR(unsigned int x){
	static const unsigned int prime = 4294967291u;
	if (x >= prime)
		return x;  // The 5 integers out of range are mapped to themselves.
	unsigned int residue = ((unsigned long long) x * x) % prime;
	return (x <= prime / 2) ? residue : prime - residue;
}

struct RandomSeq* createRandomSeq(unsigned int seedBase,unsigned int seedOffset){
	struct RandomSeq *ret = malloc(sizeof(struct RandomSeq));
	ret->m_index = permuteQPR(permuteQPR(seedBase) + 0x682f0161);
	ret->m_intermediateOffset = permuteQPR(permuteQPR(seedOffset) + 0x46790905);
	return ret;
}

unsigned int next(struct RandomSeq* rs){
	return permuteQPR((permuteQPR(rs->m_index++) + rs->m_intermediateOffset) & 0x5bf03635);
}

void destoryRandomSeq(struct RandomSeq* rs){
	free(rs);
}

#endif // __RANDOM_C_SEQUENCE_H__
