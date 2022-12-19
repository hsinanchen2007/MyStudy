### 解题思路
定义一个count计数，假设在10000次内循环结束是快乐数，否则不是快乐数。
也许可以证明快乐数可以在10000次循环内判断出来。

### 代码

```c
bool isHappy(int n){
    int s=n,sum=0;;
    int temp;
    int count = 0;

    while(n!=1){     
        while(s!=0){
            temp=s % 10;
            sum += temp*temp;
            s /= 10;
        }
        s=n=sum;
        sum=0;
        count++;
        if(count>10000)return false;
    }
    return true;
}
```