1.把字母日志和数字日志分开，存储字母日志的时候把标识符放后面，利用sort把字母日志排序，成功得到需要顺序的字母日志和数字日志。
2.把字母日志重排列把标识符放回原位。

```
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
	vector<string>alphas;
	vector<string>digits;
	vector<string>res;
	string a;
	for (auto log : logs)
	{
		for (int i = 0; i < log.size(); i++)
		{
			if (log[i] == ' '&&isalpha(log[i + 1]))
			{
				a = log.substr(i + 1) + '+' + log.substr(0, i);
				alphas.push_back(a);
				break;
			}
			if (log[i] == ' '&&isdigit(log[i + 1]))
			{
				digits.push_back(log);
				break;
			}
		}
	}
	sort(alphas.begin(), alphas.end());
	for (auto log : alphas)
	{
		for (int i = 0; i < log.size(); i++)
		{
			if (log[i] == '+')
			{
				a = log.substr(i + 1) + ' ' + log.substr(0, i);
				res.push_back(a);
				break;
			}

		}
	}
	for (auto log : digits)
	{
		res.push_back(log);
	}

	return res;
    }
};
```
