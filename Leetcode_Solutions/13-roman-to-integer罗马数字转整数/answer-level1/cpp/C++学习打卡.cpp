### 解题思路
看了大佬们的题解才想起来用switch代替if-else可以加快判断速度

### 代码

```cpp
class Solution {
public:
	int romanToInt(string s) {
		if (s.length() == 0) { return 0; }

		vector<int>nums(s.length());
		for (int i = 0; i < s.length(); i++) {
			switch (s[i]) {
			case 'M': nums[i] = 1000; break;
			case 'D': nums[i] = 500; break;
			case 'C': nums[i] = 100; break;
			case 'L': nums[i] = 50; break;
			case 'X': nums[i] = 10; break;
			case 'V': nums[i] = 5; break;
			case 'I': nums[i] = 1; break;
			default:  nums[i] = 0;
			}
		}
			
		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (i + 1 < nums.size() && nums[i]<nums[i+1]) {
				ans -= nums[i];
			}
			else {
				ans += nums[i];
			}
		}
		return ans;
	}
};
```