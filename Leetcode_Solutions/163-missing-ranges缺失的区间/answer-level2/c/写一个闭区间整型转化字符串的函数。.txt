### 解题思路
1、对比lower和nums[0]是否需要闭区间
2、对比nums[i]和nums[i-1]是否需要闭区间；注意有个用例考了int边界，两数相减需要转化为long long相减。
3、对比nums[i]和upper是否需要闭区间

写一个闭区间函数，用sprintf把整数读出到字符串

### 代码

```c
#define MAXLEN 1000
#define NUMSIZE 25
char * getResult(int a, int b) {
    char * ret = (char*) malloc(sizeof(char)*NUMSIZE);
	if (b == a) {
		sprintf(ret, "%d", a);
		return ret;
	}
	sprintf(ret, "%d->%d",a,b);
	return ret;
}

char ** findMissingRanges(int* nums, int numsSize, int lower, int upper, int* returnSize) {
	char ** ret = (char **)malloc(sizeof(char*) * MAXLEN);
	int i, count;
	count = 0;
	if (numsSize == 0) {
		ret[count++] = getResult(lower, upper);
		*returnSize = count;
		return ret;
	}
	if (lower < nums[0]) {
		ret[count++] = getResult(lower, nums[0] - 1);//[lower, nums[0] -1]
	}
	for (i = 1; i < numsSize; i++) {
        long long flag = (long long)nums[i] - (long long)nums[i - 1];
		if (flag > 1) {
			ret[count++] = getResult(nums[i - 1] + 1,nums[i] - 1);
		}
	}
	if (nums[i - 1] < upper) {
		ret[count++] = getResult(nums[i - 1] + 1, upper); //[nums[end] + 1, upper]
	}
	*returnSize = count;
	return ret;
}

```