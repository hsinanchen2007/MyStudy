1.数组的数据小于等于1的时候，说明跳跃游戏肯定成功
2.倒数第二位置是1的时候，说明只要能跳到倒数第二的位置，就必定能跳到最后的位置。
```
class Solution {
public:
bool canJump(vector<int>& nums) {
	int n = nums.size();
	if (n <= 1) return true;
	for (int i = n - 2; i >= 0;i--)
	{
		if (nums[i] >= n - i - 1)
			nums.pop_back();
		else
			continue;
		return(canJump(nums));
	}
	return false;
}
};
```
