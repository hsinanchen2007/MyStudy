# **解题思路**
    本题N皇后应该有四个限制
    1.行不能重复
    2.列不能重复
    3.左上不能重复
    4.右上不能重复
    对于第一个限制，可用递归来消除，而其他的都会添加一个数组来作为条件cols cross crossRight
```
public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList();
        List<String> tmp = new ArrayList();
        boolean[] cols = new boolean[n];
        boolean[] cross = new boolean[2*n];
        boolean[] crossRight = new boolean[2*n-1];
        backTrack(res,tmp,cols,cross,crossRight,n,0);
        return res;
    }
    public void backTrack(List<List<String>> res,List<String> tmp,boolean[] cols,boolean[] cross,boolean[] crossRight,int n,int row){
        //结束条件：当到达最后一层添加 并退出
        if(row==n){
            res.add(new ArrayList(tmp));
            return;
        }
        //这一行的每一个位置进行判断
        for(int col=0;col<n;col++){
            int num = leftCross(row,col,n);
            int right = rightCross(row,col);
            //判断是否可以放
            if(cols[col]||cross[num]||crossRight[right])
                continue;
            //设置条件
            cols[col] = true;
            cross[num] = true;
            crossRight[right] = true;
            //添加某一行
            tmp.add(creatRow(col,n));
            backTrack(res,tmp,cols,cross,crossRight,n,row+1);
            // 消除条件
            cols[col] = false;
            cross[num] = false;
            crossRight[right] = false;
            tmp.remove(tmp.size()-1);
        }
    }
    //用于左上的映射
    public int leftCross(int row,int col,int n){
        return n+col-row;
    }
    //用于右上的映射
    public int rightCross(int row,int col){
        return row+col;
    }
    //用于每一行放置棋子
    public String creatRow(int col,int n){
        char[] str = new char[n];
        Arrays.fill(str,'.');
        str[col] = 'Q';
        return String.valueOf(str);
    }
```
