直接对着代码看注释吧
```java
class Solution {
    char[][]board;
    String word;
    //设置数组判断这个位置是否走过。
     boolean[][]bb;
    public boolean exist(char[][] board, String word) {
        this.board=board;
        this.word=word;
    //在循环外声明判断数组即可，递归会重置数组。
    //即：当我们i循环到下一个时，数组之前赋值的值会全部重置。
  bb =new boolean[board.length][board[0].length];
        //回溯＋递归
        for(int i=0;i<board.length;i++)
        {
            for(int j=0;j<board[0].length;j++)
            {
              
                if(find(i,j,0)==true)
                    return true;
            }
        }
        return false;
    }
    public boolean find(int i,int j,int word_index){
        //需要让他不能走之前走过的路走过的路boolean型数组设置为true;
        if(word_index==word.length())
            return true;
        if(i<0||i>=board.length||j<0||j>=board[0].length||
           board[i][j]!=word.charAt(word_index)||bb[i][j]==true)
            return false;
        else{
            bb[i][j]=true;
        }
        boolean res= find(i-1,j,word_index+1)||find(i+1,j,word_index+1)||
            find(i,j+1,word_index+1)||find(i,j-1,word_index+1);
        //当我们把ij位置的所有都找完之后，会到这一步，不管成功与否，我们都需要
        //把ij这个位置的可走信息变成false（可走），因为这一步之后，会回溯至上一个位置的
        //另一种路线，而另一种路线是可以走ij这个位置的。
          bb[i][j]=false;
        return res;
    }
}
```