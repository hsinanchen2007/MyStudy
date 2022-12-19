感觉在这方面还是不熟悉，改之又改才有看得过去的结果：
    执行用时 :8 ms, 在所有 Java 提交中击败了94.69% 的用户
    内存消耗 :42.1 MB, 在所有 Java 提交中击败了85.78%的用户
思路很清晰，就是经典的递归查找，死路的回就往回退
说一下我这里比较可取的地方：
下面整个hasBeen数组用来标记某个格子的字母是否已用，这没问题。但是我多加了两行两列来把他包起来，
并全都赋值为true  即已用
这样有个什么好处呢？在真正的表格里面是存在边界字母的，它们或许上面没有字母了  或许左边没有字母了，
通过hasBeen外围一圈我在使用之前直接查看四周是否可用，而忽视是否是边界字母。完毕
```
boolean hasBeen[][]=new boolean[rowNum+2][colNum+2];//在外面加一层包皮，并且标记他已读
        for (int i = 0; i <colNum+2; i++) {
            hasBeen[0][i]=true;
            hasBeen[rowNum+1][i]=true;
        }
        for (int i = 0; i <rowNum+2; i++) {
            hasBeen[i][0]=true;
            hasBeen[i][colNum+1]=true;
        }



          if (!hasBeen[x+2][y+1]&&board[x+1][y]==word.charAt(n)){
            hasBeen[x+2][y+1]=true;
            if (searchNext(board,hasBeen,word,x+1,y,n+1))return true;
            hasBeen[x+2][y+1]=false;
         }   
```


```
public boolean exist(char[][] board, String word) {
        int rowNum = board.length;
        if (rowNum==0){//网格是空的
            if (word=="")return true;//字符串也是空的
            else return false;
        }
        int colNum = board[0].length;
        if (colNum==0){//网格是空的
            if (word=="")return true;//字符串也是空的
            else return false;
        }
        boolean hasBeen[][]=new boolean[rowNum+2][colNum+2];//在外面加一层包皮，并且标记他已读
        for (int i = 0; i <colNum+2; i++) {
            hasBeen[0][i]=true;
            hasBeen[rowNum+1][i]=true;
        }
        for (int i = 0; i <rowNum+2; i++) {
            hasBeen[i][0]=true;
            hasBeen[i][colNum+1]=true;
        }
        List<List<Integer>> list=new ArrayList<>();//先找到第一个字母所在并作为出发点
        for (int i = 0; i <rowNum; i++) {//寻找出发点
            for (int j = 0; j <colNum; j++) {
                if (board[i][j]==word.charAt(0)){//找到就放到列表里面
                    List<Integer> tmp=new ArrayList<>(2);
                    tmp.add(i); tmp.add(j);
                    list.add(tmp);
                }
            }
        }
        for (List<Integer> subList : list) {
            hasBeen[subList.get(0)+1][subList.get(1)+1]=true;
            if (searchNext(board,hasBeen,word,subList.get(0),subList.get(1),1))return true;
            hasBeen[subList.get(0)+1][subList.get(1)+1]=false;
        }
        return false;
    }
    //递归函数，不断寻找下一个字母
    //形参分别是  字母表  使用标记   目标单词  初始位置   和第几个元素
    private boolean searchNext(char[][]board,boolean[][]hasBeen,String word,int x,int y,int n){
        if (n==word.length())return true;//已经找完了
        if (!hasBeen[x+2][y+1]&&board[x+1][y]==word.charAt(n)){
            hasBeen[x+2][y+1]=true;
            if (searchNext(board,hasBeen,word,x+1,y,n+1))return true;
            hasBeen[x+2][y+1]=false;
        }
        if (!hasBeen[x+1][y+2]&&board[x][y+1]==word.charAt(n)){
            hasBeen[x+1][y+2]=true;
            if (searchNext(board,hasBeen,word,x,y+1,n+1))return true;
            hasBeen[x+1][y+2]=false;
        }
        if (!hasBeen[x][y+1]&&board[x-1][y]==word.charAt(n)){
            hasBeen[x][y+1]=true;
            if (searchNext(board,hasBeen,word,x-1,y,n+1))return true;
            hasBeen[x][y+1]=false;
        }
        if (!hasBeen[x+1][y]&&board[x][y-1]==word.charAt(n)){
            hasBeen[x+1][y]=true;
            if (searchNext(board,hasBeen,word,x,y-1,n+1))return true;
            hasBeen[x+1][y]=false;
        }
        return false;
    }
```
