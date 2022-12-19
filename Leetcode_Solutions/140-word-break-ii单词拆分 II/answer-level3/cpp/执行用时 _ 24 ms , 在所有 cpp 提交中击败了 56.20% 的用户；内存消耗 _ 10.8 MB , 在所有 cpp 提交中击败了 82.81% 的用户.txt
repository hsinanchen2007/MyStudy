### 解题思路
速度一般，跟着别人的思路写出来的，代码里有注释

### 代码

```cpp
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        int length = (int)s.length();

        /*
        在139题中，dp为一维数组，dp[i]表示前i个字符串是否可以匹配，bool值
        但在此题中,如果前i个字符可以匹配，还要记录每次匹配的字符串，比如：
        s = "catsanddog"
        wordDict = ["cat", "cats", "and", "sand", "dog"]
        s中前7个字符catsand可以匹配，但是有两种方式匹配，cat，sand 和 cats，sand.
        所以每次匹配时要记录这个一次匹配串的长度。
        dp[0] = {0};
        dp[3] = {3}; // 当i=3时，前3个可以匹配，记录此时可以匹配的字符串长度3
        dp[4] = {4}; // 当i=4时，前4个可以匹配，记录此时可以匹配的字符串长度7
        dp[7] = {3,4}; // 当i=7时，前3个字符and可以匹配，记录为3；前4个字符sand也可以匹配,记录为4
        dp[10] = {3};
        */
        
        vector<vector<int>> dp(length+1);
        dp[0] = {0};
        
        for(int i = 0; i <= s.size(); i++) {
            for(auto word : wordDict) {
                int wordLength = (int)word.size();
                if(i >= wordLength) {
                    string subStr = s.substr(i-wordLength, wordLength);
                    if(subStr == word && !dp[i-wordLength].empty()) {
                        dp[i].push_back(wordLength);
                    }
                }
            }
        }
        

        if(dp[length].empty()) {
            return vector<string>(); // 剪枝：整个串都不匹配，直接返回
        }
        
        vector<vector<string>> res(length+1); // res[i] 表示前i个字符串匹配时，所有的匹配方式
        
        /*
        上面已经找到了每次匹配的的字符长度，现在可以求结果了
        */
        for(int i = 1; i <= s.size(); i++) {
            if(dp[i].empty()) {
                continue;
            }
            vector<int> lengthArr = dp[i];
            for(auto autoLength : lengthArr) { //autoLength表示这一次匹配的匹配长度
                if(dp[i-autoLength][0] == 0) {
                    res[i].push_back(s.substr(i-autoLength,autoLength)); // 这里说明是第一次匹配成功，跟之前的没有关联
                }
                else {
                    /*
                    更新元素：res[i-autoLength]中的每一个元素都要更新，更新后的结果即为res[i]
                    */
                    for(auto str : res[i-autoLength]) {
                        res[i].push_back(str + ' ' + s.substr(i-autoLength,autoLength));
                    }
                }
            }
        }
        return res[length];
    }
};
```