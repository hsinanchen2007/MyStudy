![J~HCW0F\]3QZNAO_1DI_@$6E.png](https://pic.leetcode-cn.com/9eebe1ee85de253a59d502a094e8c390d8baea0651a1d881a1b6d0f6e21b2ab0-J~HCW0F%5D3QZNAO_1DI_@$6E.png)

```
class Solution {
public:
	string countAndSay(int n) {
		if (n == 1)
			return "1";
		//获取第n-1个字符串s作为待描述对象
		string s = countAndSay(n - 1), result = "";
		char curr = s[0];//当前字符
		int count = 0;   //当前字符计数
		for (int i = 0; i < s.size(); i++) {
			//当扫描到的字符发生变化时，填入result中，count归零
			if (curr != s[i]) {
				result += count + '0';
				result += s[i - 1];
				curr = s[i];
				count = 0;
			}
			count++;
		}
		result += count + '0';
		result += s[s.size() - 1];
		return result;
	}
};
```
