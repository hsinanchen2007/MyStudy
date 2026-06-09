### 解题思路
先考虑的行的情况
定义一个二维数组 rows 记录每一行的情况，如rows[2][5]表示第2行数字5，
循环遍历该数独，若第2行中出现数字5，
判断row[2][5]是否等于true(是否已经出现过)，如果rows[2][5]=true,返回false
否则rows[2][5]=true,继续遍历

列的情况同理

每一个小数独（小块）其实道理也是一样的，难点在于如何根据行号i，列号j 算出是第几个数独；
我是根据列举法总结出这样一个通用公式
index=i/3*3+j/3;

### 代码

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][] rows = new boolean[9][10];
        boolean[][] cols = new boolean[9][10];
        boolean[][] block = new boolean[9][10];
        int index;
        int num;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j]!='.'){
                    num=board[i][j]-'0';
                    index=i/3*3+j/3;
                    if (rows[i][num]||cols[j][num]||block[index][num]) {
                        return false;
                    }else {
                        rows[i][num]=true;
                        cols[j][num]=true;
                        block[index][num]=true;
                    }
                }
                  
            }
        }
        return true;
    }
}
```