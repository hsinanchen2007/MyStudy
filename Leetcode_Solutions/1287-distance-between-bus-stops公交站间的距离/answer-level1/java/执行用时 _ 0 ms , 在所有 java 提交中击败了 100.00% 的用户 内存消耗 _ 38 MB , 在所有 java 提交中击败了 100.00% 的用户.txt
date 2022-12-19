思想：总共只有两条路，算出一条，另一条直接用整个环的距离减去第一条即可
      起点到终点 与终点到起点 无非是前者正序累加，后者逆序累加的问题
      当起点大于终点时进行交换，确保只利用正序累加  

```
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int sum =0;//整个环的总距离
        int res = 0;
        int one = 0;//记录第一条路线
        for(int d :distance)
            sum += d;
        if(start > destination){//确保起始点小于目的地
            int temp = destination;
            destination = start;
            start = temp;
        }
        for(int i = start;i<destination;i++)
            one += distance[i];
        int other = sum -one;
        res = Math.min(one,other);
        return res;
    }
}
```
