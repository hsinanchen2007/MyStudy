```
    bool wordBreak_dp(string s,int index, vector<bool>& canBreak,vector<string>& wordDirct, unordered_map<char, vector<string>>& m,unordered_set<string>& n)
{
	int size = s.size();
	if (size < 0)
		return false;
	if (size == 0)
		return true;
	if (size == 1)
	{
		if (n.count(s) > 0)
		{
			canBreak[index] = true;
			return true;
		}
		else
		{
			canBreak[index] = false;
			return false;
		}
	}
	char c = s[0];
	for (int i = 0; i < m[c].size(); i++)
	{
		int word_size = m[c][i].size();
		if (!canBreak[index] || s.size() < word_size ) //如果该位置不可被拆分，或者s小于目标字符串
			continue;
		string s_word = s.substr(0, word_size);						//前word_size个字符组成的字符串
		string s_left = s.substr(word_size, s.size() - word_size);	//剩下的字符串
		//如果s_word在wordDirct中，且剩余的字符串可以被拆分，则代表整个字符串可以被拆分。
		if (n.count(s_word) > 0 && wordBreak_dp(s_left, word_size + index, canBreak, wordDirct, m, n)) 
			return true;
	}
	canBreak[index] = false; //如果不能被拆分就标记为false
	return false;
}

    bool wordBreak(string s, vector<string>& wordDict) 
{
        if (wordDict.size() == 0)
            return false;
        if (s.size() == 0)
            return false;
        unordered_map<char, vector<string>> m;	//m代表 字符c（char类型）到以c开头字符串的映射。
        unordered_set<string> set;				//n中存储wordDict中的字符串。
        for (int i = 0; i < wordDict.size(); i++)
        {
            string s = wordDict[i];
            char c = s[0];
            m[c].push_back(s);
            set.insert(s);
        }
        vector<bool> canBreak;					//canBreak作为备忘录，记录该位置是否能对单词拆分。
        canBreak.assign(s.size(), true);
        return wordBreak_dp(s, 0, canBreak,wordDict, m,set);
}
```