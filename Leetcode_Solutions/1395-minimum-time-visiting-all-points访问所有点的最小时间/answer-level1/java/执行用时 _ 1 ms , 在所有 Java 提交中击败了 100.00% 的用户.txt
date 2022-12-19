### 解题思路
此处撰写解题思路
### 代码

```java
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int summ=0;
        for(int i=0;i<points.length-1;i++) {
        	int x=0,y=0,sum=0;
        	x=Math.abs(points[i+1][0]-points[i][0]);
        	y=Math.abs(points[i+1][1]-points[i][1]);
        	sum=Math.abs(x-y);
        	sum+=x>y?y:x;
        	summ+=sum;
        }
		
		return summ;
    }
}
```