![1.png](https://pic.leetcode-cn.com/ac963a986ee3fc4055a4cf0b160d88f7925b9acfb78c67a34a289f2a1bcf3b3e-1.png)

### 解题思路
参照多数元素的思路，写了这个。运行一下，几乎双百。
但是，
回头一想，好象有BUG。
int a[6] = { 1, 2, 3, 4, 5, 5 };
printf("%d\n", majorityElement(a, 6));
这个运行下来输出是5，按题意应该是-1。
算是BUG吧

### 代码

```c
int majorityElement(int* nums, int numsSize){
	int cnt = 0, t = *nums;
	for (int i = 0; i < numsSize; i++){
		if (nums[i] == t)
			cnt++;
		else
			cnt--;		
		if (cnt <= 0){
			if (i < numsSize - 1)
				t = nums[i + 1];
			else
				return -1;
		}
	}
	return t;
}
```