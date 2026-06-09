### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
       int i=0,j = s.size()-1;
       if(j == -1) return true;
       while(i<j) {
           while(i<j && !isalnum(s[i])) i++;//移动指针，直到遇到字符
           while(i<j && !isalnum(s[j])) j--;
           if(tolower(s[i]) != tolower(s[j])) {
               return false;
           }
           i++;
           j--;
       }
       return true;
    }
};
```