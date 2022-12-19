vector<string> strs(n);
	strs[0] = "1";
	if (n == 1)
		return "1";
	else if (n == 2)
		return "11";
	strs[1] = "11";
	for (int i = 2; i < n; i++)
	{
		auto iter = strs[i - 1].begin();
		int count = 0;
		int nownum = *iter;
		while (iter != strs[i - 1].end())
		{
			if (iter == strs[i - 1].begin() || *iter == (*(iter - 1)))
				count++;
			else
			{
				strs[i].push_back(count + '0');
				strs[i].push_back(*(iter-1));
				count = 1;
			}
			iter++;
		}
		strs[i].push_back(count + '0');
		strs[i].push_back(*(strs[i-1].end() - 1));
	}
	return strs[n-1];