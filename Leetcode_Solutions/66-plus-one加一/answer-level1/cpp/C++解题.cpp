### 解题思路
参考自[@yhhzw](/u/yhhzw/)

### 代码

```cpp
class Solution {
public:
	//除9,99,999之外的数字+1即可
	//数字9，99，999等类型数字，需要额外手动增大数组并+1
	vector<int> plusOne(vector<int>& digits) {
		for (int i=digits.size()-1;i>=0;i--)
		{
			digits[i]++;
			digits[i] = digits[i] % 10;
			if (digits[i] != 0) return digits;
		}
		//对于特殊情况，出现9，99等，要手动加1
		vector<int> ans(digits.size() + 1);
		ans[0] = 1;
		return ans;
	}
};
```