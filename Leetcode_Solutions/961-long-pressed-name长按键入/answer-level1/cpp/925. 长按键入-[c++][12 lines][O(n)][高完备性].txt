能应付各种奇怪的 case:

```c
   "", "abc"
"abc", ""
"abc", "abbec"
```

```c++
bool isLongPressedName(string name, string typed) {
    int i = 0, j = 0;
    char last = 0;
    while (j != typed.length()) {
        if (i != name.length() && name[i] == typed[j]) {
            last = typed[j];
            ++i;
            ++j;
        } else if (typed[j] == last) {
            ++j;
        } else break;
    }
    return i == name.length() && j == typed.length();
}
```
