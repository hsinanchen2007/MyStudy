### 解题思路
![QQ图片20200316113119.png](https://pic.leetcode-cn.com/d9c8b57e7f15f6a47824f655bb7541ad0f0a13a20c6a5bbe481e4a2704858e50-QQ%E5%9B%BE%E7%89%8720200316113119.png)

### 代码

```cpp
class Solution {
public:
string compressString(string S) {
		if (S.size() < 1) return S;
		size_t len = S.size();
		string str;
		str += S[0];
		for (int i = 1; i < len; ++i)
		{
			int num_cout = 1;
			while (S[i - 1] == S[i])
			{
				num_cout++;
			    ++i;
			}
			str += to_string(num_cout);
            str += S[i];
		}
		if (len == 1 || S[len - 1] != S[len - 2]) str += "1";//若只有一个char或最后单独一个char
		return str.size() > len ? S : str;//不要忘记\0也要占位
	}
};
```