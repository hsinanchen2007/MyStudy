### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        
        int t1 = -1, t2 = -1, res = INT_MAX;
        for (int i = 0; i < words.size(); i ++) {
            if (words[i] == word1) t1 = i;
            else if (words[i] == word2) t2 = i;
            if (t1 != -1 && t2 != -1) res = min(res, abs(t1 - t2));
        }
        return res;
    }
};
```