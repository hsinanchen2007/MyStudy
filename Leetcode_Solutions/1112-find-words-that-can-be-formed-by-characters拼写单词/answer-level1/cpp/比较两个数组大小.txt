### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> parse(string &s){
        vector<int> dp(128, 0);
        for(char ch : s){
            dp[ch]++;
        }
        return dp;
    }

    bool contains(vector<int> &lst, vector<int> &target){
        for(int ch = 'a'; ch <= 'z'; ch++){
            if(lst[ch] < target[ch]){
                return false;
            }
        }
        return true;
    }


    int countCharacters(vector<string>& words, string chars) {
        vector<int> lst = parse(chars);
        int res = 0;
        for(string word : words){
            vector<int> tmp = parse(word);
            if(contains(lst, tmp)){
                res += word.size();
            }
        }
        return res;
    }
};
```