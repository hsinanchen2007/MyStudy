### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/ff50b63fb9b12cabe31f79e66b41f2c3231abdb8e9f9374d1f9bbfda658c0602-image.png)

### 代码

```java
class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        int[] arr1 = coordinates[0];
        int[] arr2 = coordinates[1];

        int initY = arr1[1];
        int initX = arr1[0];

        int xDistance = arr2[0] - initX;
        int yDistance = arr2[1] - initY;


        for (int i = 2; i < coordinates.length; i++) {
            int[] curArr = coordinates[i];
            int curX = curArr[0];
            int curY = curArr[1];
            if (yDistance == 0) {
                if (curY - initY != 0) return false;
            }else {
                if (curY - initY == 0) return false;
                if (((curX - initX) / (curY - initY)) != (xDistance / yDistance)) return false;
            }
        }

        return true;
    }
}
```