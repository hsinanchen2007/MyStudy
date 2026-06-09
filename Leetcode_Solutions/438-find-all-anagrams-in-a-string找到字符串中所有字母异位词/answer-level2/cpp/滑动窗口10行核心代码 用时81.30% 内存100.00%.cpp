### 解题思路
注释应该已经写清楚了。

首先在哈希表中标记字符串p中出现的字符状况。
用一个滑动窗口盖在数组s上，右边界一位一位向右滑动并标记访问到的字符，滑动窗口拓展到p那么长时，当前滑动窗口覆盖的子串是一个可能解。于是直接比较s和p的哈希表是否相等（c++的vector可以直接用==比较）。如果相等，ans里推入当前左边界值l；否则，左边界右移一位并删除曾经访问的字符的标记。进入下一轮循环。循环结束的条件是右边界在循环体内滑动到lenS-1，下一轮循环判断就会终止循环。

两个个优化点：左边界最小取值是0，可能解的长度是lenP，所以右边界最小取值是lenP-1，所以r < lenP-1直接continue；p比s短立刻返回无解。

### 代码

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int lenS = (int)s.size(), lenP = (int)p.size();
        if(lenP > lenS) return ans;
        vector<int> hashtableP(256, 0);
        vector<int> hashtableS(256, 0);
        for(auto ch : p) ++hashtableP[ch];
        int l = 0, r = -1; // 滑动窗口初始化为一个不存在的区间[0, -1]
        while(r < lenS-1) // r == lenS-1时退出循环
        {
            if (r+1 < lenS) ++hashtableS[s[++r]]; // 窗口右边界右移一位 并标记访问到的值
            if(r < lenP-1) continue; // 符合条件的r一定 >= p.length - 1
            if(hashtableP == hashtableS) ans.push_back(l);
            --hashtableS[s[l++]]; // 窗口左边界右移一位 并删除曾经访问的值的标记
        }
        return ans;
    }
};
```