### 解题思路
每次判断一个区间，直接看代码吧，比较好理解

### 代码

```cpp
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = 0, len2 = 0;
        while(len1 < version1.length() || len2 < version2.length()){
            string str1 = "", str2 = "";
            while(len1 < version1.length() && version1[len1] != '.') str1 += version1[len1++];
            while(len2 < version2.length() && version2[len2] != '.') str2 += version2[len2++];
            int a = str1.length() ? atoi(str1.c_str()) : 0;
            int b = str2.length() ? atoi(str2.c_str()) : 0;
            if(a < b) return -1;
            else if(a > b) return 1;
            len1++; len2++;
        }
        return 0;
    }
};
```