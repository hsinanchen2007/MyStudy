### 解题思路
![)S98S2FGNZBYKEUGMCQEMOW.png](https://pic.leetcode-cn.com/7517f7011284ecef64a7fdc056e84f320a80688dd3787fcc862a808fe9e88a0a-\)S98S2FGNZBYKEUGMCQEMOW.png)
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> min = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i = 0; i < words.size(); i++)
        {
            string stmp;
            int sin = words[i].size();
            for(int j = 0; j < sin; j++)
            {
                stmp += min[words[i][j] - 97];
            }
            words[i] = stmp;
        }
        set<string> st(words.begin(), words.end());
        words.assign(st.begin(), st.end());
        return words.size();
    }
};
```