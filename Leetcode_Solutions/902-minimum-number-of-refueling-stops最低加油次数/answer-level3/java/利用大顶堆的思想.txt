### 解题思路
汽车每经过一个加油站时，先不加油，把加油站的油量用大顶堆存储下来。
当汽车当前的油量不足以前往下一个加油站时，就从大顶堆中取出堆顶元素，继续前进。
若某时刻，大顶堆中的元素取完仍到达不了目的地，则表示无法到达。

### 代码

```java
class Solution {
   public int minRefuelStops(int target, int startFuel, int[][] stations) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> o2-o1);
        int current = 0;
        int times = 0;
        for (int i = 0;i < stations.length; i++){
            if (startFuel >= stations[i][0] - current){
                startFuel -= stations[i][0] - current;
                pq.add(stations[i][1]);
                current = stations[i][0];
            }
            else {
                //当前油量不足以支撑前往下一个加油站
                if (pq.isEmpty())
                    return -1;
                else {
                    Integer remove = pq.remove();
                    startFuel += remove;
                    times++;
                    i--;
                }
            }
        }
        if (startFuel >= target - current)
            return times;
        while (!pq.isEmpty()){
            startFuel += pq.remove();
            times++;
            if (startFuel >= target - current)
                return times;
        }
        return -1;
    }
}
```