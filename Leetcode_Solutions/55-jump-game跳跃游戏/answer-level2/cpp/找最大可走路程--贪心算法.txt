### 一种简单的思想
没看题解之前想到从第一个元素开始，得到能走的最大路程，大于等于数组长度减1就可以return true了，不行的话往后遍历每个元素能走的最大路程，更新当前能走最大路程；若是到了最大路程处还没到数组尾部，那就循环结束return false。提交结束后看到这种思路和官方的贪心算法思想一致，不过官方是从后面往前走的。
这里注意两点：一是数组只有一个元素的时候都能走完返回true，可以不用走循环提升一点速度，当然不判断程序也是能通过的；二是注意持续更新能走的最大路程j，for循环的判断语句是动态跟随j的。

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
	int len = nums.size();
	if (len == 1)//只有一个元素时无论是多少都已经到达数组尾部了
		return true;
	int i, j = nums[0];
	for (i = 0; i <= j; i++)
	{
		if (nums[i] + i > j)
			j = nums[i] + i;
		if (j >= len-1)
			return true;
	}
	return false;
    }
};
```