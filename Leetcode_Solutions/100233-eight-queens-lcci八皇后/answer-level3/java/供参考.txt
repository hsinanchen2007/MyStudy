### 解题思路
参考了其他大佬的思路，主要思想是回溯，比较需要注意的地方是判断当前位置是否可以放置Q，这里采用一个flag数组用来记录之前放置过的棋子的列值，行列相加以及行列相减（表示对角线）。

### 代码

```java
class Solution {
    private static char[][] ans;
    private static int N;
    private static int[][] flag;
    private static List<List<String>> result;
    public List<List<String>> solveNQueens(int n) {
        ans = new char[n][n];
        N = n;
        flag = new int[3][N];//y,x+y,x-y
        ans = new char[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ans[i][j] = '.';
            }
        }
        result = new ArrayList<>();
        test(0);
        return result;
    }
    //index表示已经放置了多少个Q了
    private void test(int index){
        if(index==N){
            ArrayList<String> temp = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                temp.add(String.valueOf(ans[i]));
            }
            result.add(temp);
        }
        for (int i = 0; i < N; i++) {
            if(judge(index,i,index)){
                //当可以放置时，回溯
                ans[index][i] = 'Q';
                flag[0][index] = i;
                flag[1][index] = index+i;
                flag[2][index] = index-i;
                test(index+1);
                flag[0][index] = 0;
                flag[1][index] = 0;
                flag[2][index] = 0;
                ans[index][i] = '.';
            }
        }
    }
    //该函数用于判断当前位置是否可以放置
    private boolean judge(int x,int y,int index){
        for (int i = 0; i < index; i++) {
            if(y==flag[0][i]||(x+y)==flag[1][i]||(x-y)==flag[2][i])
                return false;
        }
        return true;
    }
}
```