### 解题思路
遍历一次求出环形总距离，两站之间的一个半环距离，总站距离减去半环距离为另一个半环距离，返回两个半环距离较小的即可。

### 代码

```java
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        if(distance==null||distance.length==0){
            return 0;
        }
        int sum=0;
        int dis=0;
        for(int i=0;i<distance.length;i++){
            sum+=distance[i];
            if(i>=Math.min(start,destination)&&i<Math.max(start,destination)){
                dis+=distance[i];
            }
        }
        return Math.min(dis,sum-dis);
    }
}
```