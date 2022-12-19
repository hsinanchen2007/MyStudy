### 解题思路
    使用最常规的遍历思路即可，首先计算从左边到右边的正向的距离，然后计算从右边到边缘然后循环回到顶点的距离，比较两个距离的大小即可。

### 代码

```java
class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
         int left=start<destination? start:destination;
	     int right=start<destination? destination:start;
	     int des1=0;
	     int des2=0;
	     if(left==right) return 0;
	     for(int i=left;i<right;i++)
	     {
	    	 des1+=distance[i];
	     }
	     for(int i=right;i<distance.length;i++)
	     {
	    	 des2+=distance[i];
	     }
	     for(int i=0;i<left;i++)
	     {
	    	 des2+=distance[i];
	     }
	     return des1<=des2? des1:des2;
    }
}
```