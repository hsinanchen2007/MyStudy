### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int result=0;
        if(start==destination){
            
        }else if(start<destination){
            int r1=0;
            for (int i=start; i<destination;i++){
                r1+=distance[i];
            }
            int r2=0;
            for(int i=0;i<start;i++){
                r2+=distance[i];
            }
            for(int i=destination;i<distance.length;i++){
                r2+=distance[i];
            }
            result=Math.min(r1,r2);
        }else if(start>destination){
            int r1=0;
            for (int i=destination; i<start;i++){
                r1+=distance[i];
            }
            int r2=0;
            for(int i=0;i<destination;i++){
                r2+=distance[i];
            }
            for(int i=start;i<distance.length;i++){
                r2+=distance[i];
            }
            result=Math.min(r1,r2);  
        }
    return result;
    }
}
```