### 解题思路
判断对应位置是否相同。


C++
### 代码

```cpp
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(int i=0;i<words.size();i++){
            if(check(words[i],pattern)) res.push_back(words[i]);
        }
        return res;
    }
    bool check(string word,string pattern){
        if(word.length()!=pattern.length()) return false;
        for(int i=0;i<pattern.length();i++){
            if(word.find(word[i])!=pattern.find(pattern[i])) return false;
        }
    return true;
    }
};
```
python3:
```
class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        def check(word,pattern):
            if len(word)!=len(pattern):
                return False
            for i in range(len(word)):
                if word.index(word[i])!=pattern.index(pattern[i]):
                    return False
            return True
        res=[]
        for i in range(len(words)):
            if check(words[i],pattern):
                res.append(words[i])
        return res
```