### 解题思路
此处撰写解题思路

### 代码

```c
void reverseString(char* s, int sSize){
    int i;
    char *x=NULL;

    for(i=0;i<sSize/2;i++){
        x=*(s+i);
        *(s+i)=*(s+sSize-1-i);
        *(s+sSize-i-1)=x;
    }
}
```