整体思路：
1. 除去尾部空格；
2. 整体反转；
3. 局部单词反转；
4. 去除中间空格；
5. 首部空格反转后在尾部，再次去除尾部空格；

```c
/**
 * 反转字符串
 **/
void reverse(char* str, int start, int end) {
  if (str == NULL) return str;
  int i, j;
  char s;
  for (i = start, j = end; i < j; i++, j--) {
    s = str[i];
    str[i] = str[j];
    str[j] = s;
  }
}
/**
 * 去除中间空格
 **/
void compact(char* s) {
  if (s == NULL || *s == '\0') return s;
  int i = 0, p = 0;
  bool pre_space = false;  //上一个字符是空格
  do {
    if (!(s[i] == ' ' && pre_space)) {
      s[p++] = s[i];
      pre_space = (s[i] == ' ');
    }
  } while (s[i++] != '\0');
}
/**
 * 去除尾部空格
 **/
void trim(char* s) {
  int p = strlen(s) - 1;
  while (p >= 0 && s[p] == ' ') {
    s[p--] = '\0';
  }
}
char* reverseWords(char* s) {
  trim(s);  //除去尾部空格
  int i, p, len = strlen(s);
  if (s == NULL || len < 2) return s;
  reverse(s, 0, len - 1);                  //整体反转
  for (i = 0, p = 0; s[i] != '\0'; i++) {  //逐个单词反转
    if (s[i] == ' ') {
      reverse(s, p, i - 1);
      p = i + 1;
    }
  }
  reverse(s, p, i - 1);  //反转最后一个单词
  compact(s);            //去除中间空格
  trim(s);               //首部空格反转后在尾部，再次去除尾部空格
  return s;
}
```