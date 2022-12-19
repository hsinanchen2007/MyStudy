从右向左扫描，能跳到最后一点就是跳跃力满足要求的嘛！
倒数第二跳跃力至少要有1，不满足那么他前面的跳跃力要加1，如果满足那么前面的跳跃力也只要1；
用flag存储至少需要的跳跃力，一直扫描到nums[0],如果他的跳跃力不满足最低要求那肯定就返回false;否则就返回true了嘛！

```
class Solution{
public:
	bool canJump(vector<int>& nums)
	{
		if (nums.size() == 1)
			return true;
		int flag = 1;   //要想跳到下一坐标至少大于等于1
		for (int i = nums.size() - 2; i >= 0; i--)
		{
			if (nums[i] < flag)     //从右向左扫描，当前不能跳到下一坐标，则前面想要到下一坐标所需要的跳跃力要加1；
				flag++;
			else
				flag = 1;           //当前能跳到下一坐标，则前面想要到跳到这只需要1跳跃力；
		}
		return nums[0] >= flag;     //第一跳能满足最低的跳跃力要求则能到最终点；
	}
};
```
