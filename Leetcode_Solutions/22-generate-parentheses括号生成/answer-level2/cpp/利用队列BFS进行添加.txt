n=0时，队列push空字符串进去
n>0时，取出队列中字符串，当遇到‘（’以及字符串末添加“（）”，利用set去除重复结果


```
class Solution {
public:
    vector<string> generateParenthesis(int n) {
	vector<string> ans;
	string m = "()";
	queue<string>q;
	q.push("");
	while (n > 0)
	{
		int qsize = q.size();
		set<string> d;
		for (int i = 0; i < qsize; i++)
		{
			string p = q.front();

			q.pop();
			for (int i = 0; i < p.size(); i++)
			{
				if (p[i] == '(')
				{
					string ss = "";
					ss += p.substr(0, i+1) + m + p.substr(i + 1);
					d.insert(ss);
				}
					
			}
			string ss = "";
			ss += p + m;
			d.insert(ss);
		}
		for (auto t : d)
		{
			q.push(t);
		}
		d.clear();
		n--;
	}
	while (!q.empty())
	{
		ans.push_back(q.front());
		q.pop();
	}
	return ans;
    }
};
```
