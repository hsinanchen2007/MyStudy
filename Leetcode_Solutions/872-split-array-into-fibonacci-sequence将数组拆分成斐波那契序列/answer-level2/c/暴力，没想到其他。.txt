### 解题思路
暴力，没想到其他。

### 代码

```c
#define LEN_MAX 10
bool splitIntoFibonacci_goon(char * S, int startPos, int *ret, int *returnSize) {
	long nextNumber, nPre1, nPre2;
	int len, olen;
	char *nextString;
	
	len = strlen(S+startPos);
	olen = len;
	nextString = (char *)calloc(LEN_MAX + 1, sizeof(char));
	
	nPre1 = ret[0];
	nPre2 = ret[1];
	while (len > 0) {
		//printf("\t\tcontinue string:%s, len:%d\n", S+startPos, strlen(S+startPos));
		nextNumber = nPre1 + nPre2;
		if (nextNumber > INT_MAX) {
			return false;
		}
		sprintf(nextString, "%ld", nextNumber);
		//printf("\t\ttry to mach %s, len:%d", nextString, strlen(nextString));
		len -= strlen(nextString);
		if (strncmp(nextString, S+startPos, strlen(nextString)) != 0) {
			//printf(" not match !\n");
			return false;
		} else {
			//printf(" match!!!!!!!!!!!!left len:%d\n", len);
			nPre1 = nPre2;
			nPre2 = nextNumber;
			ret[*returnSize] = nextNumber;
			(*returnSize) ++;
		}
		startPos += strlen(nextString);
		//printf("\t\tstartPos:%d, len:%d\n", startPos, strlen(S));
		memset(nextString, 0, (LEN_MAX + 1)*sizeof(char));
		//printf("\t\tstartPos:%d, len:%d\n", startPos, strlen(S));
	}
	if (len == 0) {
		return true;
	}
	return false;
}

int* splitIntoFibonacci(char * S, int* returnSize){
	int i, j, len, *ret;
	long n1number, n2number;
	char *n1string, *n2string;

	len = strlen(S);
	ret = (int *)calloc(len, sizeof(int));
	n1string = (char *)calloc(len, sizeof(char));
	n2string = (char *)calloc(len, sizeof(char));
	
	*returnSize = 0;

	for (i = 1; i < len; i++) {
		strncpy(n1string, S, i*sizeof(char));
		n1number = atol(n1string);
		if (n1number > INT_MAX) {
			//printf("number 1 is out of range:%ld(MAX:%ld)\n", n1number, INT_MAX);
			break;
		}
		if ((S[0] == '0') && (i > 1)) {
			//printf("number 1 can not be %s, break\n", n1string);
			memset(n1string, 0, len*sizeof(char));
			break;
		}
		memset(n1string, 0, len*sizeof(char));
		//printf("number1: %ld\n", n1number);
		for (j = 1; j < (len - i); j++) {
			strncpy(n2string, S+i, j*sizeof(char));
			n2number = atol(n2string);
			if ((S[i] == '0') && (j > 1)) {
				//printf("\tnumber 2 can not be %s, break\n", n2string);
				memset(n2string, 0, len*sizeof(char));
				break;
			}
			if (n2number > INT_MAX) {
				//printf("\tnumber 2 is out of range:%ld(MAX:%ld)\n", n2number, INT_MAX);
				memset(n2string, 0, len*sizeof(char));
				break;
			}
			//printf("\tnumber2: %ld\n", n2number);
			memset(n2string, 0, len*sizeof(char));
			ret[0] = n1number;
			ret[1] = n2number;
			*returnSize = 2;
			if (splitIntoFibonacci_goon(S, i+j, ret, returnSize)) {
				return ret;
			}
		}
	}
	
	*returnSize = 0;
	return NULL;
}

```