### 解题思路
这个题不用想的复杂，用一个变量就可以表示一个位置，按顺序遍历二维数组，可以看成一维数组
1.定义一个变量count，记录数字为0的位置
2.使用一个arrayList记录每个数字为0的位置
3.遍历ArrayList，使用数学公式计算行和列
4.将对应行和列置为0

### 代码

```java
class Solution {
    public void setZeroes(int[][] matrix) {
        if(matrix.length<1)return;

        int rowLen = matrix.length;
        int colLen = matrix[0].length;
        int count = 0;//count值最大为mn
        List<Integer> loca = new ArrayList<Integer>();//用于存放值为0时的每个count值

        for (int i = 0; i < rowLen; i++) {
            for (int j = 0; j < colLen; j++) {
                count++;
                if(matrix[i][j]==0) loca.add(count);
            }
        }

        for (int i = 0; i < loca.size(); i++) {
            Integer lo = loca.get(i);
            int row = (lo - 1) / colLen;
            int col = (lo - 1) % colLen;
            for (int j = 0; j < colLen; j++) {
                matrix[row][j] = 0;
            }
            for (int j = 0; j < rowLen; j++) {
                matrix[j][col] = 0;
            }
        }
    }
}
```