### 解题思路
此处撰写解题思路
首先将二维数组的第一维排序，然后将后面的范围的头与之前的范围的尾部比较，若头比较小，则继续后比，若头比较大，则计数加一，然后将新一轮的范围的尾变成刚刚比较的那个范围的尾部，进行下一轮比较
### 代码

```java
class Solution {
    public int findMinArrowShots(int[][] points) {
        if(points.length==0) return 0;
        Arrays.sort(points,(a,b)->(a[1]-b[1]));
        int tail=points[0][1];
        int num=1;
        for(int i=1;i<points.length;i++){
            if(tail>=points[i][0])
            continue;
            tail=points[i][1];
            num++;
        }
        return num;
    }
}
```