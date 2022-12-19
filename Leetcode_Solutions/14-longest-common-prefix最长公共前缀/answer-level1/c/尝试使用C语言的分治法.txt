#define MIN(a, b) ((a) > (b)) ? (b) : (a)

int twoLCP(const char *a, const char *b, int min)
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

int dacLCP(char **strs, int left, int right, int min)
{
	if (left + 1 == right) { // 两种的情况已经处理
		return MIN(twoLCP(strs[left], strs[right], min), min);
	} else if (left == right){ // 一种的情况已经处理
		return MIN((int)strlen(strs[left]), min);
	}
	int mid = (left + right) / 2; // 三种及三种以上的做法，继续采用分而治之的做法
	int minL = dacLCP(strs, left, mid, min); // 处理左侧
	min = MIN(min, minL);
	if (min == 0) { // 处理没有任何相似的极端情况
		return 0;
	}
	int minR = dacLCP(strs, mid + 1, right, min); // 处理右侧
	min = MIN(min, minR);
	return MIN(min, twoLCP(strs[left], strs[right], min)); // 返回最小值
}

char * longestCommonPrefix(char ** strs, int strsSize){
	if (strs == NULL || strsSize <= 0) {
		return "";
	}
	if (strsSize == 1) { // 处理只有一个的输入
		return strs[0];
	}
	int min = (int)strlen(strs[0]);
	for (int i = 1; i < strsSize; i++) {
		min = MIN(min, (int)strlen(strs[i])); // 获取最短字符串的长度
	}
	if (min == 0) { // 处理带有空串的情形
		return "";
	}
	int mid = strsSize / 2;
	int minL = dacLCP(strs, 0, mid, min); // 即使只有两个字符串，0 到 1 都分到了左侧一半
	min = MIN(min, minL);
	if (min == 0) { // 处理极端情况
		return "";
	}
	if (mid + 1 <= strsSize - 1) { // 右侧一半不一定有，当有的时候，计算右边一半
		int minR = dacLCP(strs, mid + 1, strsSize - 1, min);
		min = MIN(min, minR);
		if (min == 0) {
			return "";
		}
		min = MIN(min, twoLCP(strs[0], strs[strsSize - 1], min)); // 合并左右一半处理的结果
	}
	if (min == 0) {
		return "";
	}
	char *ret = (char *)calloc(min + 1, sizeof(char));
	if (ret == NULL) {
		exit(-1);
	}
	strncpy(ret, strs[0], min);
	return ret;
}