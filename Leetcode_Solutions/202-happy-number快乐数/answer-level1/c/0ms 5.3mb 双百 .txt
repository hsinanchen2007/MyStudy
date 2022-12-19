### 解题思路
其实就像快慢指针检验链表是否有环一样。。。好的我承认e我看了评论区

### 代码

```c
int getSum(int n){
    int sum=0,temp=0;
    while(n>0){
        temp=n%10;
        sum+=temp*temp;
        n/=10;
    }
    return sum;
}
bool isHappy(int n){
    int a=getSum(n);
    int b=getSum(a);
    if(a==1||b==1){
        return true;
    }
    while(a!=b){
        a=getSum(a);
        b=getSum(b);
        b=getSum(b);
        if(a==1||b==1){
            return true;
        }
    }
    return false;
}
```