### 解题思路

### 代码

```cpp
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ptr1 = 0, ptr2 = 0;
        int pre1 = 0, pre2 = 0;
        int v1=0, v2=0;
        while (pre1 < version1.size() || pre2 < version2.size()) {
            if (pre1 < version1.size()) {
                while (version1[ptr1] != '.' && ptr1 < version1.size()) {
                    ptr1++;
                }
                v1 = stoi(version1.substr(pre1, ptr1-pre1));
                ptr1++;
                pre1 = ptr1;
            }
            else {
                v1 = 0;
            }

            if (pre2 < version2.size()) {
                while (version2[ptr2] != '.' && ptr2 < version2.size()) {
                    ptr2++;
                }
                v2 = stoi(version2.substr(pre2, ptr2-pre2));
                ptr2++;
                pre2 = ptr2;    
            }
            else {
                v2 = 0;
            }

            if (v1==v2) continue;
            if (v1>v2) 
                return 1;
            else 
                return -1;
            
        }
        return 0;
    }
};
```