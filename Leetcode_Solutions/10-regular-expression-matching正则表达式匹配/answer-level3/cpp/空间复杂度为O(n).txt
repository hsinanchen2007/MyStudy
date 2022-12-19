观察dp的计算顺序，其实并不需要二维数组，只需要一维的就够了。

```
	bool isMatch(string s, string p) {
		int s_len = s.size();
		int p_len = p.size();
		vector<bool>dp_new(p_len+1);
		bool dp_j_1;
		bool dp_j_2;
		for (int i = s_len; i >= 0; i--)
		{
			for (int j = p_len; j >= 0; j--)
			{
				if(j==p_len)
				{
					if (i == s_len)
						dp_new[j] = true;
					else
					{
						dp_j_1 = dp_new[j];
						dp_new[j] = false;
					}
					continue;
				}
				dp_j_2 = dp_new[j];
				bool first_match = s[i] == p[j] || p[j] == '.';
				if (j + 1 < p_len && p[j + 1] == '*')
					dp_new[j] = dp_new[j + 2] || (first_match&&dp_new[j]);
				else
					dp_new[j] = first_match && dp_j_1;
				dp_j_1 = dp_j_2;
			}
		}
		return dp_new[0];
    }
```
