

```c
bool isPalindrome(char * s)
{
    int len = strlen(s);
    int left = 0, right = len - 1;
    char* cur = s;
    while(*cur)                //把大写字符全部转化成小写
    {
        if(65<= *cur && *cur <= 90)
            *cur = *cur + 32;
        ++cur;
    }
    while(left <= right)
    {
        if(((97 <= s[left] && 122 >= s[left]) || (48 <= s[left] && 57 >= s[left])) && 
           ((97 <= s[right] && 122 >= s[right]) || (48 <= s[right] && 57 >= s[right])))   //左右都是字母或者字符
        {
            if(s[left] != s[right])     //不等则返回false
                return false;
            ++left;--right;              //否则缩小范围
        }
        else if(97 <= s[left] && 122 >= s[left] || 48 <= s[left] && 57 >= s[left])  //左边是字符或数字，右边不是
            --right;
        else if(97 <= s[right] && 122 >= s[right] || 48 <= s[right] && 57 >= s[right]) //右边是字符或数字，左边不是
            ++left;
         else if(!(((97 <= s[left] && 122 >= s[left]) || (48 <= s[left] && 57 >= s[left])) &&   //左右边都不是字符或数字
           ((97 <= s[right] && 122 >= s[right]) || (48 <= s[right] && 57 >= s[right]))))
        {
            ++left;
            --right;
        }
    }    
  return true;
}
```
```
