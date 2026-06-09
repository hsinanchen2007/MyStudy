假设每个字母代表的字符总数为10，那么就相当于数字分解到每个数字位上应该是多少，无非是现在由每个字母代表10变成了3或者4
```
class Solution {
private:
	struct node
	{
		int idx;
		int cnt;
		int mod;
		char o[4];
		node(int n)
		{
			idx = 0;
			if (n == 2) o[0] = 'a', o[1] = 'b', o[2] = 'c', o[3] = '\0', cnt = 3;
			if (n == 3) o[0] = 'd', o[1] = 'e', o[2] = 'f', o[3] = '\0', cnt = 3;
			if (n == 4) o[0] = 'g', o[1] = 'h', o[2] = 'i', o[3] = '\0', cnt = 3;
			if (n == 5) o[0] = 'j', o[1] = 'k', o[2] = 'l', o[3] = '\0', cnt = 3;
			if (n == 6) o[0] = 'm', o[1] = 'n', o[2] = 'o', o[3] = '\0', cnt = 3;
			if (n == 7) o[0] = 'p', o[1] = 'q', o[2] = 'r', o[3] = 's', cnt = 4;
			if (n == 8) o[0] = 't', o[1] = 'u', o[2] = 'v', o[3] = '\0', cnt = 3;
			if (n == 9) o[0] = 'w', o[1] = 'x', o[2] = 'y', o[3] = 'z', cnt = 4;
			mod = 1;
		}
		char get(int &t)
		{
			char ret = o[t/mod];//取当前t下此数字位的字符
			t %= mod;
			return ret;
		}
	};
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ret;
		int size = digits.size();
        if(!size)
            return ret;
		vector<node*> vt;
		int count = 1;
		for (int i = 0; i < size; ++i)
		{
			vt.emplace_back(new node(digits[i] - '0'));
			count *= vt[i]->cnt;
		}
		int mod = vt[vt.size()-1]->cnt;
		for (int i = vt.size()-2; i >=0;--i)
		{
			vt[i]->mod = mod;//积累进位基数
			mod = vt[i]->mod * vt[i]->cnt;
		}
		int cnt = 0;
		while (cnt<count)
		{
			string t;
			int c = cnt;
			for (int i = 0; i < vt.size(); ++i)
				t += vt[i]->get(c);
			ret.emplace_back(t);
			cnt++;
		}
		return ret;
	}
};
```
