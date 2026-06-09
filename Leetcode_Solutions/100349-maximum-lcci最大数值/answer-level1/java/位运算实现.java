求a与b最大值
首先求a+b，a-b,
那么max(a,b)=((a+b)+abs(a-b))/2.
abs(a-b)=(a-b)*(a-b<0?-1:1);
a-b如果小于0，那么首位为1，反之为0.
根据a-b首位使用位运算实现1和-1.
令c=a-b
c<0时:1-(1<<(c>>63))+(1>>(c>>63))=-1
c>0时:1-(1<<(c>>63))+(1>>(c>>63))=1
代码实现:
```
    public int maximum(int a, int b) {
        long sum=(long)a+b;
        long diff=(long)a-b;
        sum=sum+(1-(1<<(diff>>>63))+(1>>(diff>>>63)))*diff;
        return (int)(sum/2);
    }
```
