```
vector<string> letterCombinations(string digits) {
	vector<string> res;
	queue<string> que;
	string str[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	for(int i = 0; i < digits.size(); i++){
		int index = digits[i] - '0';
		int len = str[index - 2].size();
		if(que.empty()){
			for(int i = 0; i < len; i++){
				string temp = "";
				temp += str[index - 2][i];
				que.push(temp);
			}
		}else{
			int que_len = que.size();
			while(que_len--){
				string cur_str = que.front();
				que.pop();
				for(int i = 0; i < len; i++){
					string temp = cur_str + str[index - 2][i];
					que.push(temp);
				}
			}
		}
	}
	while(!que.empty()){
		res.push_back(que.front());
		que.pop();
	}
	return res;
}
```
