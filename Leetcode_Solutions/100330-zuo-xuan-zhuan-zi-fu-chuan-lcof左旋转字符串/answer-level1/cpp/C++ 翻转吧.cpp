### 解题思路
3次翻转
先从n为分界线的位置，对0~n-1翻转一次，对n-1~length-1反转一次
再翻转字符串s

### 代码

```cpp
class Solution {
public:
	string reverseLeftWords(string s, int n) {
		//特判
		//字符串为空或是n<0返回空
		if (s.size() == 0|| n<0) return "";
		//先对从n为分界线的位置翻转
		Reverse(s, 0, n-1);
		Reverse(s, n, s.size() - 1);
		//再翻转字符串s
		Reverse(s, 0, s.size() - 1);
		return s;
	}
	void Reverse(string& s, int pBegin, int pEnd)
	{
		while (pBegin<pEnd)
		{
			char temp = s[pBegin];
			s[pBegin] = s[pEnd];
			s[pEnd] = temp;
            pBegin++,pEnd--;
		}
	}
};
```