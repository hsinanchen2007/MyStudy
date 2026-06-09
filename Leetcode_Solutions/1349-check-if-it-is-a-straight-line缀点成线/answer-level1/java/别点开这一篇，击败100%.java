### 解题思路
这道题从斜率入手，值得注意的是斜率公式是(y1- y2) / (x1 -x2)，但可能存在除0错误，所以可以考虑用交换将除法变成两个斜率公式乘法，然后做对比。

### 代码

```java
class Solution {
    public boolean checkStraightLine(int[][] coordinates) {

        if(coordinates.length == 2) return true;

        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];

        for(int i = 2; i < coordinates.length; i++){
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            if(((x - x1) * (y2 - y1)) != ((y - y1) * (x2 - x1)))
                return false;
        }
        return true;
    }
}
```