### 解题思路
题意：一个回旋镖由三个点组成，每个点由平面坐标(x,y)表示，如果某个点到另外两个点的距离相等，则这三个点可以组成回旋镖，不妨称这个点为中心点。这三个点不仅可以组成回旋镖，还可以组成两个，因为中心点固定，另外两个点的位置可互换。
由上，可确定思路为两层循环，对每个中心点，遍历所有其他点，找与中心点距离相同的点，用哈希表记录到中心点的距离，以及满足这个距离的点的个数。
**对于一个中心点，每找到一个到它距离相同的其他点，可以新增的回旋镖数量为：之前已满足该距离的点的个数乘2。**

时间复杂度：O(n*n)。两重循环。
空间复杂度：O(n)。哈希表大小最大需要存放n个点的距离。

### 代码

```java
class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int sum = 0;
        int n = points.length;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)  continue;
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dis = (int) (Math.pow((x1-x2), 2) + Math.pow((y1-y2), 2));
                if(map.containsKey(dis))
                {
                    int times = map.get(dis);
                    sum += 2 * times;
                    map.put(dis, times+1);
                }
                else    map.put(dis, 1);
            }
            map.clear();
        }
        return sum;
    }
}
```