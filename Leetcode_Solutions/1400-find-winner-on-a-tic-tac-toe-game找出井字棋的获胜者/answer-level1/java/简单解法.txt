模拟每一步落子是很简单的。主要问题是如何判断是否赢
要注意的是输入的数组中不存在重复的落子，不会先下[0,0]后面再下一次
最后井字棋胜利的结果是可枚举的，共计8种
每次落子都会对一个或者几个胜利结果造成影响，当一个胜利结果被影响3次后就算胜利。
另外，A和B的落子并不需要记录在一个棋盘中。A和B单独记录就会方便很多

```
    public String tictactoe(int[][] moves) {
        if(moves.length<5) return "Pending";

        int[] rowA = new int[3];
        int[] rowB = new int[3];
        int[] colA = new int[3];
        int[] colB = new int[3];
        int[] oblA = new int[2];
        int[] oblB = new int[2];
        int aFirst = 20;
        int bFirst = 20;

        // 检查A
        for (int i = 0; i < moves.length; i+=2) {
            int[] move = moves[i];
            boolean result = this.check(move,rowA,colA,oblA);
            if(result){
                aFirst = i;
                break;
            }
        }

        // 检查B
        for (int i = 1; i < moves.length; i+=2) {
            int[] move = moves[i];
            boolean result = this.check(move,rowB,colB,oblB);
            if(result){
                bFirst = i;
                break;
            }
        }

        if(aFirst<bFirst) return "A";
        if(aFirst>bFirst) return "B";
        if(moves.length == 9) return "Draw";

        return "Pending";
    }

    private boolean check(int[] move,int[] row,int[] column,int[]oblique){
        int rowIndex = move[0];
        int colIndex = move[1];
        // 检查行
        row[rowIndex]++;
        if(row[rowIndex] == 3) return true;

        // 检查列
        column[colIndex]++;
        if(column[colIndex] == 3) return true;

        // 00 ,11, 22
        // 02, 11, 20

        // 从左向右斜
        if(rowIndex-colIndex == 0){
            oblique[0]++;
            if(oblique[0] == 3) return true;
        }

        // 从右向左斜
        if(rowIndex+colIndex == 2){
            oblique[1]++;
            if(oblique[1] == 3) return true;
        }

        return false;
    }
```
![image.png](https://pic.leetcode-cn.com/c9fc9b36ae50505fb490512e6fb86e34143199ccdffe69cbf3cc26b7ca3ff3cc-image.png)
