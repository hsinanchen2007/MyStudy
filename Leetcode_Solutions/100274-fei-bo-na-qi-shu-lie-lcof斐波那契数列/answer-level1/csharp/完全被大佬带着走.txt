### 解题思路
依赖递归就死掉，还是向大佬看齐

### 代码

```csharp
public class Solution {
    public int Fib(int n) {
        int a=0,b=1,sum;        
        for(int i=0;i<n;i++){
            sum=(a+b)%1000000007;
            a = b;
            b = sum;
        }
        return a;
    }
}
```