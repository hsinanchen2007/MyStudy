执行用时 :7 ms, 在所有 Java 提交中击败了98.63% 的用户
内存消耗 :41.8 MB, 在所有 Java 提交中击败了100.00%的用户

### 解题思路
1、将图转为二维数组
2、假设每次遍历到的格子对周长的影响都是 +4；
3、排除第一个格子的情况；
4、往后每经过一个格子，都判断其上、左两处是否为1，如果为1则减掉两个格子的边，即-2；

### 代码

```java
class Solution {
    public int islandPerimeter(int[][] island) {
        int length = 0;
        for (int i = 0; i < island.length; i++) {
            for (int j = 0; j < island[i].length; j++) {
                if (island[i][j] == 1) {
                    length += 4;
                    if (i != 0 && island[i - 1][j] == 1) length -= 2;
                    if (j != 0 && island[i][j - 1] == 1) length -= 2;
                }
            }
        }
        return length;
    }
}
```