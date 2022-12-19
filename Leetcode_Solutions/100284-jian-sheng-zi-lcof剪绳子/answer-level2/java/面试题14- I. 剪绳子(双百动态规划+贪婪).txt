### 解题思路
分解问题，至上而下，将长度为n的分成m段，第一刀可以将第一段分成长度为:1,2,3,...,n-1，即f(n)=f(n-i)*f(i);
其中f(i)表示长度为i的最大乘积。
故至下而上，f(1)=1;f(2)=2;f(3)=3;此处需要注意，f(3)指的是剪完第一刀后剩余长度的最大乘积，而不是长度为3的最大乘积（长度为3的最大乘积是2，分为两段1，2），这里需要非常注意，很容易搞混。
然后根据规律嵌套循环即可，注意内层循环求得是最大乘积的可能，因此只需要<=i/2即可。

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        if(n==2)return 1;
        if(n==3)return 2;
        int[] f=new int[n+1];
        f[1]=1;
        f[2]=2;
        f[3]=3;
        int MAX=0;
        for (int i=4;i<=n;i++){
            int max=0;
            for (int j=1;j<=i/2;j++){
                int item=f[j]*f[i-j];
                if(item>max){
                    max=item;
                }
                f[i]=max;
            }
        }
        MAX=f[n];
        return MAX;
    }
}
```
**贪婪算法**
只要>=5开始就不断剪3，除非剩余长度为4就分成2*2.
```
class Solution {
    public int cuttingRope(int n) {
        if(n==2)return 1;
        if(n==3)return 2;
        int timesThr=n/3;
        if(n-timesThr*3==1){
            timesThr=timesThr-1;
        }
        int timesTwo=(n-timesThr*3)/2;
        return (int)(Math.pow(3,timesThr))*(int)(Math.pow(2,timesTwo));
    }
}
```
