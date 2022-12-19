我也是第一次接触到双向BFS的，很难想到但是想到后还是很容易写的。
基本思想就是BFS遍历是一个金字塔型，越往后遍历，塔基越大。而在众多塔基上只有一点（end）是解，其回溯的路径也很少。
所以逆向思维自底向上BFS，就有可能减少时空消耗。而双向BFS更加精妙，从begin->end遍历和从end->begin同时进行，当待遍历的队列哪个短先遍历哪个。
结束条件是，双向BFS遍历碰头。可以记录每个单词的遍历方向，1表示从前向后，2表示从后向前，3表示双向都遍历过了，即解。
```
// Time 68ms, 13.4MB
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_map<string,int> freqs;
		for(const auto &word:wordList)
			freqs[word]=0;
		if(freqs.count(endWord)==0) return 0;
		queue<string> q1({beginWord}), q2({endWord});
		int step=1;
		for(freqs[beginWord]|=1,freqs[endWord]|=2; q1.size() && q2.size(); ++step){
			bool first=q1.size()<q2.size();
			queue<string> &q=first?q1:q2;
			int flag=first?1:2;
			for(int size=q.size(); size--; q.pop()){
				string &word=q.front();
				if(freqs[word]==3) return step;
				for(int i=0; i<word.length(); ++i){
					for(char ch='a'; ch<='z'; ++ch){
						string s=word;
						if(s[i]==ch) continue;
						s[i]=ch;
						if(freqs.count(s)==0 || freqs[s]&flag) continue;
						freqs[s]|=flag;
						q.push(s);
					}
				}
			}
		}
		return 0;
	}
};
```
