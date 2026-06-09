执行用时 :
0 ms
, 在所有 C 提交中击败了
100.00%
的用户
内存消耗 :
7.3 MB
, 在所有 C 提交中击败了
82.81%
的用户
```
int calPoints(char ** ops, int opsSize){
    int n=0;
    int a[1000]={0};
    int sum=0;
    for(int i=0;i<opsSize;i++)
        if(ops[i][0]=='C'){
            n--;
            sum-=a[n];
        }
        else if(ops[i][0]=='D'){
            sum+=a[n-1]*2;
            a[n]=a[n-1]*2;
            n++;
        }
        else if(ops[i][0]=='+'){
            a[n]=a[n-1]+a[n-2];
            sum+=a[n];
            n++;
        }
        else if(ops[i][0]=='-'){
            int p=0;
            for(int j=1;j<strlen(ops[i]);j++){
                p*=10;
                p+=ops[i][j]-'0';
            }
            sum-=p;
            a[n++]=-p;
        }
        else{
            int p=0;
            for(int j=0;j<strlen(ops[i]);j++){
                p*=10;
                p+=ops[i][j]-'0';
            }
            sum+=p;
            a[n++]=p;
        }
    return sum;
}
```
