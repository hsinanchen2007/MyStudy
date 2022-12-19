### 解题思路
就是两种大情况，每种大情况又分两种小情况
1、顺时针走
  1.1起始位置在终点后start>destination
  1.2起始位置在终点前start<destination
2、逆时针走(逆时针走时，要用逆向思维就化为顺时针走了，即将终点起点反过来计算，即可)
  1.1起始位置在终点后start>destination
  1.2起始位置在终点前start<destination

### 代码

```java
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int circlrDis=0;//顺时针走
        if(start<destination){
            for(int i=start;i<destination;i++){
                circlrDis=distance[i]+circlrDis;
            }
            
        }
        else{
                for(int i=start;i<distance.length;i++){
                     circlrDis=distance[i]+circlrDis;
                }
                 for(int i=0;i<destination;i++){
                     circlrDis=distance[i]+circlrDis;
                }
            }
        int reCircleDis=0;//逆时针走
        if(start>destination){
            for(int i=destination;i<start;i++){
                reCircleDis=distance[i]+reCircleDis;
            }
            
        }
        else{
                for(int i=destination;i<distance.length;i++){
                     reCircleDis=distance[i]+reCircleDis;
                }
                 for(int i=0;i<start;i++){
                    reCircleDis=distance[i]+reCircleDis;
                }
            }


        return (reCircleDis>circlrDis)?circlrDis:reCircleDis;
    }
}
```