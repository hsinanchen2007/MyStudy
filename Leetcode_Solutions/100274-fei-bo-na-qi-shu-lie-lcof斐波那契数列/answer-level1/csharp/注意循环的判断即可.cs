### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int Fib(int n) {
        int Fib = 0;
        int Fib_0 = 0;
        int Fib_1 = 1;
        if(n==0)
            Fib = 0;
        if(n==1)
            Fib = 1;
        for(int i=1;i<n;i++){
            Fib = (Fib_0 + Fib_1)% 1000000007; 
            Fib_0 = Fib_1;
            Fib_1 = Fib;
            
        }                      
        return Fib ;
    }
}



```