### 解题思路
对**t**进行遍历，每个字符与**s**中字符匹配，相等则继续匹配，不等则还匹配原有s位置字符，当遍历完成时，如果没有匹配完所有的字符，则返回false，否则返回true。

### 代码

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        /**
            方法2:暴力法————遍历t字符串，按顺序比对是否出现s字符
            时间复杂度:O(m+n)
            空间复杂度:O(1)
        */
        int j =0;//s的定位标签

        // 对t进行遍历
        for(int i=0;i<t.size();i++)
        {
            if(t[i] == s[j]) j++;// 如果相等，下次循环匹配s下一位字符
        }
        if(j == s.size()) return true;
        else return false;
    }
};
```