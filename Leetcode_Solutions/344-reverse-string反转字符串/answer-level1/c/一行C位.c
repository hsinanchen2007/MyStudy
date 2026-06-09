### 解题思路
头尾交换，双指针

### 代码

```c
void reverseString(char* s, int sSize){
    for(int i=0;i<sSize;i++){char temp = s[--sSize];s[sSize] = s[i];s[i] = temp;}
}
```