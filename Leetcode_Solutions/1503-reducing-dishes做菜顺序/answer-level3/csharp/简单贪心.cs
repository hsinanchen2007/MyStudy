### 解题思路
局部最优解
从大到小排序 sat
sat前缀和
每多一道菜 加一次前缀和


### 代码

```csharp
class DishOrder {
    public int MaxSatisfaction(int[] satisfaction) {
        //TimeSum * Love Sum  Max
        //Order Choose
        //Max = WIth Dish WithOutDish 
        //TimeCount
        Array.Sort(satisfaction, (a, b) =>
        {
            return b - a;
        });
        //sati >= 0 Just Use All Greatest Last
        //sati >= 0 
        //< 0  1*neg + SumAll
        var prefixSum = new List<int>();
        var snow = 0;
        for (var i = 0; i < satisfaction.Length; i++){
            snow += satisfaction[i];
            prefixSum.Add(snow);
        }
        var totalSum = 0;
        for (var i = 0; i < satisfaction.Length; i++){
            var sv = satisfaction[i];
            if(sv >= 0){
                totalSum += prefixSum[i];
            }else {
                if(prefixSum[i] >= 0){
                    totalSum += prefixSum[i];
                }else break;
            }
        }
        return totalSum;
    }
    // static void Main(string[] arg) { 
    //     var dor = new DishOrder();
    //     // var r = dor.MaxSatisfaction(new int[] { -1, -8, 0, 5, -9 });
    //     // var r = dor.MaxSatisfaction(new int[] { });
    //     // var r = dor.MaxSatisfaction(new int[] { 4,3,2});
    //     // var r = dor.MaxSatisfaction(new int[] { -1,-4,-5});
    //     var r = dor.MaxSatisfaction(new int[] {-2,5,-1,0,3,-3 });
    //     Console.WriteLine(r);

    // }
}
public class Solution {
    public int MaxSatisfaction(int[] satisfaction) {
        var dor = new DishOrder();
        return dor.MaxSatisfaction(satisfaction);
    }
}
```