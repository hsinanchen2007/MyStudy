### 解题思路
取绝对值Math.abs()

### 代码

```java
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
int length=0,wide=0,time=0;
for(int i=0;i<points.length-1;i++){
    length=Math.abs(points[i+1][0]-points[i][0]);
    wide=Math.abs(points[i+1][1]-points[i][1]);
    if(length>wide){
       time+=length;  
    }else{
        time+=wide;
    }
   
}
return time;
    }
}
```