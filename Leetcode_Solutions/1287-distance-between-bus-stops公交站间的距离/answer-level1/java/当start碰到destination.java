### 解题思路
+ 无论正向走逆向走，走完刚好是一圈
+ 数组相加是一圈的距离，减去单次（正向/你想）的距离，即可比较大小
+ 单次距离是 start 碰到 destination 的距离
+ 从start出发一路走下去，只到遇到destination 结束


### 代码

```java
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int all = 0;
        for (int i=0;i<distance.length;i++){
            all += distance[i];
        }
        int d = 0;
        while (start !=destination){
            d += distance[start++];
            if (start > (distance.length - 1)){
                start = 0;
            }
        }
        return Math.min(d,all-d);
    }
}
```