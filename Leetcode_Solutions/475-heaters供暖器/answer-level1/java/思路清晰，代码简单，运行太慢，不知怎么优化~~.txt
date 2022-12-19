### 解题思路
1、遍历房间的每一个点，再遍历每一个加热器的位置
2、算出某一个点距离所有加热器的最短距离
3、比较所有点的“最短距离”，找出最大值

### 代码

```java
class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        int distance = 0; //初始化最小值
        for(int i=0; i<houses.length; i++){
            int minForEachPoint = Integer.MAX_VALUE; //某一点与各加热器的值，初始化最大值
            for(int j=0; j<heaters.length; j++){
                int locDistance = Math.abs(houses[i]-heaters[j]); //当前点与供暖器的距离
                //找出当前点与各加热器的最短距离
                if(minForEachPoint>locDistance) minForEachPoint=locDistance; 
            }
            //获取minForEachPoint中的最大值
            if(distance<minForEachPoint) distance=minForEachPoint;
        }
        return distance; 
    }
}
```