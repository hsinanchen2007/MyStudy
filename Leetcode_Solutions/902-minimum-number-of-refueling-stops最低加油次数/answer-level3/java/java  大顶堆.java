### 解题思路
思路其实很简单，遍历加油站，使用大顶堆保存已经遍历的加油站的油，如果当前汽车中的油不足以到达当前加油站，则取堆顶加油，直到足够，如果堆空了还是不够，return -1

### 代码

```java
class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        //构造大顶堆
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->(b-a));
        //加油次数
        int res = 0;
        //当前车中的油
        int sum = startFuel;
        
        for(int i=0 ; i<stations.length ; i++){
            if(sum<stations[i][0]){//车中油不足以到达加油站
                //取堆顶的油加入到车中
                while(!pq.isEmpty() && sum<stations[i][0]){
                    sum += pq.poll();
                    ++res;
                }
                //不够，到达不了
                if(sum<stations[i][0]){
                    return -1;
                }
                
            }
            pq.offer(stations[i][1]);
        }
        //判断是否能到达目的地
        while(!pq.isEmpty() && sum<target){
            sum += pq.poll();
            ++res;
        }
        if(sum<target){
            return -1;
        }
        
        return res;
    }
}
```