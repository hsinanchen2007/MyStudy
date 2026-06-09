### 解题思路
转成图，层序寻找最短路径

### 代码

```cpp
class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<int,vector<int>> ma;
        vector<bool> log(wordList.size(),false); 
        int target=-2;
        int size=wordList.size();
        for(int i=0;i<size;++i){
            if(wordList[i]==endWord){
                target=i;
            }
            if(IsLengthEqualOne(beginWord,wordList[i])){
                ma[-1].push_back(i);
            }
        }
        if(target==-2){
            return 0;
        }
        for(int i=0;i<size;++i){
            for(int j=0;j<size;++j){
                if(IsLengthEqualOne(wordList[i],wordList[j])){
                    ma[i].push_back(j);
                }
            }
        }
        queue<int> q;
        q.push(-1);
        int ans=1;
        while(!q.empty()){
            ++ans;
            int qsize=q.size();
            for(int i=0;i<qsize;++i){
                int temp=q.front();
                q.pop();
                for(auto a:ma[temp]){
                    if(a==target){
                        return ans;
                    }
                    if(!log[a]){
                        q.push(a);
                        log[a]=true;
                    }
                }

            }
        }
        return 0;

    }

    bool IsLengthEqualOne(const string& first,const string& second){
        int count=0;
        for(int i=0;i<first.size();++i){
            if(first[i]!=second[i]){
                ++count;
                if(count>1){
                    return false;
                }
            }
            
        }
        return count==1;
    }
};
```