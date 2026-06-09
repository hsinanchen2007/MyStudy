#define MIN(a, b) ((a) > (b)) ? (b) : (a)
int TwoLCP(const char *a, const char *b, int min)
{
	int left = 1;
	int right = min;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (0 == strncmp(a, b, mid)) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return (left + right) / 2;
}

char * longestCommonPrefix(char ** strs, int strsSize){
	if (strs == NULL || strsSize <= 0) {
		char *ret = (char *)calloc(1, sizeof(char));
		if (ret == NULL) {
			exit(-1);
		}
		return ret;
	}
	int min = (int)strlen(strs[0]);
	if (strsSize == 1) {
		char *ret = (char *)calloc(min + 1, sizeof(char));
		if (ret == NULL) {
			exit(-1);
		}
		strcpy(ret, strs[0]);
		return ret;
	}
	for (int i = 1; i < strsSize; i++) {
		min = MIN(min, (int)strlen(strs[i]));
	}
	for (int i = 1; i < strsSize; i++) {
		min = MIN(min, TwoLCP(strs[0], strs[i], min));
		if (min == 0) {
			break;
		}
	}
	char *ret = (char *)calloc(min + 1, sizeof(char));
	if (ret == NULL) {
		exit(-1);
	}
	if (min == 0) {
		return ret;
	}
	strncpy(ret, strs[0], min);
	return ret;
}