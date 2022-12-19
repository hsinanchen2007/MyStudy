### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int NumWays(int n) {
        int a=1,b=1,sum;
        for(int i=0;i<n;i++){
            sum = (a+b)%1000000007;
            a=b;
            b=sum;
        }
        return a;
    }
}
```