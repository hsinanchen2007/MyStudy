### 解题思路


### 代码

```c
void reverseString(char* s, int sSize){
    int i, temp, x = sSize / 2;
    for (i = 0; i < x; i++)
    {
        temp = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = temp;
    }
    return;
}
```