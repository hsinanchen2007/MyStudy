### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int count=0;
		for(int i=1;i<points.length;i++) {
			int temp=0;
			while(points[i-1][0]!=points[i][0]&&points[i-1][1]!=points[i][1]) {
				if(points[i][0]>points[i-1][0]) {
					points[i-1][0]++;
				}
				if(points[i][0]<points[i-1][0]) {
					points[i-1][0]--;
				}
				if(points[i][1]>points[i-1][1]) {
					points[i-1][1]++;
				}
				if(points[i][1]<points[i-1][1]) {
					points[i-1][1]--;
				}
				temp++;
			}
			if(points[i-1][0]==points[i][0]) {
				count+=temp+Math.abs(points[i][1]-points[i-1][1]);
			}
			else if(points[i-1][1]==points[i][1]) {
				count+=temp+Math.abs(points[i][0]-points[i-1][0]);
			}
		}
		return count;
    }
}
```