### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s. size();
        int count = 0;
        int k = 0;
        for(int i = 0; i < t.size(); i++){
            if(k < n && t[i] == s[k]){
                count++;
                k++;
            }
        }
        return count == n;
    }
};
```