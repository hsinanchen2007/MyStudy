遍历更新最大长度即可

代码：
```
class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int len = nums.size();
		if (len) {
			int ans = 0;
			int i = 0;
			int temp = 1;
			for (int i = 0; i < len - 1; i++) {
				if (nums[i + 1] > nums[i])
					temp++;
				else {
					ans = ans > temp ? ans : temp;
					temp = 1;
				}
			}
			ans = ans > temp ? ans : temp;
			return ans;
		}
		return 0;
	}
};
```
