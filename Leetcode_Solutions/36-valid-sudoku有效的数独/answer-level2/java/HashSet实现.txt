### 解题思路
再加入新元素前先判断一下ROWS、COLS、BOXS中对应位置有没有该元素。 
if(ROWS[i].contains(c) || COLS[j].contains(c) || BOXS[i/3*3+j/3].contains(c)){
    return false;
}

### 代码

```java
import java.util.HashMap;
import java.util.HashSet;

public class Solution {
    public boolean isValidSudoku(char[][] board) {
        // 9行，9列，9个方框
        HashSet<Character>[] ROWS = new HashSet[9];
        HashSet<Character>[] COLS = new HashSet[9];
        HashSet<Character>[] BOXS = new HashSet[9];

        for(int i=0; i<board.length; i++){
            ROWS[i] = new HashSet<>();
            COLS[i] = new HashSet<>();
            BOXS[i] = new HashSet<>();
        }

        // 对board进行遍历
        for(int i=0; i<board.length; i++){
            for(int j=0; j<board.length; j++){
                char c = board[i][j];
                if(c == '.'){
                    continue;
                }
                if(ROWS[i].contains(c) || COLS[j].contains(c) || BOXS[i/3*3+j/3].contains(c)){
                    return false;
                }
                ROWS[i].add(c);
                COLS[j].add(c);
                // 行 i/3 列j/3
                BOXS[i/3*3+j/3].add(c);
            }
        }
        return true;
    }
}

```