### 解题思路
如果字符数量小于k 那直接返回false
否则统计一下出现次数为奇数的字符的种类，所得的回文串至少要有这么多 因为奇数字符的话只能放在回文串的正中心，而这样的位置一个回文串只有一个


最近可能准备从前端工程师转行到可以paper reading的工作，简历被嫌弃了。。**各位大佬不妨顺手给我的项目加个星** 万分感谢！
[https://github.com/wfnuser/burrow](https://github.com/wfnuser/burrow)  **[一个分布式缓存的go语言简单实现](https://github.com/wfnuser/burrow)**
希望也可以对大家有帮助


### 代码

```cpp
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;
        unordered_map<char, int> cnt;
        
        for (auto c: s) {
            cnt[c]++;
        }
        int odd = 0;
        
        for (auto p: cnt) {
            if (p.second % 2 == 1) odd++;
        }
        
        if (odd <= k) return true;
        else return false;
    }
};
```