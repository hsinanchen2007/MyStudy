对出现下降的地方进行计数。
如果出现两次下降则必定false。
如果出现下降的两个数nums[i-1],nums[i]能去除其中一个使数列仍然非递减则说明true，那么也就是说去除其中任意一个都不能使数列非递减则为false。
```
class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int count = 0;
		for (int i = 1; i < nums.size(); i++){
			if (count == 0 && nums[i] < nums[i - 1]){
				count++;
				if (i < nums.size() - 1 && nums[i + 1] < nums[i - 1] && i > 1 && nums[i] < nums[i - 2])
					return false;
			}
			else if (count == 1 && nums[i] < nums[i - 1]){
				return false;
			}
		}
		return true;
	}
};
```

