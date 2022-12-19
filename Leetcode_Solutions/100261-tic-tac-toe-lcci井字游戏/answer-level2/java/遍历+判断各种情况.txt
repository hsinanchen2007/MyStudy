### 解题思路


### 代码

```java
class Solution {
    public String tictactoe(String[] board) {
        boolean fill = true;
        boolean duijiao1 = board[0].charAt(0) == ' '?false:true;
        boolean duijiao2 = board[0].charAt(board.length - 1) == ' '?false:true;
        boolean [] col = new boolean[board.length];
        Arrays.fill(col,true);
        for(int j = 0;j < board.length;j++){
            String s = board[j];
            if(duijiao1 && s.charAt(j) != board[0].charAt(0)) duijiao1 = false;
            if(duijiao2 && s.charAt(col.length - 1 - j) != board[0].charAt(col.length - 1)) duijiao2 = false;
            boolean wid = true;
            if(s.charAt(0) == ' ') wid = false;
            for(int i = 0;i < s.length();i++){
                if(fill && s.charAt(i)==' ')  fill = false;
                if(wid && s.charAt(i) != s.charAt(0)) wid = false;
                if(col[i] && s.charAt(i) != board[0].charAt(i)) col[i] = false;
            }
            if(wid) return "" + s.charAt(0);
        }
        if(duijiao1) return "" +board[0].charAt(0);
        if(duijiao2) return "" + board[0].charAt(col.length - 1);
        for(int i = 0;i < col.length;i++) if(col[i] && board[0].charAt(i) !=' ') return "" + board[0].charAt(i);
        return fill?"Draw":"Pending";
    }                                               
}
```