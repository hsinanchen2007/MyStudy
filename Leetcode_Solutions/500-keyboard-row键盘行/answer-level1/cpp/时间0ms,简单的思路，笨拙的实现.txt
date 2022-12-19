```
vector<string> findWords(vector<string>& words) {
     unordered_set<char> first{ 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P' };
	 unordered_set<char> second{ 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L' };
	 unordered_set<char> third{'z','x','c','v','b','n','m','Z','X','C','V','B','N','M'};
	 int len = words.size();
	 vector<string> result;
	 if (len == 0) return result;
	 int count1 = 0;
	 int count2 = 0;
	 int count3 = 0;
	 for (int i = 0; i < len; i++)
	 {
		 for (int j = 0; j < words[i].size(); j++)
		 {
			 if (first.find(words[i][j]) != first.end()) count1++;
			 if (second.find(words[i][j]) != second.end()) count2++;
			 if (third.find(words[i][j]) != third.end()) count3++;

		 }
		 if (count1 == words[i].size() || count2 == words[i].size() || count3 == words[i].size())
		 {
			 
			 result.push_back(words[i]);
		 }
         count1 = 0;
		 count2 = 0;
		 count3 = 0;
	 }

	 return result;   
}
```
