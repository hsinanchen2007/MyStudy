![1.png](https://pic.leetcode-cn.com/b3a97149b180e15aaf81f4c22f591d0b39fc45c19567fb78cd765b313ac867d6-1.png)

### 解题思路
此处撰写解题思路

### 代码

```c
int jump(int* nums, int numsSize){
	if (numsSize < 2)
		return 0;
	int step = 0;
    while (1){
        step++;
		if (*nums < numsSize - 1){
			int i, t = *nums, max = nums[t];
			for (i = 1; i <= *nums; i++)
				if (nums[i] + i >= max + t){
				max = nums[i];
				t = i;
				}
			nums = &nums[t];
			numsSize -= t;			
		}
		else
			break;		
	}
	return step;
}
```