```
string freqAlphabets(string s) {
	vector<vector<char>>dic(2, vector<char>(10, '0'));
	for (int i = 0; i<10; i++){
		dic[0][i] = 'j' + i;
	}
	for (int i = 0; i<7; i++){
		dic[1][i] = 'j' + i + 10;
	}

	string res = "";
	int len = s.length();
	for (int i = 0; i<len; i++){
		if (i+2 < len && s[i + 2] == '#'){
			res = res + (dic[s[i] - '1'][s[i + 1] - '0']);
			i = i + 2;
		}
		else{
			res = res + (char)(s[i] + 48);
		}
	}
	return res;
}
```
