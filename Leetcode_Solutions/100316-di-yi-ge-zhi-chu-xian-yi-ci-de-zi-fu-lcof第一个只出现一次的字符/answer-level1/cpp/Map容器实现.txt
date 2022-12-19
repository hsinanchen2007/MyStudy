利用Map不允许有重复key的特性。


` char firstUniqChar(string s) {
	 map<char, int> temp;
	 for (int i = 0; i < s.length(); i++)
	 {
		 map<char, int>::iterator pos = temp.find(s[i]);
		 if (pos == temp.end())
		 {
			 temp.insert(pair<char, int>(s[i], 1));
		 }
		 else
		 {
			 temp.insert(pair<char, int>(s[i], ++(*pos).second));
		 }
	 }
	 for (int i = 0; i < s.length(); i++)
	 {
		 if (temp[s[i]] == 1)
		 {
			 return s[i];
		 }
	 }
	 return ' ';
 }`