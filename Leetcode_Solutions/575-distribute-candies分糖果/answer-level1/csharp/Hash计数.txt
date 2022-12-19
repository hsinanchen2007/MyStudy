### 解题思路
妹妹最多能拿到的糖果数量是数组长度/2。
计算糖果的种类数量，如果数量小于等于数组长度/2,那么每一种都能拿到，返回糖果种类的数量。否则，就返回数组的长度/2，就一定会有种类重复的糖果

### 代码

```csharp
public class Solution {
    public int DistributeCandies(int[] candies) {
        HashSet<int> temp=new HashSet<int>();
        for(int i=0;i<candies.Length;i++)
        {
            temp.Add(candies[i]);
        }

        if(temp.Count<=candies.Length/2)
        {
            return temp.Count;
        }
        else
        {
            return candies.Length/2;
        }
    }
}
```