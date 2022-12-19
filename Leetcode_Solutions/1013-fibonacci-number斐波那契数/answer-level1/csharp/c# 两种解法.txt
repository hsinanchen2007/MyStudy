### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    //黄金比例计算，理论明白了soeasy
    public int Fib(int N) {
        double goldenRatio=(1+Math.Sqrt(5))/2;
        return (int)Math.Round(Math.Pow(goldenRatio,N)/Math.Sqrt(5));
    }

    //直接法
    public int Fib(int N) {
        int a=0;int b=1;
        if(N==0)
        {
            return 0;
        }
        else if(N==1)
        {
            return 1;
        }
        else
        {
            for(int i=2;i<=N;i++)
            {
                int temp=b;
                b=b+a;
                a=temp;
            }
        }    
        return b;
    }
}
```