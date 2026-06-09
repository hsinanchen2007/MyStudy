![1.png](https://pic.leetcode-cn.com/edc7fd87026107213ee26f29a198307d87fa4aba20db23a7e8a34d0e6903e857-1.png)

### 解题思路
此处撰写解题思路

### 代码

```c
bool canJump(int* nums, int numsSize){
    if(numsSize<2)
        return 1;
	int i, j = 0, flag = 1;
	for (int i = numsSize - 1; i >= 0; i--){
		if (!nums[i] && flag){
			flag = 0;
			if (i == numsSize - 1)
				j--;
		}
		else if (!flag){
			if (nums[i] - 1 > j){
				flag = 1;
				j = 0;
			}
			else
				j++;
		}
	}
	return flag;
}
```