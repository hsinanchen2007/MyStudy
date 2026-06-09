双指针，原地交换位置
```
for (int i = 0, j = s.length - 1; i < j; i++, j--) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}
```
