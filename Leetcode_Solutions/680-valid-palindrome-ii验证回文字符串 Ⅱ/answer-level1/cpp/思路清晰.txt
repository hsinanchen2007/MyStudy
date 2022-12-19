### 解题思路
此处撰写解题思路
双指针，要么left+1，要么right-1
### 代码

```cpp
class Solution {
public:
    bool Judgehuiwen(int left,int right,string &str){
        if (left == right) {
            return true;
        }
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
                break;
            } else {
                left++;
                right--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        if (s.size() == 1) {
            return true;
        }
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return (Judgehuiwen(left + 1, right, s)) || (Judgehuiwen(left, right - 1, s));
            } else {
                left++;
                right--;
            }
        }
        return true;
    }
};
```