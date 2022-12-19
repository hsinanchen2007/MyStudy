### 解题思路
找准四个参考点做顺时针运动(minX,minY)->(maxX,minY)->(maxX,maxY)->(minX,maxY)
然后计算出每一圈的点个数，调整minX,minY,maxX,maxY


![Snipaste_2020-03-28_17-05-44.png](https://pic.leetcode-cn.com/06142746fc674a025e5605d7d5ab38403cfeb69b924050c555ab7414ab8e34e5-Snipaste_2020-03-28_17-05-44.png)

供参考
### 代码

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int y = matrix.length;
        if (y == 0) {
            return Collections.emptyList();
        }
        int x = matrix[0].length;
        ArrayList<Integer> list = new ArrayList<>(x * y);
        if (x == 0) {
            return list;
        }

        int len = x * y, xx = 0, yy = 0, maxx = x - 1, minx = 0, maxy = y - 1, miny = 0;
        // 第一圈点个数
        int dot = 2 * (x + y) - 4;
        for (int i = 0; i < len; i++) {
            list.add(matrix[yy][xx]);

            // 顺时针横线
            if (yy == miny) {
                // 到达顶点，向下走
                if (xx == maxx) {
                    yy += 1;
                    //
                    continue;
                }
                xx += 1;
            }
            // 向下走
            else if (xx == maxx) {
                if (yy == maxy) {
                    xx -= 1;
                    //
                    continue;
                }
                yy += 1;
            }
            // 向左走
            else if (yy == maxy) {
                // 最左端
                if (xx == minx) {
                    yy -= 1;
                    //
                    continue;
                }
                xx -= 1;
            }
            // 向上走
            else if (xx == minx) {
                if (yy == miny) {
                    xx += 1;
                    //
                    continue;
                }
                yy -= 1;
            }

            // 没走一圈经过点的总数
            if (i + 1 == dot) {
                //
                x -= 2;
                y -= 2;
                dot += 2 * (x + y) - 4;
                //
                minx += 1;
                maxx -= 1;

                miny += 1;
                maxy -= 1;
                
                //
                yy += 1;
                xx += 1;
            }

        }
        return list;
    }
}
```