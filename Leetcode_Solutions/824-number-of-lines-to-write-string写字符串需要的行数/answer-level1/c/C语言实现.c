
int* numberOfLines(int* widths, int widthsSize, char * S, int* returnSize){
	int *ret = (int *)malloc(sizeof(int) * 2);
	int sum = 0;
	int row = 1;
	for (int i = 0; S[i]; i++) {
		sum += widths[S[i] - 'a'];
		if (sum > 100) {
			row++;
			sum = widths[S[i] - 'a']; /* 换行后*/
		}
	}
	ret[0] = row;
	ret[1] = sum; 
	*returnSize = 2;
	return ret;
}