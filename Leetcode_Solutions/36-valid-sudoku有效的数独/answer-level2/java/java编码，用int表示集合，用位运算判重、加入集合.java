直接就用移位编码来做，用int表示集合，通过按位与判断行、列、宫格是否重复，通过按位或加入数字对应的集合，只用一维数组的额外空间，所有字符元素只过一遍
执行用时：1 ms
已经战胜 100.00 % 的 java 提交记录
```
class Solution {
    public boolean isValidSudoku(char[][] board) {
        if(board == null)
            return false;
        if(board.length !=9)
            return false;
        int[] map = new int[9];
        for(int y=0; y<9; y++){
            if(board[y] == null || board[y].length != 9)
                return false;
            for(int x=0; x<9; x++){
                int key = board[y][x] - '1'; //key:数字
                if(key >= 0 && key <= 8) {  //1~9有效数字
                    int index = (1<<x)     //Value:位置编码，最低9位存放列号
                            | (1<<(y+9))    //中间9位存放行号
                            | (1<<(x/3 + y/3*3 + 18));  // z为9宫格区域序号
                    int old = map[key];
                    if((old & index) == 0) //无重复，则按位或，加入位置集合
                        map[key] = old | index;
                    else    //有重复
                        return false;
                }
            }
        }
        return true;
    }
}
```
