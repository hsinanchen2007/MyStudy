### 解题思路
先判断start和destination的大小，然后计算路径，因为是环形线路，所以用总路径减去当前路径再和当前计算的路径进行比较。

### 代码

```java
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        if(start > destination){
            //--> 0-3和3-0路径相等
            return distanceBetweenBusStops(distance,destination,start);
        }
        int sum = 0, curSum = 0;  //sum为总路径，curSum为当前计算路径
        for(int n : distance){
            sum +=n;   
        }
        for(int i = start;i < destination;i++){
            curSum += distance[i];
        }
        return Math.min(curSum , sum - curSum);   //返回最小路径
    }
}
```