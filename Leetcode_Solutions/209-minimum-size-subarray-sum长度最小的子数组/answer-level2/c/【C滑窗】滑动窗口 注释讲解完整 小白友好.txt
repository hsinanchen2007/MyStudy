### 解题思路
标准的滑窗，第一次做，注释很完整，希望帮助到新人小白

### 代码

```c
int min(int a, int b) {
	return a>b?b:a;
}

int minSubArrayLen(int s, int* nums, int numsSize){
    if(nums==NULL) return 0;

    // 滑动窗口， l/r分别是滑窗的左右index
    int l = 0, r = 0, sum = 0, minLen = numsSize;  /*注意题意求minLen故初始化为numsSize */
    while(r<numsSize) {
        sum += nums[r];  /* 基础操作就是滑窗右移，不断r++，求部分前缀和 */
        while(sum >= s && r>=l) {  /* 更新minLen的条件 */
        	minLen = min(minLen, (r-l+1));   /* 更新minLen */
			sum -= nums[l];   /* 遍历整串求所有minLen，因此滑窗l++，注意此处可能向右多次while  */
			l++;
		}
		r++;

        if(r-l==numsSize && sum<s) {  /* 最后2个case挂了，发现可能总sum不够，添加特殊判断 */
            // printf("min = %d---sum = %d", r-l+1, sum);
            minLen= 0;
        }

    }

	return minLen;

}
```