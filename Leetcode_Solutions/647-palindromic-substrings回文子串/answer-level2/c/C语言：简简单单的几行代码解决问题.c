采用中心扩展法

```
int countSubstrings(char* s)
{
    int len = strlen(s), num = 0;
    for (int start = 0, left, right; start < len; ++start, ++num) {  //++num 原因是因为每一个字母本身就是回文串
        for (left = start,   right  = start+1; left>=0 && right<len && s[left] == s[right]; --left, ++right,++num);
        for (left = start-1, right  = start+1; left>=0 && right<len && s[left] == s[right]; --left, ++right,++num);
    }
    return num;
}
```
