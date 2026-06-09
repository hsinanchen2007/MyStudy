### 解题思路
用string.compare对字符串进行比较，
遍历wordDict中的word，与s的字串（从i开始，往前数word.size()个）进行比较，如果比较结果一致，改变dp
常规DP解法，需要注意的地方是s的索引i和dp数组的索引之间的关系。

### 代码

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);      //创建length+1的vector
        dp[0] = true;      //第一个设置为True，因为空字符串也匹配，其他的都是False
        for(int i=0; i<=s.size(); ++i) {
            for(auto word: wordDict) {      //遍历字典中的字符串
                int ws = word.size();
                if(i - ws >= 0) {
                    if ( !s.compare(i-ws, ws, word) && dp[i-ws]) {  //字符串一致返回0所以取！
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[s.size()];    //返回最后的一个元素即为结果
    }
};
```
![image.png](https://pic.leetcode-cn.com/3ffa64695af023c5752450ebae5baef44f749054c5b32eff5d7ef2c915bae10a-image.png)
