### 解题思路
采用力扣上给出的方法五 滑动窗口

### 注意点
如果采用数组的方式存储每个字母出现的频率会出现错误，这道题目这里有坑，我刚开始采用的是数组存，本地可以过，但是交上去不能过
代码如下，本机没问题，交上去就是错，经过PlayGround我发现，本应输入的字符串为s1="ab",s2="eidbaooo"，变成了图中所示样子
![1.jpg](https://pic.leetcode-cn.com/96c98c8deb2c7b62bc84840afac625a16cc456fea5ece5e0528c40cf8c38cdd4-1.jpg)
```cpp
class solution {
public:
	bool checkinclusion(string s1, string s2) {
		int s1map[26];
		int s2map[26];
		if (s1.length() > s2.length()) return false;//s1的长度大于s2，说明s2不会包含s1
		for (int i=0;i<s1.length();i++)
		{
			s1map[s1[i] - 'a']++;//获取第i给元素出现的频率
			s2map[s2[i] - 'a']++;
		}
		for (int i=0;i<s2.length()-s1.length();i++)
		{
			if (matches(s1map,s2map))
			{
				return true;//如果出现频率一样，说明含有
			}
			s2map[s2[i + s1.length()] - 'a']++;//将新的后续字符添加到所需考虑的新窗口中
			s2map[s2[i] - 'a']--;//去除窗口的第i个字符
		}
		return matches(s1map,s2map);
	}
	bool matches(int s1map[], int s2map[])//判断窗口内的元素出现频率是否一样
	{
		for (int i=0;i<26;i++)
		{
			if (s1map[i]!=s2map[i])
			{
				return false;
			}
		}
		return true;
	}
};
```

### 代码
该代码为通过代码
```cpp
class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		vector<int> s1map(26);
		vector<int> s2map(26);
		if (s1.length() > s2.length()) return false;//s1的长度大于s2，说明s2不会包含s1
		for (int i = 0; i < s1.length(); i++)
		{
			s1map[s1[i] - 'a']++;//获取第i给元素出现的频率
			s2map[s2[i] - 'a']++;
		}
		for (int i = 0; i < s2.length() - s1.length(); i++)
		{
			if (s1map==s2map)
			{
				return true;//如果出现频率一样，说明含有
			}
			s2map[s2[i + s1.length()] - 'a']++;//将新的后续字符添加到所需考虑的新窗口中
			s2map[s2[i] - 'a']--;//去除窗口的第i个字符
		}
		return s1map == s2map;
	}
};
```
