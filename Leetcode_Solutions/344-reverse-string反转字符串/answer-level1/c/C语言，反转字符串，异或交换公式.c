用位运算异或`^`交换数字，可以节省中间变量，记住公式然后去炫(zhuang)技(b)吧 

```C
void reverseString(char* s, int sSize){
    for (int a = 0, b = sSize-1; a < b; a++, b--){
        s[a] = s[a] ^ s[b];
        s[b] = s[a] ^ s[b];
        s[a] = s[a] ^ s[b];
    }
}
```