### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public bool CanMeasureWater(int x, int y, int z) {
        if(x+y<z) return false;
        if(x==0||y==0) return z == 0 || x + y == z;
        int n = GCD(x,y);
        return z%n==0 ? true : false;
    }

    public int GCD(int a,int b)
    {
        if(a%b==0)
            return b;
        else
        {
            return GCD(b,a%b);
        }
    }
}


```