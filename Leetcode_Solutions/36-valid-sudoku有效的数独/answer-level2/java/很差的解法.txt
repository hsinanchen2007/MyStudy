### 解题思路
没脸见人了，这代码好丑
### 代码

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[] Mask=new int[10];
        int index=0;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                index=board[i][j]-'0';
                if(Mask[index]==0)
                    Mask[index]=1;
                else 
                    return false;
            }
             Arrays.fill(Mask,0);
        }
        Arrays.fill(Mask,0);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[j][i]=='.')
                    continue;
                index=board[j][i]-'0';
                if(Mask[index]==0)
                    Mask[index]=1;
                else
                    return false;
            }
             Arrays.fill(Mask,0);
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3) {
                for (int q = 0; q < 3; q++) {
                    for (int w = 0; w < 3; w++) {
                        if(board[i+q][j+w]=='.')
                            continue;
                        index=board[i+q][j+w]-'0';
                        if(Mask[index]==0)
                            Mask[index]=1;
                        else
                            return false;
                    }
                }
                Arrays.fill(Mask, 0);
            }
        }
        return true;
    }
}
```