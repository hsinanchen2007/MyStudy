引入words，代表已经被访问过的单词，然后我们加入level变量，其中当当前路径path长度大于level的长度时候，此时我们需要将原words中的所有变量从dict中移除掉，表明这些变量在下一层的遍历时候都不会被选用，同时更新level并加入判断条件，如果当前level>minLevel，表明该路径已经超过最短路径长度，因此加以剔除。
参考：[[LeetCode] Word Ladder II 词语阶梯之二](https://www.cnblogs.com/grandyang/p/4548184.html)

```
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > res;
        unordered_set<string> dict(wordList.begin(),wordList.end());
        unordered_set<string> words;
        vector<string> beginPath={beginWord};
        queue<vector<string> > paths;
        paths.push(beginPath);
        words.insert(beginWord);
        int level=1,minLevel=INT_MAX;
        while(!paths.empty()){
            int size=paths.size();
            while(size--){
                auto t=paths.front();
                paths.pop();
                if(t.size()>level){
                    for(auto word:words) dict.erase(word);
                    words.clear();
                    level=t.size();
                    if(level>minLevel) break;
                }
                auto last=t.back();
                for(int i=0;i<last.size();i++){
                    string newLast=last;
                    for(auto ch='a';ch<='z';ch++){
                        newLast[i]=ch;
                        if(!dict.count(newLast)) continue;
                        words.insert(newLast);
                        auto path=t;
                        path.push_back(newLast);
                        if(newLast==endWord){
                            res.push_back(path);
                            minLevel=level;
                        }else{
                            paths.push(path);
                        }
                    }
                }
            }
        }
        return res;
    }
};
```
