### 解题思路
![图片.png](https://pic.leetcode-cn.com/1378f9fa8aa8a2907ae2bd9ffe33ee2687cb121d7ab61f67d4f58143c73afbb5-%E5%9B%BE%E7%89%87.png)

从num[0]开始依次遍历，用temp记录当前可以抵达的最远位置。
如果最远位置小于等于当前位置，返回false。
ps:temp<numsSize-1这个判定条件是因为测试案例里有[0]的情况，特殊考虑。

### 代码

```c
bool canJump(int* nums, int numsSize) {

	int temp = 0;

	for (int i = 0; i < numsSize; i++)
	{
		if (temp < (i + nums[i]))
			temp = i + nums[i];
		if (temp <= i&&temp<numsSize-1)
			return false;
	}
	return true;

}

```