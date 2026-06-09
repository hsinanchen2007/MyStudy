5ms 42.6MB
参考精选，仅供自己参考

class Solution {
    public boolean exist(char[][] board, String word) {
    //多写一点预判条件，可以优化耗时
        if(board == null || board[0] == null || board.length == 0 || board[0].length == 0 || word == null || word.equals("")||      board.length * board[0].length < word.length()) return false;
    //也可以不转换为数组，直接用CharAt查询字符串的第k个元素。
        char words[]=word.toCharArray();
    //暴力加剪枝，暴力是遍历全部元素且每一个元素都穷尽。剪枝是发现不通立刻返回false  
        for(int i =0; i<board.length;i++){
            for(int j =0; j<board[0].length;j++){
                if (dfs(i,j,board,words,0)) {
                    return true;
                    }
                    
            }
        }
        return false;
    }

    public boolean dfs(int i, int j, char[][] board, char[]words,int k){
        //预判条件，最后一个条件包括了防止重复查询的判断（对‘/’）
        if(i<0||i>=board.length||j<0||j>=board[0].length||board[i][j]!=words[k]){
            return false;
        }
        //全部找到的条件
        if(k==words.length-1){
            return true;
        }
        //防止重复访问同一元素，先置为/，然后遍历完恢复
        char temp = board[i][j];
        board[i][j] = '/';
        //减枝的最重要的一步，四个方向用了与并起来
        boolean res = dfs(i+1,j,board,words,k+1)||dfs(i,j+1,board,words,k+1)||dfs(i-1,j,board,words,k+1)||dfs(i,j-1,board,words,k+1);
        board[i][j] = temp;
        return res;
    }
}