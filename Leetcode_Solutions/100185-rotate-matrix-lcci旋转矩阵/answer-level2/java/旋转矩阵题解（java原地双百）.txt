对于该题我们很容易能找到如下的坐标变换规律：
    nextX = currentY，nextY = N - 1 - currentX
    由于题目要求不能使用额外的空间，因此需要一种特殊的位置更新顺序。
我的做法是四个点四个点的更新。
以示例一为例[
  [1,2,3],
  [4,5,6],
  [7,8,9]
]
把1移动到3的位置，3移动到9的位置，9移动到7的位置，7移动到1的位置。
如此只要对第一行的前N-1个元素进行如此操作，最外圈已经更新好了。
如此依次对每一圈进行该操作即可。
```
class Solution {
    public void rotate(int[][] matrix) {
        int N = matrix.length;
        int level = (N + 1) / 2;
        int last = N - 1;
        int currentX, currentY, nextX, nextY, val;
        for(int l = 0; l < level; l++){
            for(int i = l; i < last; i++){
                //当前结点坐标为 l , i
                currentX = l;
                currentY = i;
                val = matrix[currentX][currentY];   
                for(int j = 0; j < 4; j++){
                    nextX = currentY;
                    nextY = N - 1 -currentX;
                    //交换 val 和 matrix[next][next]的值
                    int temp = matrix[nextX][nextY];
                    matrix[nextX][nextY] = val;
                    val = temp;
                    currentX = nextX;
                    currentY =nextY;
                }
            }
            last -= 1;
        }
    }
}
```
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
38.2 MB
, 在所有 Java 提交中击败了
100.00%
的用户