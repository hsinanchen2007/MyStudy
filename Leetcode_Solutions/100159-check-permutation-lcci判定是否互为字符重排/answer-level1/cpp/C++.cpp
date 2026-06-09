### 解题思路
此处撰写解题思路
若字符互为重排，则按大小排序后两个字符串应该完全相同。

### 代码

```cpp
#include <string>
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        s1 = replace(s1);
        s2 = replace(s2);
        if(s1 == s2) return true;
        else return false;
    }
    string replace(string s){
        for(int i = 0; i < s.size(); i++){
            int min = i;
            for(int j = i+1; j < s.size(); j++){
                if(s[j] < s[min]) min = j;
            }
            if(min != i){
                char a = s[min];
                s[min] = s[i];
                s[i] = a;
            }
        }
        return s;
    }
};
```