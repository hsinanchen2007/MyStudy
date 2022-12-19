找到所有可能的解的过程中，删除重复的。
后来才发现，map里面有是插入不进去的，基础知识不牢。蠢。
还有很多待改进的地方啊。

```
    vector<string> generateParenthesis(int n) {
 	map<string,int> w;
	vector<string> result;
	string a = "";
	if (n == 0)
		return result;
	if (n == 1){
		string a = "()";
		result.push_back(a);
		return result;
	}
	for (int j = 1; j < n / 2 + 1; j++){
		vector<string> temp1 = generateParenthesis(j);
		vector<string> temp2 = generateParenthesis(n - j);		
		for (int i = 0; i < temp1.size();i++)
			for (int k = 0; k < temp2.size(); k++){
				if (w.end() == w.find(temp1[i] + temp2[k])){
					w.insert(pair<string, int>(temp1[i] + temp2[k], 1));
					result.push_back(temp1[i] + temp2[k]);	
				}
				if (w.end() == w.find(temp2[k] + temp1[i])){
					w.insert(pair<string, int>(temp2[k] + temp1[i], 1));
					result.push_back(temp2[k] + temp1[i]);
				}
		}
		if (j == 1){
			for (int i = 0; i < temp2.size(); i++)
				result.push_back("(" + temp2[i] + ")");
		}
	}	
	return result;
    }
```
