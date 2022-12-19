执行用时 :0 ms  , 在所有 C 提交中击败了100.00%的用户
内存消耗 :6.7 MB, 在所有 C 提交中击败了26.67%的用户
```
int clumsy(int N){
static char a[4] = {1, 2, 2, -1};
      if(N > 4)   return N + a[N%4];
else  if(N > 2)   return N + 3     ;
else              return N         ;
}
```
