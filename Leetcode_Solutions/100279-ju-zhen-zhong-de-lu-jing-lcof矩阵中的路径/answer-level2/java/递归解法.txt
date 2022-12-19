### 解题思路
递归解法：递归的难点在于递归函数的参数设置，主要包括原数组遍历到的坐标位置，字符串遍历到的位置。
当数组中坐标值与字符串坐标值相等，则进入下一层递归，当字符串遍历长度大于等于字符串本身长度时，返回true，
上层函数根据返回的true值直接跳出本层函数，返回到最上面的层函数，根据返回结果判断，如果为true,直接返回true即可。

### 代码

```java
class Solution {
    int[] a = {0,0,1,-1};
    int[] b = {1,-1,0,0};
    public boolean exist(char[][] board, String word) {
        boolean res = false;
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[0].length;j++){
                if(board[i][j]==word.charAt(0)){
                    board[i][j]='#';
                    res = trace(board,word,1,i,j);
                    if(res){
                        return true;
                    }
                    board[i][j]=word.charAt(0);
                }
            }
        }
        return res;
    }
    public boolean trace(char[][] board,String str,int index,int i,int j){
        //System.out.print(i);
        //System.out.print(j);
        
        if(index>=str.length()){
            return true;
        }
        // 获取到一个字符
        char c = str.charAt(index);
        for(int m=0;m<4;m++){
            int newi = i+a[m];
            int newj = j+b[m];
            if(newi<0||newi>=board.length||newj<0||newj>=board[0].length){
                continue;
            }
            //System.out.println(board[newi][newj]);
            //System.out.println();
            if(board[newi][newj]==c){
                System.out.println(board[newi][newj]);
                board[newi][newj] = '#';
                if(trace(board,str,index+1,newi,newj)){
                    return true;
                }
                board[newi][newj] = c;
            }

        }
        // System.out.println(i);
        // System.out.println(j);
        // System.out.println("test");
        return false;
    }
    
}
```