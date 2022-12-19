### 解题思路
利用双指针。
### 代码

```cpp
class Solution {
public:
int isCharOrNum(char s)  //判断是否为数字或字母，数字返回1；字母返回2
{
    if(s >= '0' && s <= '9')
        return 1;
    else if(s >= 'A' && s <= 'Z')
        return 2;
    else if(s >= 'a' && s <= 'z')
        return 2;
    return 0;
}
bool isPalindrome(string s)
{
    if(s.length() < 2)  //字符串长度小于2，满足题意
        return true;
    int left = 0, right = s.length()-1;
    while(left < right)
    {
        while(left <= s.length() - 1 && isCharOrNum(s[left]) == 0 )  //从左边向右移动，找到第一个字母或数字。（注意：指针不能溢出字符串长度）
            left ++;
        while(right > -1 && isCharOrNum(s[right]) == 0)  //从右边向左移动，找到第一个字母或数字。
            right --;
        if(left >= right)  //如果已经比较完了，输出True
            return true;
        if(isCharOrNum(s[left]) != isCharOrNum(s[right]))  //如果字符类型不同，输出false
            return false;
        else
        {
        if((s[left] - s[right]) % 32 != 0)  //如果字母不相同，输出false
               return false;
         left ++;
         right --;
        }
    }
    return true;
    }
};
```