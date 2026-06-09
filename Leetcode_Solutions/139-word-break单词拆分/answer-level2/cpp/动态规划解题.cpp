### 解题思路
回溯法在这里显得有点臃肿了，动态规划会清爽不少，效率也更好。

### 代码

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //动态规划的答案集
        vector<bool> ans(s.size(), false);
        //查找用的哈希表
        unordered_map<string, bool> mp;
        //初始化哈希表，搜索起来速度快点。（为啥输入默认是数组?!）
        for (int i=0; i<wordDict.size(); i++) {
            mp[wordDict[i]] = true;
        }
        //大循环遍历string
        for (int i=0; i<s.size(); i++) {
            //如果从开始到当前字母就是一个完整的单词，那么直接判true就行了
            if (mp.find(s.substr(0,i+1)) != mp.end()) {
                ans[i] = true;
                continue;
            }
            //看看能不能跟着前边的某个节点接上一个单词
            for (int j=0; j<i; j++) {
                if (ans[j] && mp.find(s.substr(j+1, i-j)) != mp.end()) {
                    ans[i] = true;
                    break;
                }
            }
        }
        return ans[ans.size()-1];
    }
};
```