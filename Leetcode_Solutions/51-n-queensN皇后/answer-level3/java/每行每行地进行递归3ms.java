### 解题思路
以前遇到递归的题真的是蛋疼，怎么做怎么不会，但是后来还是硬着头皮刷了好几道，现在遇到这道题，不到15分钟就过了，感觉有点开窍了。
多说无益，递归的题我觉得好好思考，多做几道题研究一下代码，久而久之就开窍了。
1.判断某个位置c[i,j]能否放置Q：这个比较简单，八个方向遍历就行了。
2.以每行为一个单位，一行一行地进行放置。例如：
    a.从c[i,0]~c[i,n-1]遍历，直到某个位置c[i,j]可以放置Q，则放置，转至下一行c[i+1,0]，并重复a步骤。
    b.a结束后，进行回溯，即还原c[i,j]为'.'，继续进行遍历。

### 代码
老话常言道：Don't BB,show me the codes.
另外，我觉得我的代码可以再优化一下，在最后整合答案的时候将n个char[]转换为String,用了o(n)的复杂度;其实应该在一开始就不必要用char[][]型，直接用String[]就可以了。但无所谓了，重要的是递归的思想。
```java
class Solution {
    private List<List<String>> anslist;
    private char[][] cboard;
    private int n;
    
    private boolean couldPlace(int row,int col)
    {
        //up check:
        for(int i=row-1;i>=0;i--)
            if(cboard[i][col]=='Q')
                return false;
        //upleft check:
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
            if(cboard[i][j]=='Q')
                return false;
        //upright check:
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
            if(cboard[i][j]=='Q')
                return false;
        //down check:
        for(int i=row+1;i<n;i++)
            if(cboard[i][col]=='Q')
                return false;
        //downleft check:
        for(int i=row+1,j=col-1;i<n&&j>=0;i++,j--)
            if(cboard[i][j]=='Q')
                return false;
        //downright check:
        for(int i=row+1,j=col+1;i<n&&j<n;i++,j++)
            if(cboard[i][j]=='Q')
                return false;
        //left check:
        for(int i=col-1;i>=0;i--)
            if(cboard[row][i]=='Q')
                return false;
        //right check:
        for(int i=col+1;i<n;i++)
            if(cboard[row][i]=='Q')
                return false;
        return true;
    }
    
    private void place(int row,int col)
    {
        if(row>n-1)
        {
            List<String> list=new ArrayList<>();
            for(int i=0;i<n;i++)
            {
                String s=String.valueOf(cboard[i]);
                list.add(s);
            }
            anslist.add(list);
            return;
        }
        for(int i=col;i<n;i++)
        {
            if(couldPlace(row,i))
            {
                cboard[row][i]='Q';
                place(row+1,0);
                cboard[row][i]='.';
            }
        }
    }
    public List<List<String>> solveNQueens(int n) {
        
        this.n=n;
        cboard=new char[n][n];
        anslist=new ArrayList<>();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cboard[i][j]='.';
        place(0,0);
        return anslist;
    }
}
```