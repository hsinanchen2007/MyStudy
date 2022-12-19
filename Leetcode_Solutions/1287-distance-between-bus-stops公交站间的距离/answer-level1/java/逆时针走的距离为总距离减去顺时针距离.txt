### 解题思路


### 代码

```java
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int sDistance = 0;
		int nDistance = 0;
		int totalDis = 0;
        if(start < destination) {
			//顺时针
			for(int i = start;i < destination;i++) {
				sDistance +=distance[i];
			}
			
		}else {
			
			//顺时针
			for(int i = destination;i < start;i++) {
				sDistance +=distance[i];
			}
			
		}
		//总总距离距离
		for(int i=0;i<distance.length;i++) {
			totalDis+=distance[i];
		}
		//逆时针逆时针距离距离
		nDistance = totalDis - sDistance;
		
		int dis = (nDistance - sDistance)>0 ?sDistance :nDistance;
		return dis;

    }
}
```