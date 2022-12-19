### 解题思路
此处撰写解题思路

### 代码

```c
void reverseString(char* s, int sSize){
    char save;
    int index,i;
    index = sSize/2;
    for(i = 0; i < index; i++)
    {   save = s[i];
        s[i] = s[sSize-i-1];
        s[sSize-i-1] = save;
    }
}
```