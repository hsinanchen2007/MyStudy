### 解题思路
反转的问题，一般都会想到用双指针i,j，但是这个问题只反转元音字母，即a,e,i,o,u。字符串包含字母、数字和其他字符，这就需要我们比较特殊地切入了。
直接判断当前字符是否为元音字母，那么怎么处理呢？是用数组存储元音字母还是写一个函数来判断呢？我采用的是后者。但是，还要注意的一个问题是，元音字母的大小写也要注意区分，可以使用<ctype.h>的tolower(c)函数，将字符c转为小写字母，当i,j指向的字符均为元音字母时，交换它们的位置并移动指针，否则移动指针。

while (i < j) {
    跳过非元音字母；
    交换元音字母并移动指针；
}

### 代码

```c
/* isVowel: 字符c是元音字母，返回1，否则返回0 */
int isVowel(char c)
{
    char t = tolower(c);    /* 大写字母转换为小写字母 */
    if(t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u')
        return 1;
    else 
        return 0;
}

/* reverseVowels: 反转元音字母 */
char * reverseVowels(char * s)
{
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        /* 跳过非元音字母的字符 */
        while (i < j && !isVowel(s[i])) 
            ++i;
        while (i < j && !isVowel(s[j])) 
            --j;
        /* 交换元音字母 */
        char tmp = s[i];
        s[i++] = s[j];
        s[j--] = tmp;
    }
    return s;
}
```