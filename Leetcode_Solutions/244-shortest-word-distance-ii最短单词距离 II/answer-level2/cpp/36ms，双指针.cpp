### 解题思路

双指针

### 代码

```cpp
class WordDistance {
public:
    unordered_map<string,vector<int>> um;
    WordDistance(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            um[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        auto &t1=um[word1],&t2=um[word2];
        int i=0,j=0;
        int ret=INT_MAX;
        while(i<t1.size()&&j<t2.size()){
            ret=min(abs(t1[i]-t2[j]),ret);
            if(t1[i]>t2[j])++j;
            else ++i;
        }
        return ret;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
```