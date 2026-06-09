### 解题思路
![微信图片_20200327010308.png](https://pic.leetcode-cn.com/87e632415f850bbdb45f7941543a59b3d52a72c2dabe68cc3389d4a665b0d6fd-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200327010308.png)
本题是跳跃游戏II，是真正的贪心算法。
思路：当要进行下一次跳跃的时候，模拟当前位置下nums[now]范围内可进行的多种跳跃情况，看哪一种情况可以跳的最远，并记录跳到最远的对应起跳点的下标值，作为下一起跳点，并跳到该位置。以此类推，不断循环直至可以跳到最后。

### 代码

```cpp
class Solution {
public:
int jump(vector<int>& nums) {
	int now = 0;//记录现在跳到的位置
	int cnt = 0;
	while (now < nums.size() - 1)
	{
		int max = 0;//记录可以跳到的最远距离
		int max_idx = 0;//记录满足跳到最远距离的那个下标值
		for (int i = nums[now]; i >=1; i--)
		{
			if (now + i == nums.size() - 1)//如果直接可以跳到最后，则退出循环
			{
				max_idx = nums.size() - 1;
				break;
			}
			if (i+now<nums.size()&&now + nums[i+now] + i > max)//！！！小心超过范围
			{
				max = now + nums[i+now] + i;
				max_idx = now + i;
			}
		}
		now = max_idx;
		cnt++;
	}
	return cnt;
}
};
```