### 解题思路
此处撰写解题思路

### 代码

```c
int numJewelsInStones(char * J, char * S){
int m=strlen(J);
int n=strlen(S);
int i,j,count=0;
for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        if(J[i]==S[j])
        count++;
    }
}
return count;
}
```