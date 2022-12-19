### 解题思路
bfs思路

### 代码

```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;//队列
        int res=1;
        unordered_map<string,bool> map; //备忘
        for(int i=0;i<wordList.size();i++){
            map[wordList[i]]=false;
        }

        q.push(beginWord);

        while(!q.empty()){
            int qsize=q.size();
            for(int i=0;i<qsize;i++){
                string tmp=q.front();
                q.pop();
                for(int j=0;j<wordList.size();j++){
                    int count=0;
                    for(int k=0;k<wordList[0].size();k++)
                    {
                        if(tmp[k]!=wordList[j][k]) count++;
                        if(count>1) break;
                    }
                    if(count==1&&wordList[j]==endWord) return res+1;
                    if(count==1&&!map[wordList[j]]){
                        q.push(wordList[j]);
                        map[wordList[j]]=true;
                    }  
                }
                
            }
            res++;
        }
        return 0;
    }
};
```