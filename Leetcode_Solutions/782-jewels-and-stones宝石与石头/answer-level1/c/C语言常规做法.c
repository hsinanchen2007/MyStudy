```c
int numJewelsInStones(char * J, char * S){
    int count=0,i=0,j=0,len=0;
    while(S[len]!=0) len++;
    while(J[i]!=0){
        for(j=0;j<len;j++)
            if(S[j]==J[i]) count++;
        i++;
    }
    return count;
}
```
此方法中，不需要通过while循环求J的长度，再通过for循环遍历，而对S则需要先求长度，否则每次遍历都需要比较S[j]与'\0'，浪费时间。