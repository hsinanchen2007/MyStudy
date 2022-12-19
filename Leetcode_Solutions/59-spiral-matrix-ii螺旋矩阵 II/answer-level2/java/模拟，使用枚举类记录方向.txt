顺时针旋转思路：
- 1、定义方向：向右写入；定义写入当前的矩阵 层级（level）
- 2、先向右开始，按 右→下→左→上 顺序，每次写入至当前层级行/列的首尾时，则改变写入方向
- 3、当向上写入至首时，说明当前层级已完成写入，level+1

```
public int[][] generateMatrix(int n) {
        //结果矩阵
        int[][] matrix = new int[n][n];
        //总大小
        int nums = n * n;
        //当前方向：向上、下、左、右（插入）
        Dirction dirction = Dirction.right;
        //旋转层数
        int level =0;
        for (int i=0,j=0,num=1;num<=nums;num++){
            matrix[i][j] = num;

            //计算下个数横纵 坐标
            if(dirction == Dirction.right && j< n-1-level){
                //横坐标不变，纵坐标向右移动
                j++;
            }else if(dirction == Dirction.left && j> level){
                j--;
            }else if(dirction == Dirction.dowm && i< n-1-level){
                i++;
            }else if(dirction == Dirction.up && i> level){
                i--;
            }

            //改变方向
            if(dirction == Dirction.right && j == n-1-level){
                dirction = Dirction.dowm;
            }else if(dirction == Dirction.dowm && i == n-1-level){
                dirction = Dirction.left;
            }else if(dirction == Dirction.left && j == level){
                dirction = Dirction.up;
            }else if(dirction == Dirction.up && i == level+1){
                dirction = Dirction.right;
                //转一圈
                level++;
            }
        }
        return matrix;
    }

    enum Dirction{
        right,
        left,
        up,
        dowm;
    }
```
