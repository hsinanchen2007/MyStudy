### 解题思路
计算字母的数量，为偶直接计入sum；为奇时，若大于1，则计入sum-1，同时计算这样单独的字母的数量x；
小白看代码能看懂吧。我还没学会其他高大上的方法，这么简单都要让我怀疑人生！！！

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
	int sum = 0, x = 0;
	for (int i = 0; i<s.length(); i++)
	{
		int f;
		if ((s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= 'A'&&s[i] <= 'Z')){
			f = 1;
			for (int j = i + 1; j<s.length(); j++)
			{
				if (s[i] == s[j]){ f++; s[j] = '0'; }
			}
			if (f % 2 == 0)  sum += f;
			else if (f == 1) x++;
			else { sum += f - 1; x++; }

		}
				
	}
	if (x!=0) sum++; 
	return sum;
}
};
```