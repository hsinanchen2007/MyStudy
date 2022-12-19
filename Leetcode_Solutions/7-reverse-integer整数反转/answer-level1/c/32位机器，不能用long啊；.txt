### 解题思路
用数组把每位数字存起来，然后再判断

### 代码

```c
int rev(int n){
    int ans=0;
    if(n<0){
        n=-n;
        while(n!=0){
            ans=10*ans+n%10;
            n/=10;
        }
        ans=-ans;
    }
    else{
        while(n!=0){
            ans=10*ans+n%10;
            n/=10;
        }
    }
    return ans;
}
int reverse(int x){
    int n=x,i,ans,m=0;
    int array[20]={0};
    for(i=19;n!=0;i--){
        array[i]=n%10;
        n/=10;
    }
    for(i=0;array[i]==0&&i<19;i++);
    if((20-i)>10)   return 0;
    if((20-i)==10){
        for(i=19;i>10;i--){
            m=10*m+array[i];
        }
        if(m>214748364||m<-214748364) return 0;
    }
    ans=rev(x);
    return ans;
}
```