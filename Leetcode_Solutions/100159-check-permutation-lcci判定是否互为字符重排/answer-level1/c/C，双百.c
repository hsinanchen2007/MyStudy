将2个字符串出现过的字符分别在2个空间中标记，结束后将2个空间进行比较可得结果。

执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :6.7 MB, 在所有 C 提交中击败了100.00%的用户
```
bool CheckPermutation(char* s1, char* s2){
    int l1=strlen(s1),l2=strlen(s2);
    if(l1!=l2||l1==0||l2==0)
    return 0;
    char a[256],b[256];
    memset(a,'1',sizeof(a)-1);
    memset(b,'1',sizeof(b)-1);
    for(int i=0;i<l1;i++){
        a[128+s1[i]]++;
        b[128+s2[i]]++;
    }
    if(strcmp(a,b)==0)
    return 1;
    else
    return 0;
}
```
