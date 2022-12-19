### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public bool CanMeasureWater(int x, int y, int z) {

           if (z == 0) return true;//自动满足
            if (x + y < z) return false;//怎么都满足不了

            int big = Math.Max(x, y);//大
            int small = x + y - big;//小

            if (small == 0) return big == z;//x，y相等 满足必须z也相等


            while (big % small != 0) {//辗转相除
                int temp = small;
                small = big % small;
                big = temp;
            }
            return z % small == 0;
    }
}
```