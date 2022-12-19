### 解题思路
直接使用KMP算法匹配子串

### 代码

```cpp
class Solution {
public:
    vector<int> getNext(string p) {
        vector<int> next(p.size());
        int j = 0;
        int k = -1;
        next[0] = -1;
        while (j < p.size() - 1) {   //注意要小于长度减1
            if (k == -1 || p[j] == p[k]) {
                if (p[++j] == p[++k])
                next[j] = next[k];
                else
                next[j] = k;
            }
            else
                k = next[k];
        }
        return next;
    }
    
    int KMP(string t, string p) {
        int i = 0, j = 0;
        vector<int> next = getNext(p);
        while ((i < t.size()) && j<(int)p.size()) {
            if (j == -1 || t[i] == p[j]){
                i++; j++;
            }
            else {
                j = next[j];
            }
        }
        if (j == p.size()) {
            return i - j;
        }
        else
            return -1;
    }
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        return KMP(haystack, needle);
    }
};
```