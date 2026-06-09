### 解题思路
![未命名.png](https://pic.leetcode-cn.com/5520cd31c8e54c52e10794ea2c7c2c736440e5ec56a886e48b7941e385d02780-%E6%9C%AA%E5%91%BD%E5%90%8D.png)
可以觀察官方給的示意圖發現，兩個點之間的最短秒數為兩點座標`x軸相減`或`y軸相減`的最大值，如此一來只需要使用一次for迴圈便能取得最終需要的秒數

### 代码

```csharp
public class Solution {
    public int MinTimeToVisitAllPoints(int[][] points) {
        int totalTime = 0;
        for (int i = 0; i < points.Length - 1; ++i)
        {
            int t1 = Math.Abs(points[i][0] - points[i + 1][0]);
            int t2 = Math.Abs(points[i][1] - points[i + 1][1]);
            totalTime += (t1 > t2) ? t1 : t2;                                            
        }
        return totalTime;
    }
}
```