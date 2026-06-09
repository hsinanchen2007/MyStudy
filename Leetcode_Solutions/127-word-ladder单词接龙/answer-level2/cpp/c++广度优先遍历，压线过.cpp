### 代码

```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int wordlen = wordList.size();
        vector<bool> used(wordlen, false);
        int n = 0;
        queue<string> que;
        que.push(beginWord);
        while(!que.empty()){
            int quelen = que.size();
            n++;
            for(int i = 0; i < quelen; i++){
                string item = que.front();
                que.pop();
                for(int j = 0; j < wordlen; j++){
                    if(endWord == item) return n;
                    if(used[j]) continue;
                    if(check(item, wordList[j])){
                        used[j] = true;
                        que.push(wordList[j]);
                    }
                }
            }
        }
        return 0;
    }
    bool check(string s1, string s2){
        int count = 0;
        for(int i = 0; i < s1.size(); i++){
            if(count > 1) return false;
            if(s1[i] != s2[i]) count++;
        }
        return count == 1;
    }
};
```