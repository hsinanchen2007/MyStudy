####  一次遍历，统计出现次数
- 使用 52 个大小的数组，大写字母用后26个，小写字母用前26个
- 避免重复调用 `strlen()` 手动保存字符串长度

```cpp
    int flags[52] = {0};
    int strLen = 0;
    for (; s[strLen] != '\0'; ++strLen) {
        int index = isupper(s[strLen]) ? s[strLen] -'A' + 26 : s[strLen] - 'a';
        flags[index]++;
    }
```

#### 二次遍历，确定回文串长度
- 避免奇数被直接记数，在除法两边加括号
- 最后比较，若比原字符串短，必有出现次数为奇数的字母，加 `1` 即可

```cpp
    int len = 0;
    for (int i = 0; i < 52; ++i)
        len += 2 * (flags[i]/2);
    len += len < strLen ? 1 : 0;    
```