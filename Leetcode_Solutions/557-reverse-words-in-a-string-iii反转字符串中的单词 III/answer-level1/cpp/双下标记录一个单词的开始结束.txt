### 解题思路
双下标记录一个单词的开始结束，然后对每个单词做反转就行

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        if ( len <= 1)return s;
        int l = 0;
        for ( int i = 0 ; i <= len ; i++){
            if (s[i] == ' ' || s[i] == '\0'){
                for ( int j = 0 ; j < (i-l)/2 ; j++){
                    char temp = s[i-1-j];
                    s[i-1-j] = s[l+j];
                    s[l+j] = temp;
                }
                l = i+1;
            }
        }
        return s;
    }
};
```