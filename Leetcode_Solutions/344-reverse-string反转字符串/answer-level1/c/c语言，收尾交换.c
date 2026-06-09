### 解题思路
此处撰写解题思路

### 代码

```c
void reverseString(char* s, int sSize){
    int j=0;
    for(j=0;j<sSize/2;j++)
    {
        char tmp;
        tmp=s[sSize-1-j];
        s[sSize-1-j]=s[j];
        s[j]=tmp;

    }
    
}
```