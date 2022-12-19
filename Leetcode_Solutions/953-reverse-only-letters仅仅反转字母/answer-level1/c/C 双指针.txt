执行用时 :
0 ms
, 在所有 C 提交中击败了
100.00%
的用户
内存消耗 :
5.1 MB
, 在所有 C 提交中击败了
100.00%
的用户
```
char * reverseOnlyLetters(char * S){
    int j = strlen(S)-1, i = 0;
    char tmp;
    while(i<j){
        if(!((*(S+i)<='Z' && *(S+i)>='A')||(*(S+i)<='z' && *(S+i)>='a'))){
            i++;
        }else if(!((*(S+j)<='Z' && *(S+j)>='A')||(*(S+j)<='z' && *(S+j)>='a'))){
            j--;
        }else{
            tmp = *(S+i);
            *(S+i) = *(S+j);
            *(S+j) = tmp;
            i++;
            j--;
        }
    }
    return S;
}
```
