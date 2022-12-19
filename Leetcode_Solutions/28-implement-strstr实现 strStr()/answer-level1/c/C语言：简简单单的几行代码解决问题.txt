用了一点KMP的思想
```
int strStr(char * haystack, char * needle)
{
    if (haystack == NULL || needle == NULL) return -1;
    if (needle[0] == '\0')                  return 0;
    int i = 0, j = 0;
    while (haystack[i] && needle[j]) {
        if (haystack[i] == needle[j]) ++i, ++j;//如果相当就后移
        else {
            i = i - j + 1;//指向开始字符的下一个字符
            j = 0;//重头比较
        }
    }
    return (needle[j] ? -1 : (i - j));//如果needle没有到结尾就输出 -1
}
```
