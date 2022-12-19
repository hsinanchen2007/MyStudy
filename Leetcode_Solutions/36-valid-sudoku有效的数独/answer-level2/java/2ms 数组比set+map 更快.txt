### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
   int[][] rowMap=new int[9][9];
        int[][] columnMap=new int[9][9];
        int[][] regionMap=new int[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                int num=c-49;
                if (!(c<='9'&&c>='1')){
                    continue;
                }
                // 行
                if (rowMap[i][num]==1) {
                    return false;
                }
                rowMap[i][num]=1;
                // 列
                if (columnMap[j][num]==1) {
                    return false;
                }
                columnMap[j][num]=1;
                int region = (i / 3) * 3 + (j / 3);
                // 区域
                if (regionMap[region][num]==1) {
                    return false;
                }
                regionMap[region][num]=1;
            }
        }
        return true;
    }
}
```