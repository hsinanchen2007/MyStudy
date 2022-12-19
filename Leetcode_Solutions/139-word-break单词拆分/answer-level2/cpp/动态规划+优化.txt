定义dp[i]表示从0～i字符串可否被分割，
则对于dp[i+1]而言，寻找其中一个位置p，使得dp[p]==true && 字符串p~i+1在字典中，则dp[i+1]为true。
进一步优化，没必要从0～i+1寻找位置p，因为字符串p~i+1的长度必须为字典中的任意一个单词长度，这是必要条件。
步骤：首先把words加入hashset中提高查询速度，然后遍历词典寻找所有可能的单词长度lens，最后遍历一遍。
```
// Time O(n*k), Space O(n+m+k)，n为字符串长度，m为单词个数，k为所有单词长度个数。
// Time 4ms, 98%， Space 8.9MB, 92%
class Solution {
public:
    bool wordBreak(string s, vector<string>& words) {
        unordered_set<string> dict;
        for(int i=0; i<words.size(); dict.insert(words[i++]));
        unordered_set<int> lens;
        for(const string &word:dict)
            lens.insert(word.length());
        vector<bool> dp(s.length()+1,false);
        dp[0]=true;
        for(int i=1; i<=s.length(); ++i){
            for(const int &l:lens){
                if(i>=l && dp[i-l] && dict.count(s.substr(i-l,l))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
```
