### 解题思路
速度一般般，但是解出来了

思路：先将输入的字符串分隔，用一个map来存储以i开始的并且在字典中的子串。比如题目中"cat", "cats"都是从i=0开始的。那么map[0]=["cat", "cats"]
剩下的工作就是要将这些子串拼接成答案，这里用一个递归调用就好，表示组合从[i~s.length]的可能组合，如果没有组合，则返回空数组。这里可以用一个map来记录已经组合过从i开始的组合了，避免重复遍历。


### 代码

```cpp
class Solution {
public:
    vector<string> combineString(long start, long length, map<long, vector<string>> &mmap, map<long, vector<string>> &strDp) {
        if (strDp.count(start) != 0) {
            return strDp[start];
        }
        if (mmap.count(start) == 0) {
            return vector<string>();
        }
        auto v = mmap[start];
        vector<string> res;
        for (auto s : v) {
            long nextStart = start + s.length();
            if (nextStart < length) {
                auto nextV = combineString(nextStart, length, mmap, strDp);
                for (auto nextS : nextV) {
                    res.emplace_back(s + " " + nextS);
                }
            } else { //加上这个字符s就已经到结尾了，不用再递归
                res.emplace_back(s);
            }
            
        }
        strDp[start] = res;
        return res;
    }


    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<long, vector<string>> mmap;
        set<string> sset;
        for (auto str : wordDict) {
            sset.emplace(str);
        }
        
        for (int j=0; j<s.length(); j++) {
            for (int i=0; i<=j; i++) {
                auto str = s.substr(i, j-i+1);
                if (sset.count(str)) {
                    if (0 == mmap.count(i)) {
                        mmap[i] = vector<string>();
                    }
                    mmap[i].emplace_back(str);
                }
            }
        }
        map<long, vector<string>> strDp;
        return combineString(0, s.length(), mmap, strDp);
    }
};
```