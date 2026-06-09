l和r分别记录未匹配的左右括号个数，时间复杂度O(n)。
```
int getBranket(char* S,int l,int r){
    if(*S=='\0') return l+r;
    if(*S=='(') return getBranket(S+1,l+1,r);
    if(*S==')') return l==0?getBranket(S+1,l,r+1):getBranket(S+1,l-1,r);
    return getBranket(S+1,l,r);
}
int minAddToMakeValid(char * S){
    return getBranket(S,0,0);
}
```
