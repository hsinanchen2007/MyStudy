### 解题思路
![2.png](https://pic.leetcode-cn.com/3a8564140aa8dfa3b42a69b9b38404f9bb1785d5ae51813f39e33d6789071ddc-2.png)
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l = 0;
        int r = s.length()-1;
        while(l<=r){
            if(!isalpha(s[l]))
                l++;
            else if(!isalpha(s[r]))
                r--;
            else if(isalpha(s[l])&&isalpha(s[r])){
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};
```