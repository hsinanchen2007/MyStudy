 **我们目的是求两个值，一个是最大分数值，另一个是相同最大分值的路径数**

 分别建立两个状态方程，**dpScore[i][j]** 表示走到位置（i，j）最大分值。
 **dpPath[i][j]** 表示走到位置（i，j）的最大分值的路径数。

### 分开两步来求解：
 **第一步**
 先求dpScore[i][j]， 根据题意，有三种走法： 要么向上走，要么向左走，要么向左上走
 所以位置（i,j)**要么从(i+1, j)过来，要么从(i, j+1)过来，要么从(i+1, j+1)过来**
 所以dpScore[i][j] = max(dpScore[i+1][j],dpScore[i][j+1],dpScore[i+1][j+1]) + board[i][j])

 **第二步**
 dpPath[i][j],同样**要么从(i+1, j)过来，要么从(i, j+1)过来，要么从(i+1, j+1)过来**, 跟dpScore[i][j]的分数值有关
 如果dpPath[i][j]是从dpScore[i+1][j],dpScore[i][j+1],dpScore[i+1][j+1],三个中最大的分数过来的，
 所以有可能是dpScore[i+1][j]，
 也有可能是dpScore[i][j+1]，
 也有可能是dpScore[i+1][j+1]

 上面如果他们的最大分数值相等的话，dpPath[i][j] + 原来相同的最大分数值的路径个数（也就是相同的路径），详情请往下看
 所以假设maxScore = max(dpScore[i+1][j],dpScore[i][j+1],dpScore[i+1][j+1] )
 如果dpScore[i+1][j]=maxScore， dpPath[i][j] = （**dpPath[i][j] + dpPath[i+1][j]**）
 如果dpScore[i][j+1]=maxScore， dpPath[i][j] = （**dpPath[i][j] + dpPath[i][j+1]**）
 如果dpScore[i+1][j+1]=maxScore， dpPath[i][j] = （**dpPath[i][j] + pPath[i+1][j+1]**）

 如果看不懂，可以先从简单的动态规划入手
 刷了N多矩阵相关的动态规划的题目，发现都是一模一样的框架（套路），如果想当做专题来刷，
 可参考https://blog.csdn.net/weianluo/article/details/103669044


 **以下是代码**
```
    public static int[] pathsWithMaxScore(List<String> board) {
        int row = board.size();
        if (row == 0) return new int[]{0, 0};
        int modNum = 1000000007;
        int col = board.get(0).length();
        int[][] dpScore = new int[row+1][col+1];
        int[][] dpPath = new int[row+1][col+1];
        //从右下角开始走，初始路径为1条
        dpPath[row-1][col-1] = 1;
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                //如果board[i][j] == 'X', 即为障碍
                //如果dpPath[i+1][j],dpPath[i][j+1]和dpPath[i+1][j+1]都等于0，就是路径被障碍'X'封死了
                if (board.get(i).charAt(j) != 'X' &&
                        (dpPath[i + 1][j] != 0 || dpPath[i][j + 1] != 0 || dpPath[i + 1][j + 1] != 0)) {
                    int maxScore = Math.max(Math.max(dpScore[i + 1][j], dpScore[i][j + 1]), dpScore[i + 1][j + 1]);
                    dpScore[i][j] = maxScore + board.get(i).charAt(j) - '0';
                    if (dpScore[i + 1][j] == maxScore) {
                        dpPath[i][j] = (dpPath[i][j] + dpPath[i + 1][j]) % modNum;
                    }
                    if (dpScore[i][j + 1] == maxScore) {
                        dpPath[i][j] = (dpPath[i][j] + dpPath[i][j + 1]) % modNum;
                    }
                    if (dpScore[i + 1][j + 1] == maxScore) {
                        dpPath[i][j] = (dpPath[i][j] + dpPath[i + 1][j + 1]) % modNum;
                    }
                }
            }
        }
        //dpScore[0][0] - ('E' - '0'),是因为结束时候为'E'，上面加了，所以要减去
        int maxScore = dpScore[0][0] == 0 ? 0 : dpScore[0][0] - ('E' - '0');
        return new int[]{maxScore, dpPath[0][0]};
    }

    public static void main(String[] args) {
        List<String> board = new ArrayList<>();
        board.add("E11");
        board.add("XXX");
        board.add("11S");
        int[] ints = pathsWithMaxScore(board);
        for(int i: ints){
            System.out.println(i);
        }

    }
```

