解题思路：
1.s[0]直接存入vector(后面用v表示)，后面的元素先判断是否存在v中，存在就continue跳过。
2.判断s[i]是否大于v.back()，大于直接存入v。
3.if s[i] < v.back(),判断v.back()是否存在于s的i到结尾。
如果存在，弹出，跳到2.不存在，s[i]加入v。

另：希望有大佬给我讲解为什么大家普遍使用stack，而不是vector。因为不会判断s[i]是否在stack中就弃用stack了

```
class Solution {
public:
	string removeDuplicateLetters(string s) {
		vector<char> v;
		v.push_back(s[0]);
		for (int i = 1; i < s.size(); i++)
		{
			if (find(v.begin(), v.end(), s[i]) != v.end())
				continue;
			if (s[i] > v.back())
				v.push_back(s[i]);
			else if (s[i] < v.back())
			{
				while (!v.empty() && s[i] < v.back())
				{
					if (s.find(v.back(), i) != string::npos)
						v.pop_back();
					else
						break;
				}
				v.push_back(s[i]);
			}
		}
		string res;
		while (!v.empty())
		{
			res += v.back();
			v.pop_back();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
```

