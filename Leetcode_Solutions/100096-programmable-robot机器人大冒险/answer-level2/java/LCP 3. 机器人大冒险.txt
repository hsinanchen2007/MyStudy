### 解题思路
一开始暴力 超时了，设置了障碍区的区间，在区间内才判断，压线飘过。

### 代码

```java
class Solution {
    public boolean robot(String command, int[][] obstacles, int x, int y) {
        int minX = 1000000000;
        int minY = 1000000000;
        int maxX = 0;
        int maxY = 0;
        for (int k=0;k<obstacles.length;k++){
            minX = minX > obstacles[k][0] ? obstacles[k][0] : minX;
            minY = minY > obstacles[k][1] ? obstacles[k][1] : minY;
            maxX = maxX < obstacles[k][0] ? obstacles[k][0] : maxX;
            maxY = maxY < obstacles[k][1] ? obstacles[k][1] : maxY;
        }

        int i=0;
        int j=0;
        int step = 0;
        while (i <= x && j <= y){
            if (command.charAt(step) == 'U'){
                j++;
            }
            else if (command.charAt(step) == 'R') {
                i++;
            }

            step++;
            if (step == command.length()){
                step =0;
            }

            if (obstacles.length > 0 && (i>=minX && j>=minY && i<=maxX && j<=maxY)){
                if (isOstacles(i, j, obstacles)){
                    return false;
                }
            }

            if (i==x && j==y){
                return true;
            }
        }
        return false;
    }
    
    private boolean isOstacles(int i, int j, int[][] obstacles){
        for (int k=0;k<obstacles.length;k++){
            if (i == obstacles[k][0] && j == obstacles[k][1]){
                return true;
            }
        }
        return false;
    }
}
```