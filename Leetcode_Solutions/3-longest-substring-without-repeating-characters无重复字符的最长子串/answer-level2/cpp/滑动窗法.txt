### 解题思路
滑动窗法
执行用时 :44 ms， 在所有 C++ 提交中击败了28.48%的用户
内存消耗 :6.9 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin = 0, end = 0, len = s.length();
		int result = 0;
		bool isExist = 0;
		int record = 0;
		for (int i = 0; i < len; i++)
		{
			for (int j = begin; j < end; j++)
			{
				if (s.at(i) == s.at(j))
				{
					record = j;
					isExist = 1;
				}
			}
			if (isExist)
			{
				begin = record+1;
				end++;
			}
			else
			{
				end++;
			}
			int temp = end - begin;
			result = result > temp ? result : temp;
		}
		return result;}
};
```