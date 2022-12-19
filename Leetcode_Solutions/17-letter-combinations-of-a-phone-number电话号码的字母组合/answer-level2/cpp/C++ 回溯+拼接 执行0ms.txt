![image.png](https://pic.leetcode-cn.com/782072d0eff13cbeca11cb1a5cf24a45fa84a9e2984badca56466ecb01024d53-image.png)
执行用时0ms, 内存击败97.6%
### 解题思路
整体思路采用递归, 从根节点往回拼接。
字符查找采用计算的方案, 内存消耗小。

### 代码
```cpp
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty())
			return{};
		vector<string> ret = letterCombinations(digits.substr(1)); //递归到最后一位
		vector<string> ans;
		for (int pos = 0; pos < 3 + (digits[0] - '0' == 9 || digits[0] - '0' == 7); pos++){
			string this_str(1, (digits[0] - '2') * 3 + pos + (digits[0] - '0' > 7) + 'a'); //字符查找
			if (!ret.empty()){
				for (auto str : ret)
					ans.push_back(this_str + str);
			} else{
				ans.push_back(this_str);
			}
		}
		return ans;
	}
};
```