**第一种：双指针**
先利用双指针，一个从前往后，一个从后往前，依次遍历，遇到不同的就做下面的判断
由于只是删除一个字符，那么要么删除左边，要么删除右边，把两种情况结合就可以得到结果

```
bool validPalindrome(char * s){
    for (int i = 0, j = strlen(s)-1; i < j; ++i, --j) 
        if (s[i] != s[j]) 
            return (judge(s, i+1,j) || judge(s, i,j-1)); 
    return true;
}
int judge(char *str, int i, int j) {
    while (i < j) if (str[i++] != str[j--]) return false;
    return true;
}
```
**第二种：递归**
```
bool recursion(char *s, int left, int right, int is) {
    if (left >= right)       return true;
    if (s[left] == s[right]) return recursion(s, left+1, right-1, is);
    if (is) return false;     //如果那唯一的一次删除机会已经用掉了，那么输出false
    else    return (recursion(s, left+1, right, 1) || recursion(s, left, right-1, 1));
}
bool validPalindrome(char * s){
    return recursion(s, 0, strlen(s)-1, 0);
}
```
