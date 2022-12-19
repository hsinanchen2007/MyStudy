### 代码

```c
int missingElement(int* nums, int numsSize, int k){
	int res = 0;
	int len = 0;
	int oldLen = 0;
	
	for (int i = 1; i < numsSize; i++) {
		oldLen = len;
		len = nums[i] - nums[i-1] - 1 + oldLen;
        if (k <= len) {
			res = nums[i-1] + (k - oldLen);
            return res;
		}
	}

    res = nums[numsSize-1] + (k - len);
	return res;
}
```