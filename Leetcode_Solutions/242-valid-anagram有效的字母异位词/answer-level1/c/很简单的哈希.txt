观察题目可以发现，输入有两种情况：

1. 长度不相等
2. 长度相等


## 长度不相等

很简单，直接返回false。

## 长度相等

对第一个字符串扫描，将出现的字母存储哈希表，例如使其值加1。扫描第二个字符串，将出现的字母减1。最后扫描整个哈希表，如果第一个字符串的字母与第二个字符串的字母相互抵消了，说明是字母异位词，否则不是。

```
bool isAnagram(char * s, char * t)
{
    int len_s = strlen(s);
    int len_t = strlen(t);

    // 特殊情况
    if (len_s != len_t) return false;

    int map[26] = {0};
    int i;

    for (i = 0; i < len_s; i++) map[s[i]-'a']++;
    for (i = 0; i < len_t; i++) map[t[i]-'a']--;

    for (i = 0; i < 26; i++) {
        if (map[i]) return false;
    }

    return true;
}
```

