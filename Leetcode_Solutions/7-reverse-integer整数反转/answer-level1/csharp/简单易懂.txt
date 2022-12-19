### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int Reverse(int x) {
        long y=x%10;//不能用int型用例会超出int型范围，导致精度缺失
        while(x/10>0||x/10<0)
        {
            x=x/10;
            y=y*10+x%10;
        }
        if(y>int.MaxValue||y<int.MinValue)
        return 0;
        else
        return (int) y;
    }
}
```