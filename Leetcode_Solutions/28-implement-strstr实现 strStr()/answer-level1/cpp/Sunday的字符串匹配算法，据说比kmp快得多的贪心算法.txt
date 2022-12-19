### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();

        unordered_map<char, int> note;
        for(int i=1; i<=n; i++){
            if (note[needle[n-i]]==0)
                note[needle[n-i]] = i;
        }

        for(int i=0; i<=m-n;){
            if (!haystack.compare(i, n, needle))
                return i;
            if (i+n==m)
                return -1;
            /*下一跳n+1个位置*/
            if (note[haystack[i+n]]==0)
                i += (n + 1);
            /*下一跳，needl从后往前数第一个对齐haystack[i+n]位置移动步数*/
            else
                i += note[haystack[i+n]];
        }
        return -1;
    }
};
```