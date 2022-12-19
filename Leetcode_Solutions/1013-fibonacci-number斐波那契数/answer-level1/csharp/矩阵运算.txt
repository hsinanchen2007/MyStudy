### 解题思路
矩阵运算实现

### 代码

```csharp
public class Solution {
    public int Fib(int N) {
        return Fn(N);
    }

    private int Fn(int n)
    {
        if(n==0)
        {
            return 0;
        }
        int [,] a=new int[,]{{1,1,},{1,0}};
        int [,] b=MatirxPower(a,n);
        return b[1,0];
    }

    private int[,] MatirxPower(int[,] a,int n)
    {
        if(n==1)
        {
            return a;
        }
        else if(n==2)
        {
            return MatirxMultiplication(a,a);
        }
        else if(n%2==0)
        {
            int[,] temp=MatirxPower(a,n/2);
            return MatirxMultiplication(temp,temp);
        }
        else
        {
            int[,] temp=MatirxPower(a,n/2);
            return MatirxMultiplication(MatirxMultiplication(temp,temp),a);
        }
    }

    private int[,] MatirxMultiplication(int[,] a,int[,] b)
    {
        int[,] c=new int[2,2];
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    c[i,j]+=a[i,k]*b[k,j];
                }
            }
        }
        return c;
    }
}
```