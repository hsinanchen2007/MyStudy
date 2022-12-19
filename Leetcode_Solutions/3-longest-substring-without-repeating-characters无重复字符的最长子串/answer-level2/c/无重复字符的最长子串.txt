### 解题思路
执行用时 :8 ms, 在所有 C 提交中击败了68.82%的用户
内存消耗 :5.5 MB, 在所有 C 提交中击败了100.00%的用户
### 代码

```c
int lengthOfLongestSubstring(char * s){
    int len=strlen(s);
    char set[97];
    int max=0,j=0,i=0;
    memset(set,0,sizeof(char)*97);
    for(i=0;i<len;i++){
        for(j=j;j<len;j++){
            if(set[(int)s[j]-32]!=0){
                set[(int)s[i]-32]=0;
                break;
            }
            else{
                set[(int)s[j]-32]=1;
                (j-i+1)>max?(max=j-i+1):(NULL); 
            }
        }
    }
    return max;
}
```