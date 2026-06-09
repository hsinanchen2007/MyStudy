### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {

        int i = 0;
        int j = s.size()-1;

        while(i < j) {
            int pre = s[i];
            if( isalnum(pre)) {
                pre = tolower(pre);
            }else {
                i++;
                continue;
            }
            
            int back = s[j];
            if(isalnum(back)) {
                back = tolower(back);
            } 
            else {
                j--;
                continue;
            }
            if(pre == back) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
};
```