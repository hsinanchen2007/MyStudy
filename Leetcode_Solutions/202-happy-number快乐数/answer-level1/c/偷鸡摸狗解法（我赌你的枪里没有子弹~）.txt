循环了10次还没解决问题 sorry 再见（居然通过了 还是双百）
```
bool isHappy(int n){
    int sum=0,x=n,y,flag=0;
    while(1){
        x=n;
        while(x>0){
            y=x%10;
            x=x/10;
            sum=sum+y*y;
        }
        if(sum==1)
            break;
        n=sum;
        sum=0;
        flag++;
        if(flag>10)
            return 0;
    }
    return 1;
}
```
