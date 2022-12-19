### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int Reverse(int x) {
    long y=x%10;//不能用int型用例会超出int型范围，导致精度缺失
        long returnValue = 0;
        bool isFS = x>-1;
        if(!isFS)
        {
            x = -x;
        }
        while(x!= 0)
        {
            returnValue = returnValue*10 + x%10;
            x = x/10;
        }
        if(!isFS)
        {
            returnValue = -returnValue;
        }
        if(returnValue>Int32.MaxValue || returnValue < Int32.MinValue)
        {
            return 0;
        }
        return (int)returnValue;
    }
}
```