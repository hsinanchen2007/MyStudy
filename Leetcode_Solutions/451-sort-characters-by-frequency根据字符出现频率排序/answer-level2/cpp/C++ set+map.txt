```
string frequencySort(string s) {
    map<char, int> mp;
	string res = "";
	for (int i = 0;i < s.size(); i++)
	{
		mp[s[i]]++;
	}
	set<int> st;
	for (auto it = mp.begin();it != mp.end();it++)
	{
		st.insert(it->second);
	}
	for (auto it = st.rbegin();it != st.rend();it++)
	{
		for (auto it_mp = mp.begin();it_mp != mp.end();it_mp++)
		{
			if (it_mp->second == *it)
			{
				int n = *it;
				while (n)
				{
					res += it_mp->first;
					n--;
				}
			}
		}
	}
	return res;
}
```
