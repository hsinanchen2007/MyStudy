```
代码块bool flag = true;
	for (auto i : wordList)
	{
		if (i == endWord)flag = false;
	}
	if (flag == true)return 0;
	unordered_set<string > wordmap(wordList.begin(),wordList.end());
	unordered_set<string > s1;
	unordered_set<string > s2;
	queue<string > q1;
	queue<string > q2;
	s1.insert(beginWord);
	s2.insert(endWord);
	q1.push(beginWord);
	q2.push(endWord);
	int ans1 = 0;
	int ans2 = 0;
	while (!q1.empty()||!q2.empty())
	{
		if ((q1.size() <= q2.size()) && !q1.empty())
		{
			ans1++;
			int len = q1.size();
			for (int i = 0; i < len; i++)//层次遍历
			{
				string temp = q1.front();
				q1.pop();
				for (int i = 0; i < temp.size(); i++)//一次改变每个位子的元素
				{
					string help = temp;
					for (char ch = 'a'; ch < 'z'; ch++)
					{
						help[i] = ch;
						if (s2.find(help) != s2.end())return ans1 + ans2+1;
						if (wordmap.find(help) == wordmap.end() || s1.find(help) != s1.end())continue;
						s1.insert(help);
						q1.push(help);
					}
				}
			}
		}
		else
		{
			ans2++;
			int len = q2.size();
			for (int i = 0; i < len; i++)//层次遍历
			{
				string temp = q2.front();
				q2.pop();
				for (int i = 0; i < temp.size(); i++)//一次改变每个位子的元素
				{
					string help = temp;
					for (char ch = 'a'; ch < 'z'; ch++)
					{
						help[i] = ch;
						if (s1.find(help) != s1.end())return ans1 + ans2+1;
						if (wordmap.find(help) == wordmap.end() || s2.find(help) != s2.end())continue;
						s2.insert(help);
						q2.push(help);
					}
				}
			}
		}
	}
	return 0;
```
