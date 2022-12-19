执行用时 :
4 ms
, 在所有 c 提交中击败了
64.47%
的用户
内存消耗 :
6.8 MB
, 在所有 c 提交中击败了
100.00%
的用户

int tribonacci(int n){
    int a=0,b=1,c=1;
    int sum=0;
     if(n==0){
         return 0;
     }
    else if(n==1||n==2){
        return 1;
    }
    else{
        for(int i=3;i<=n;i++){
            sum=a+b+c;
            a=b;
            b=c;
            c=sum;
        }
    }
    return sum;
}
