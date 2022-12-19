### 解题思路
执行用时 :
0 ms
, 在所有 C 提交中击败了
100.00%
的用户
内存消耗 :
5.5 MB
, 在所有 C 提交中击败了
100.00%
的用户

### 代码

```c
char * addBinary(char * a, char * b){
    int i,j,n;
    int sig=0;
    for(i=0;*a!='\0';i++,a++);
    for(j=0;*b!='\0';j++,b++);
    a--;b--;
    int max=i>=j?i:j;
    char *arr=(char*)malloc((max+2)*sizeof(char));
    arr[max+1]='\0';
    while(1){
        if(i==0&&j!=0){
            n=*b-'0'+sig;
        }
        else if(j==0&&i!=0){
            n=*a-'0'+sig;
        }
        else if(i==0&&j==0){
            if(sig==1){
                arr[max]='1';
            }
            else arr[max]='0';
            break;
        }
        else{
            n=*a-'0'+*b-'0'+sig;
        }
        if(n==0){
            arr[max]='0';
            sig=0;
        }
        else if(n==1){
            arr[max]='1';
            sig=0;
        }
        else if(n==2){
            arr[max]='0';
            sig=1;
        }
        else if(n==3){
            arr[max]='1';
            sig=1;
        }
        if(i!=0) {i--;if(i!=0) a--;}
        if(j!=0) {j--;if(j!=0) b--;}
        if(max!=0) max--;
    }
    if(arr[0]=='0') return arr+1;
    else return arr;
}
```