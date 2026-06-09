### 解题思路
1.for对瓷砖选型从大到小，大量减少时间复杂度
2.对次数进行记录，减少不必要的递归
3.对剩余空间先进行判断，如果空间小于瓷砖空间，则直接返回

### 代码

```java
class Solution {
        // 瓷砖最大边长
    private int rectangleLength = 0;
    // 最小次数
    private int minNum = Integer.MAX_VALUE;
    private int[] fillArray;

    class Point {
        int x = -1;
        int y = -1;
    }

    public int tilingRectangle(int n, int m) {
        rectangleLength = n > m ? m : n;
        fillArray = new int[m];
        Arrays.fill(fillArray, 1);
        // 构建矩形
        int tempNum = 0;
        int[][] house = new int[n][m];
//        long start = System.nanoTime();
        backTracking(house,tempNum,m*n);
//        long end = System.nanoTime();
//        System.out.println(end - start);
        return minNum;
    }

    private void backTracking(int[][] house,int tempNum,int total) {
        if (isFill(house) &&  (tempNum < minNum)) {
            minNum = tempNum;
            return;
        }
        // 对1到最大边长进行遍历
        Point point = new Point();
        int tempTotal;
        //for (int rectL = 1; rectL <= rectangleLength; rectL++) {
        for(int rectL = rectangleLength; rectL >= 1; rectL--){
            if (!findSpace(house, rectL, point,total)) {
                continue;
            }
            // 剪枝，说明目前的排列是错的，大幅减少时间复杂度
            if (tempNum >= minNum){
                break;
            }
            tempTotal = rectL * rectL;
            total -= tempTotal;
            // 填充
            fillHouse(house, rectL, point);
            tempNum++;
            // 条件符合，继续回溯
            backTracking(house,tempNum,total);
            // 回退
            regeneration(house, rectL, point);
            tempNum--;
            total += tempTotal;
        }
    }

    /**
     * 查看是否能放得下rect
     *
     * @param house      房子
     * @param rectLength 瓷砖长
     * @return -1: 找不到能放置的位置
     */
    private boolean findSpace(int[][] house, int rectLength, Point point,int total) {
        if (total < (rectLength * rectLength)) {
            return false;
        }
        for (int i = 0; i <= house.length - rectLength; i++) {
            for (int j = 0; j <= house[0].length - rectLength; j++) {
                if (!filter(house, i, j, rectLength)) {
                    continue;
                }
                point.x = i;
                point.y = j;
                return true;
            }
        }
        return false;
    }

    /**
     * 瓷砖对房子进行范围过滤
     *
     * @param house
     * @param low
     * @param col
     * @param rectL
     * @return
     */
    private boolean filter(int[][] house, int low, int col, int rectL) {
        for (int i = low; i < low + rectL; i++) {
            for (int j = col; j < col + rectL; j++) {
                if (house[i][j] == 0) {
                    continue;
                }
                return false;
            }
        }
        return true;
    }

    private void fillHouse(int[][] house, int rectL, Point pos) {
        for (int low = pos.x; low < pos.x + rectL; low++) {
            Arrays.fill(house[low], pos.y, pos.y + rectL, 1);
        }
    }

    private void regeneration(int[][] house, int rectL, Point pos) {
        for (int low = pos.x; low < pos.x + rectL; low++) {
            Arrays.fill(house[low], pos.y, pos.y + rectL, 0);
        }
    }

    private boolean isFill(int[][] house) {
        for (int[] aHouse : house) {
            if (Arrays.equals(aHouse, fillArray)) {
                continue;
            }
            return false;
        }
        return true;
    }
}
```