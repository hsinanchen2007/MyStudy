### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int x = Math.min(start, destination);
        int y = Math.max(start, destination);
        int sum=0;
        for(int i=0;i<distance.length;i++) {
        	sum+=distance[i];
        }
        int num=0;
        for(int i=x;i<y;i++) {
        	num+=distance[i];
        }
        return Math.min(sum-num, num);
    }
}
```