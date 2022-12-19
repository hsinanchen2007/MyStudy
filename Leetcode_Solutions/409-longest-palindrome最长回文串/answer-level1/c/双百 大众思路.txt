### 解题思路
此处撰写解题思路

### 代码

```c
int longestPalindrome(char * s){
    int logs[63]={0},count=0,single=0;
    while(*s){
        logs[*s-60]++;
        s++;
    }
    for(int i=5;i<63;i++){
        if(logs[i]%2==0) count+=logs[i];
        else {
            count+=logs[i]-1;
            single=1;
        }
    }  
    return count+single;
}
```