### 解题思路
先决条件：两个数组必须大小一样；
哈希表存储每个字母出现的次数，只要任何一个字符出现的次数都相等，则可以进行重排列得到。

### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;

        int hash1[128];
        int hash2[128];
        for(int i =0; i<128; i++) {
            hash1[i]=0;
            hash2[i]=0;
        }
        for(int j=0;j<s1.size(); j++){
            hash1[s1[j]]++;
            hash2[s2[j]]++;
        }

        for(int a=0; a<128; a++){
            if(hash1[a]!=hash2[a]) return false;
        }
        return true;
    }
};
```