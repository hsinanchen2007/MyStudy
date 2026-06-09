### 解题思路
比如我们需要处理[0~j]的子串，当0<=i<=j的时候，如果s[i~j]的子串在字典里面，且[0~i-1]的子串是已经可以拆分的，那么[0~j]就是可以拆分的。从0到j遍历i，所有结果取或，这样就可以知道[0~j]的子串是不是可以拆分了。
优化点：
1、一旦判断[0~j]的子串已经可以拆分，就没必要继续遍历i了
2、判断是不是在字典里面可以用个set，减少查找时间      

### 代码

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> sset;
        for (auto str : wordDict) {
            sset.emplace(str);
        }
        vector<bool> res(s.length(), false);
        for (int j=0; j<s.length(); j++) {
            for (int i=0; i<=j; i++) {
                auto str = s.substr(i, j-i+1);
                if (sset.count(str)) {
                    if (i == 0 || res[i-1]) {
                        res[j] = true;
                        break;
                    }
                }
            }
        }
        return res[s.length()-1];
    }
};
```