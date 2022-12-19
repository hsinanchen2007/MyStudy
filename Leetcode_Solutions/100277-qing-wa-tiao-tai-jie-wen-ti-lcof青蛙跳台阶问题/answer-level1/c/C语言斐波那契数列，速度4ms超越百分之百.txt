int numWays(int n){
int  one =1;
int  two=2;
int  three;
if(n==0){
    return 1;
}
if(n==1){
    return 1;
}
if(n==2){
    return 2;
}
if(n>=3){
    for(int i=3;i<=n;i++){
        three=(one + two)%1000000007;
        one =two;
two=three;
    }
    
}return three;
}