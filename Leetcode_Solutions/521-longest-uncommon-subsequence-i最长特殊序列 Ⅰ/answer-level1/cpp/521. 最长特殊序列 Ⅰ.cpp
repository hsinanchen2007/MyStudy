### 解题思路
1.若两个字符串不相等，则返回较长字符串的长度。
2.若两个字符串相等则返回-1。
3.若以上两种情况都不是，则返回字符串a的长度。
### 代码

```cpp
class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.size() != b.size()){
            return max(a.size(),b.size());
        }
        if(a == b){
            return -1;
        }
        return a.size();
    }
};
```