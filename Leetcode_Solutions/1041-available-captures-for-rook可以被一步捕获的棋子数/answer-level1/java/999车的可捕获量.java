### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int row=0;
        int col=0;
        int count=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]=='R'){
                    row=i;
                    col=j;
                    break;
                }
            }
        }
        // System.out.println(row);
        // System.out.println(col);
        for(int i=row+1;i<8;){
            if(board[i][col]=='.'){
                i++;
                
            }else if(board[i][col]=='p'){
                i++;
                count++;
                // System.out.println(count+"上");
                 break;
            }else{
                break;
            }
            
        }
        for(int i=row-1;i>=0;){
            if(board[i][col]=='.'){
                i--;
            }else if(board[i][col]=='p'){
                i--;
                count++;
                // System.out.println(count+"下");
                break;
            }else{
                break;
            }
        }
        for(int j=col+1;j<8;){
            if(board[row][j]=='.'){
                j++;

            }else if(board[row][j]=='p'){
                j++;
                count++;
                // System.out.println(count+"右");
                break;
            }else{
                break;
            }
        }
        for(int j=col-1;j>=0;){
            if(board[row][j]=='.'){
                j--;
            }else if(board[row][j]=='p'){
                j--;
                count++;
                // System.out.println(count+"左");
                break;
            }else{
                break;
            }
        }
        return count;
    }
}
```