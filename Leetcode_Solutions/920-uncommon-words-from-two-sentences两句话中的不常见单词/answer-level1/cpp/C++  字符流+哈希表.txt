### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string,int> hash;
        stringstream ssA(A);
        stringstream ssB(B);
        string word;
        while(ssA >> word)
            hash[word]++;
        while(ssB >> word)
            hash[word]++;
        vector<string> res;
        for(auto iter: hash)
            if(iter.second == 1)
                res.emplace_back(iter.first);
        return res;
    }
};
```