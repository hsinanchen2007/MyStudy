![image.png](https://pic.leetcode-cn.com/5806463f308a32967bcf2f0a3398016c9036b86827d6ddb283b83c13660339a1-image.png)

```
class Solution
{
public :
	bool isValid(string S)
	{
		int pos = -1;
		char stk[20000];
		for (int i = 0; i < S.length(); ++i)
		{
			stk[++pos] = S[i];
			if (pos >= 2 && stk[pos] == 'c' && stk[pos - 1] == 'b' && stk[pos - 2] == 'a')
				pos = pos - 3;
		}
		return pos == -1;
	}
};
```
类似于括号匹配算法，遍历每个字符并不断入栈，遇到"abc"就出栈3个元素
如果最后栈为空则说明合法，否则不合法
