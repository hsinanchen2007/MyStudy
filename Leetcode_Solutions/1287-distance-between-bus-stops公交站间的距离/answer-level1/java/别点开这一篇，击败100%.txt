### 解题思路
本质就是求start 到 destination区间first 与 剩下元素和secode的大小 
### 代码

```java
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {

        if(start == destination) return 0;

        if(start > destination){
            int temp = start;
            start = destination;
            destination = temp;
        }

        int first = 0, second = 0;
        for(int i = 0; i < distance.length; i++){
            if(i >= start && i < destination){
                first += distance[i];
            } else{
                second += distance[i];
            }
        }
        return first > second ? second : first;
    }
}
```