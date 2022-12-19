### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX;
        vector<int> ind1;
        vector<int> ind2;
        for (int i = 0; i < words.size(); i++){
            if (words[i] == word1) ind1.push_back(i);
            if (words[i] == word2) ind2.push_back(i); 
        }
        for (int m = 0; m < ind1.size(); m++){
            for(int n = 0; n < ind2.size(); n++){
                res = min(abs(ind1[m] - ind2[n]), res);
            }
        }
        return res;
    }
};
```