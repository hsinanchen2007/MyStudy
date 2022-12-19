### 解题思路
递归思路，将n分两个n/2，如果能整出，即n%2==0，则将两个结果相乘之后返回

如果不能整除，即n%2==1，则将两个结果相乘并乘上X返回

### 代码

```java
class Solution{
    public double myPow(double x, int n) {
        long N=n;
        if(N<0)
        {
            N=-N;
            x=1/x;
        }
        return helper(x,N);
    }
    public double helper(double x, long N)
    {
        if(x==1)
            return 1.0;
        if(N==0)
            return 1.0;
        double temp=helper(x,N/2);
        if(N%2==0)
        {
            return temp*temp;
        }
        else
            return temp*temp*x;

    }
}

```