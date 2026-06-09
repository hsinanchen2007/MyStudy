### 解题思路
此处撰写解题思路
1.判断首指针是否为字母或数字，如果不是则++
2.判断尾指针是否为字母或数字，如果不是则--
3.判断首指针是否为小写，如果是则改为大写
4，判断尾指针是否为小写，如果是则改为大写
5.判断首指针和尾指针是否一样，如果不一样则返回false
6.如果一样，首指针++，尾指针--，返回第1步，直到首指针大于等于尾指针。
7.返回true
### 代码

```cpp
class Solution {
public:
    inline bool isCharOrNum(char& c)
    {
        return (c>='0'&&c<='9')|| (c>='A'&&c<='Z') || (c>='a'&&c<='z');
    }
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            while(i<j&&!isCharOrNum(s[i]))i++;
            while(i<j&&!isCharOrNum(s[j]))j--;
            if(s[i]>='a'&&s[i]<='z')s[i]-=32;
            if(s[j]>='a'&&s[j]<='z')s[j]-=32;
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
};
```
