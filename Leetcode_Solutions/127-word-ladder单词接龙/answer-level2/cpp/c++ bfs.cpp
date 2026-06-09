参考官方解答，仅使用c++实现了一下。
```
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = beginWord.size();
        unordered_map<string,vector<string>> mmap;
        for(string s:wordList){  ////建立邻接表
            for(int i=0; i<len; ++i){
                //截取字符串
                string newWord = s.substr(0,i)+ '*' + s.substr(i+1,len);
                mmap[newWord].push_back(s);
            }
        }
        queue<pair<string,int>> q;
        q.push(make_pair(beginWord,1));
        unordered_map<string,bool> visited;  //访问过的进行标记
        visited[beginWord] = true;
        while(!q.empty()){
            pair<string,int> node = q.front();
            q.pop();
            string word = node.first;
            int level = node.second;
            if(word==endWord) return level;
            for(int i=0; i<len; ++i){
                string newWord = word.substr(0,i)+ '*' + word.substr(i+1,len);
                for(auto adjacentWord:mmap[newWord]){
                    if(visited.find(adjacentWord) == visited.end()){  //未访问过
                        visited[adjacentWord] = true;
                        q.push(make_pair(adjacentWord,level+1));
                    }                        
                }
            }            
        }
        return 0;
    }
};
```
