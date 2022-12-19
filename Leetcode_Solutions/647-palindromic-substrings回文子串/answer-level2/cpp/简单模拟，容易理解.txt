### 解题思路
遍历每一个字符，进行相邻扩展和以该字符为中心进行两侧扩展，注意边界和扩展条件

### 代码

```cpp
class Solution {
public:
    int countSubstrings(string s) {
// 计数变量
		int count=0;
		for(int i=0;i<s.length();i++)
		{
// 单个字符就是一个回文串，计数加一
			count++;
// 扩展长度记录
			int stretch=1;
// 相邻相等扩展得到的是长度为偶数的回文串
			if(i+1<s.length()&&s[i]==s[i+1])
			{
				count++;
// 向两侧扩展比较外层两个字符是否相等
				while(i+stretch+1<s.length()&&i-stretch>=0&&s[i-stretch]==s[i+stretch+1])
				{
					stretch++;
					count++;
				} 
			}
// 扩展长度归1，进行奇数回文串判断
			stretch=1;
// 以当前字符为中心两侧进行扩展得到长度为奇数的回文串
			while(i+stretch<s.length()&&i-stretch>=0&&s[i-stretch]==s[i+stretch])
			{
				stretch++;
				count++;
			}
		}
		return count;
    }
};
```