### 解题思路
此代码速度很烂
注意点：求绝对值跟java比较像
求两个数的最大值`Math.Max(a,b)`;
Math不能少
### 代码

```csharp
public class Solution {
    public int MinTimeToVisitAllPoints(int[][] points) {
            int[] cur = points[0];
            int res = 0;
        for(int i = 1;i<points.Length;i++){
                res+=Math.Max(Math.Abs(points[i][0]-cur[0]),Math.Abs(points[i][1]-cur[1]));
                cur = points[i];
        }
            return res;
    }
}
```