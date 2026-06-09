### 解题思路
时间复杂度O(n2)
![image.png](https://pic.leetcode-cn.com/6be63492259252240b3a83e3de1cca75681275bf2e4fb902a212096eb3e4dffe-image.png)


### 代码

```java
class Solution {
    public int maxPoints(int[][] points) {
        //先对点进行排序，将横坐标纵坐标差值较小的点排在前面
        Arrays.sort(points, new Comparator<int[]>(){
            public int compare(int[] arr1, int[] arr2){
                return Math.abs(arr1[0] - arr1[1]) - Math.abs(arr2[0] - arr2[1]);
            }
        });
        if(points == null || points.length == 0)
            return 0;
        int len = points.length;
        if(len < 3)
            return len;
        int res = 0;
        for(int i = 1; i < len; i++){
            long x = points[i][0];
            long y = points[i][1];
            long dx = x - points[i - 1][0];
            long dy = y - points[i - 1][1];
            int count = 0;
            if(dx == 0 && dy == 0){
                for(int j = 0; j < len; j++){
                    if(points[j][0] == x && points[j][1] == y)
                        count ++;
                }
            }
            else{
                for(int j = 0; j < len; j ++){
                    if((points[j][1] - y) * dx == (points[j][0] - x) * dy)
                        count ++;
                }
            }
            res = Math.max(res, count);
        }
        return res;
    }
}
```