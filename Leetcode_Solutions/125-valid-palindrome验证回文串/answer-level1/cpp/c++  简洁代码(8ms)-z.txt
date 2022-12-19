### 解题思路
双指针，逐个比较首尾的字母或数字

isalnum:如果参数为字母或数字，则返回值为1
toupper:将小写字母变为大写，如果是数字则不变

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        for(int left=0,right=s.size()-1 ;left<right;   left++,right--)      //定义双指针
        {
            while(!isalnum(s[left])  &&left<right)   left++;       //直到s[left]为字母或数字
            while(!isalnum(s[right]) &&left<right)   right--;       //直到s[right]为字母或数字
            if(toupper(s[left])!=toupper(s[right]))     //toupper将小写字母变为大写，如果是数字则不变
                return false;           
        }
        return true;
    }
};
```