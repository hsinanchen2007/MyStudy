### 解题思路
2n 个排列
交换顺序 确保 P 在 D 前面

### 代码

```csharp
class Delivery{
    private const UInt64 ModV = 1000000000+7;
    public int CountOrders(int n) {
        UInt64 totalN = (UInt64)n * 2;
        UInt64 jieCheng = 1;
        var k2 = 0;
        for (UInt64 i = 1; i <= totalN; i++){
            jieCheng *= i;
            if(((i % 2) == 0) && (k2 < n)){
                jieCheng /= 2;
                k2++;
            }
            jieCheng %= ModV;
        }
        return (int)jieCheng;
    }

    // static void Main(string[] arg)
    // {
    //     var d = new Delivery();
    //     var r = d.CountOrders(3);
    //     Console.WriteLine(r);
    // }
}
public class Solution {
    public int CountOrders(int n) {
         var d = new Delivery();
        return d.CountOrders(n);
    }
}
```