#define MIN(a, b) ((a) > (b)) ? (b) : (a)

int TwoLCP(char *a, char *b, int min)
{
	int left = 1;
	int right = min;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (strncmp(a, b, mid) == 0) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return (left + right) / 2;
}

int BSlcp(char **strs, int left, int right, int min)
{
	if (left == right) {
		return min;
	}
	if (left + 1 == right) {
		return TwoLCP(strs[left], strs[right], min);
	}
	int mid = (left + right) / 2;
	min = BSlcp(strs, left, mid, min);
	if (min == 0) {
		return 0;
	}
	min = BSlcp(strs, mid + 1, right, min);
	if (min == 0) {
		return 0;
	}
	return TwoLCP(strs[left], strs[right], min);
}

char * longestCommonPrefix(char ** strs, int strsSize){
	if (strs == NULL || strsSize <= 0) {
		return "";
	}
	if (strsSize == 1) {
		return strs[0];
	}
	int min = (int)strlen(strs[0]);
	for (int i = 1; i < strsSize; i++) {
		min = MIN(min, (int)strlen(strs[i]));
	}
	if (strsSize == 2) {
        min = TwoLCP(strs[0], strs[1], min);
		strs[0][min] = 0;
		return strs[0];
	}
	int mid = strsSize / 2;
	min = BSlcp(strs, 0, mid, min);
	if (min == 0) {
		return "";
	}
	min = BSlcp(strs, mid + 1, strsSize - 1, min);
	if (min == 0) {
		return "";
	}
	min = TwoLCP(strs[0], strs[strsSize - 1], min);
	strs[0][min] = 0;
	return strs[0];

}