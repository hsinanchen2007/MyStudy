### 解题思路
此处撰写解题思路

### 代码

```c
void reverseString(char* s, int sSize){
    int i=0,j=sSize-1;
    char temp;
    while(i<j){
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
}
```