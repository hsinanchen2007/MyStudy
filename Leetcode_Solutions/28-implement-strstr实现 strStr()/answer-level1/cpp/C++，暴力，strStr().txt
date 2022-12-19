### 解题思路
暴力解法，循环判断以每个元素开始是否匹配，复杂度最高O(MN）

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        for(int i = 0; i < n - m + 1; i ++) {
            int j = 0;
            while (j < m && haystack[i+j] ==  needle[j]) j++;
            if(j == m) return i;
        }
        return -1;
    }
};

```