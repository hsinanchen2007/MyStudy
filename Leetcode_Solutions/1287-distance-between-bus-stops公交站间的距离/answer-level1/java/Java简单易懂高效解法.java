
![屏幕快照 2020-01-04 上午10.52.16.png](https://pic.leetcode-cn.com/b507a10614acb1d8a213686ceff7307e358d34b156e700c34f6c8585d8915611-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-01-04%20%E4%B8%8A%E5%8D%8810.52.16.png)


### 解题思路
求两点之间的距离就只有两种方式，一种是从 start 到 destination，另一种是从 destination 到 start。
求两者的较小者即可。

### 代码

```java
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        // 记录从 start 到 destination 的距离
        int len1 = 0;
        // 记录从 destination 到 start 的距离
        int len2 = 0;
        int cur1 = start;
        int cur2 = destination;
        while(cur1 != destination) {
            // 进行记录
            len1 += distance[cur1];
            // 更新起点
            cur1 = (cur1 + 1) % distance.length;
        }
        while(cur2 != start) {
            // 进行记录
            len2 += distance[cur2];
            // 更新起点
            cur2 = (cur2 + 1) % distance.length;
        }
        return Math.min(len1, len2);
    }
}
```