### 解题思路
1、假设我们从任意一个坐标(row,column)出发，如果上下左右都遍历完毕，都没有匹配的，那么说明该坐标没有存在该字符串的位置,否则就返回结果true
     记上面的函数为f(row,column)
2、那么整个数组是否存在可匹配的算法如下:
      int row = 0,column=0;
      while(row<maxRow&&column<maxColumn){
              if(f(row,column)){
                   return true;
              }
              //向右平移一步，当碰到右边界的时候进行折行
             if(column==maxColumn-1){
                       row+=1;
                       column=0;
             }else{
                      column+=1;
             }
      }
3、问题简化为如何判断任意一个坐标是否存在匹配指定的字符串，这里就是一个经典的回溯算法，我们需要一个boolean[][] isVisited,和wordIndex来标记目前匹配的位置。注意到java引用传值问题，这里wordIndex不能用Integer,因为当它赋值为另外一个值的时候，原来的值就不见了，所以我们这里用AtomicInteger来标记访问过的wordIndex
        

         定义f(row,column)辅助函数为:
        //row column代表当前的坐标,maxRow,maxColumn为数组的最大行边界和最大列边界，这样传进来避免重复取最大行数值和最大列数值
         //wordIndex表示当前word的匹配的索引，count表示匹配的个数   
     boolean helpIsExisted(char[][] board, boolean[][] isVisted,int row,int column,int maxRow,int maxColumn,String word,AtomicInteger wordIndex,int count){
                  //超出了行边界和列边界
                  if(row<0||row>=maxRow){
                        return false;
                   }
                   if(column<0||column>=maxColumn){
                          return false;
                   }
                    //标明该节点曾经访问过
                   if(isVisited[row][column]=true){
                          return false;
                   }
                   if(board[row][column]==word.charAt(wordIndex.get())){
                           count+=1;
                           if(count==word.length()){
                                 return true;
                           }else{
                             //将当前row,column标记为已经访问过，同时匹配下一个索引
                              isVisted[row][column]=true;
                              wordIndex.addAndIncrement();
                              //从上下左右四个方向去递归遍历
                              boolean up =  helpIsExisted(board,isVisted,row-1,column,maxRow,maxColumn,word,wordIndex,count);
                            if(up){return true;}
                             boolean down =  helpIsExisted(board,isVisted,row+1,column,maxRow,maxColumn,word,wordIndex,count);
                            if(down){return true;}
                            boolean left =  helpIsExisted(board,isVisted,row,column-1,maxRow,maxColumn,word,wordIndex,count);
                            if(left){return true;}
                            boolean right =  helpIsExisted(board,isVisted,row,column+1,maxRow,maxColumn,word,wordIndex,count);
                            if(right){return true;}
                            //如果四个方向都没有找到，说明该row,column代表的节点不匹配,wordIndex-1,退回到之前的节点继续寻找
                            isVisitied[row][column] = false;
                            wordIndex.decrementAndGet();
                          }
                    
                   }
                  return false;
           
          }

4、根据第三步，步骤2的函数调用可以改为:
           helpIsExisted(board,isVisited,row,column,maxRow,maxColumn,word,wordIndex,0);
                  


### 代码

```java
class Solution {

   private void initIsVisited(boolean[][] isVisted) {
        int maxRow = isVisted.length;
        int maxColumn = isVisted[0].length;
        for(int i = 0;i<maxRow;i++){
            for(int j = 0;j<maxColumn;j++){
                isVisted[i][j] = false;
            }
        }
    }

    private boolean helpExist(char[][] board, String word, AtomicInteger wordIndex, int row, int column, int maxRow, int maxColumn, int count, boolean[][] isVisted) {
        if (row < 0 || row >= maxRow) {
            return false;
        }
        if (column < 0 || column >= maxColumn) {
            return false;
        }
        if (isVisted[row][column] == true) {
            return false;
        }
        if (board[row][column] == word.charAt(wordIndex.get())) {
            count += 1;
            if (count == word.length()) {
                return true;
            } else {
                wordIndex.addAndGet(1);
                isVisted[row][column] = true;
            }
            boolean up = helpExist(board, word, wordIndex, row - 1, column, maxRow, maxColumn, count, isVisted);
            if(up){
                return true;
            }
            boolean down = helpExist(board, word, wordIndex, row + 1, column, maxRow, maxColumn, count, isVisted);
            if(down){
                return true;
            }
            boolean left = helpExist(board, word, wordIndex, row, column - 1, maxRow, maxColumn, count, isVisted);
            if(left){
                return true;
            }
            boolean right = helpExist(board, word, wordIndex, row, column + 1, maxRow, maxColumn, count, isVisted);
            if(right){
                return true;
            }
            wordIndex.decrementAndGet();
            isVisted[row][column] = false;
        }
        return false;
    }

    /**
     * 循环board 从任意一组坐标(i,j)出发,往四个方向寻找,如果发现了word的对应顺序的字符，则将count+=1
     * 如果count==word  退出
     *
     * @param board
     * @param word
     * @return
     */
    public boolean exist(char[][] board, String word) {
        int maxRow = board.length;
        int maxColumn = board[0].length;
        boolean[][] isVisted = new boolean[maxRow][maxColumn];
        initIsVisited(isVisted);
        AtomicInteger wordIndex = new AtomicInteger(0);
        int row = 0, column = 0;
        boolean result = false;
        while (row < maxRow && column < maxColumn) {
            result = helpExist(board, word, wordIndex, row, column, maxRow, maxColumn, 0, isVisted);
            if (result) {
                break;
            } else {
                //向右移动一步
                if (column == maxColumn - 1) {
                    //到达右边界,向下移动一行
                    row += 1;
                    column = 0;
                } else {
                    column += 1;
                }
                //证明以row column为坐标的探索失败
            }
        }
        return result;
    }
}
```