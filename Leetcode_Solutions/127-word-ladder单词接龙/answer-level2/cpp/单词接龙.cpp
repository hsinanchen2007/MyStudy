广度优先搜索求解，注意这里我们选用unordered_set<string> visited用来标记单词是否被访问过，如果已经被访问过，说明已经有对应路径存在，因此跳过访问，或者也可以使用vector<bool> visited，用来标记单词是否被访问过，实现如下：
```
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        unordered_set<string> visited;
        visited.insert(beginWord);
        queue<string> q;
        q.push(beginWord);
        int res=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto t=q.front();
                q.pop();
                for(int i=0;i<t.size();i++){
                    string word=t;
                    for(auto ch='a';ch<='z';ch++){
                        word[i]=ch;
                        if(!dict.count(word) || visited.count(word)) continue;
                        if(word==endWord) return res+1;
                        visited.insert(word);
                        q.push(word);
                    }
                }
            }
            res++;
        }
        return 0;
    }
};
```
