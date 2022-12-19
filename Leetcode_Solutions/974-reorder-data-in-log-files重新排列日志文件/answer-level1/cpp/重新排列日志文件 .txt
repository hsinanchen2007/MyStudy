字数分离，字排序（自做个比较compare），字后加数
```
class Solution {
public:
    static bool comp(string a, string b) {//比较函数
		int i = 0, j = 0;
		while(a[i] != ' ' && i < a.size()) i++;
		while(b[j] != ' ' && j < b.size()) j++;
		string atemp = a.substr(i);
		string btemp = b.substr(j);
		if(atemp == btemp) return a < b;
		return atemp < btemp;
	}
    vector<string> reorderLogFiles(vector<string>& logs) {
		vector<string> alpha;
		vector<string> digit;
        for (int i = 0; i < logs.size(); i++) {//字数分离
			int len = logs[i].size();
			if( isalpha(logs[i][len - 1] ) ) alpha.push_back(logs[i]);
			if( isdigit(logs[i][len - 1] ) ) digit.push_back(logs[i]);
        }
        sort(alpha.begin(), alpha.end(), comp);
		for(int i = 0; i < digit.size(); i++) alpha.push_back(digit[i]);//字后加数
		return alpha;
    }
};
```
