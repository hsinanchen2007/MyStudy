该题与【127.单词接龙】唯一区别在于如何将路径给记录下来，我采用的结构是queue<pair<string, string>>，first是下一个结点单词，后面是一个字符串路径，单词之间使用“-”连接，这样通过转换找到了目标单词后，second就是该路径的字符串，如例子：
begword = "hit"
endword = "cog"
wodlist = ["hot","dot","dog","lot","log","cog"]

最后路径字符串为：hit-hot-dot-dog-cog

然后进行字符串分割即可
```
vector<string> testSplit11(const string& in, const string& delim)
{
	vector<string> ret;
	try {
		regex re{ delim };
		return vector<string>{
			sregex_token_iterator(in.begin(), in.end(), re, -1),
				sregex_token_iterator()
		};
	}
	catch (const exception& e){
		cout << "error:" << e.what() << endl;
	}
	return ret;
}
/* 建立通用状态对应的单词列表映射关系 */
void generateMap(int len, map<string,vector<string>> &mp, vector<string>& wordList){
	for (auto word : wordList){
		for (int i = 0; i < len; i++){
			string tmp_word = word;
			tmp_word[i] = '*';
			if (mp.count(tmp_word) == 0) {
				vector<string> vec = { word };
				mp.insert({ tmp_word, vec });
			} else {
				mp[tmp_word].push_back(word);
			}
		}
	}
}

vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	int count = 1;
	int len = beginWord.size();
	map<string, vector<string>> mp; /* 通用状态对应的单词字典 */
	queue<pair<string, string>> Q;
	set<string> st;
	vector<string> vec;


	/* 建立通用状态对应的单词列表映射关系 */
	generateMap(len, mp, wordList);

	Q.push({ beginWord, beginWord});
	st.insert(beginWord);

	while (!Q.empty()) {
		int size = Q.size();
		//遍历当前队列中所有单词 
		for (int i = 0; i < size; i++){
			pair<string, string> front = Q.front();
			
			/* 如果当前单词与目标单词一致，则完成搜索 */
			if (front.first == endWord) {
				return testSplit11(front.second, "-");
				
			}
			Q.pop();

			/* 找到当前单词所有可能的下一个目标单词 */
			for (int j = 0; j < len; j++){
				string w = front.first;
				w[j] = '*';
				/* 找到连接的边 */
				if (mp.count(w) != 0) {
					for (auto a : mp[w]) {
						if (st.count(a) == 0) {//没有搜索过的才加入到队列
							Q.push({a, front.second + "-" + a});
							st.insert(a);
						}
					}
				}
			}
		}
	}
	return vec;
}
```


