与127类似，这里没有用双向BFS，因为代码太长不优雅，感兴趣的可以自己改写。
使用标准的BFS遍历，其中注意，将已经访问过的单词加入待删除集合dels中，不要立即删除。因为在同一层遍历时，有可能有多种路径，即多个解。这是与127的区别之一。
使用trace记住当前单词的前驱，注意前驱有多个（即有可能多个解），然后使用dfs恢复路径。
```
// Time 156ms, Space 22MB
class Solution {
	void dfs(unordered_map<string,unordered_set<string> > &trace, const string &last, vector<string> path, vector<vector<string> > &vs){
		path.push_back(last);
		if(trace.count(last)==0){
			reverse(path.begin(),path.end());
			vs.push_back(path);
			return;
		}
		for(const string &word:trace[last])
			dfs(trace,word,path,vs);
	}
public:
	vector<vector<string>> findLadders(string begin, string end, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(),wordList.end());
		if (dict.count(end)==0) return {};
		unordered_map<string,unordered_set<string> > trace;
		unordered_set<string> q={begin}, dels;
		for(; q.size() && trace.count(end)==0; q=dels){
			for(const string &word:q)
				dict.erase(word);
			dels.clear();
			for(const string &word:q){
				for(int i=0; i<word.length(); ++i){
					string s=word;
					for(char ch='a'; ch<='z'; ++ch){
						if(word[i]==ch) continue;
						s[i] = ch;
						if(dict.find(s)==dict.end()) continue;
						trace[s].insert(word);
						dels.insert(s);
					}
				}
			}
		}
		if(trace.size()==0) return {};
		vector<vector<string> > result;
		dfs(trace,end,{},result);
		return result;
	}
};
```
