一看要建树就知道应该递归，主要在于递归的终止条件（是叶子节点），还有递归传递的参数，为了清晰这里我将开始行、开始列、结束行、结束列的序号都作为形参了，当然因为开始行=开始列，结束行=结束列你也可以少传两个参数
```
public static Node construct(int[][] grid) {
        return cons(grid,0,grid.length-1,0,grid.length-1);
    }
    public static Node cons(int[][] grid,int startRow,int endRow,int startCol,int endCol)
    {
        boolean val;
        if (grid[startRow][startCol]==0)
            val=false;
        else val=true;
        Node root=null;
        if (isLeaf(grid,startRow,endRow,startCol,endCol))
        {
            root=new Node(val,true,null,null,null,null);
            return root;
        }else {
            root=new Node(val,false,null,null,null,null);
            root.topLeft=cons(grid,startRow,startRow+(endRow-startRow)/2,startCol,startCol+(endCol-startCol)/2);
            root.topRight=cons(grid,startRow,startRow+(endRow-startRow)/2,startCol+(endCol-startCol)/2+1,endCol);
            root.bottomLeft=cons(grid,startRow+(endRow-startRow)/2+1,endRow,startCol,startCol+(endCol-startCol)/2);
            root.bottomRight=cons(grid,startRow+(endRow-startRow)/2+1,endRow,startCol+(endCol-startCol)/2+1,endCol);
            return root;
        }
    }
    public static boolean isLeaf(int[][] grid,int startRow,int endRow,int startCol,int endCol)
    {
        int cons=grid[startRow][startCol];
        for (int i=startRow;i<=endRow;i++)
            for (int j=startCol;j<=endCol;j++)
            {
                if (grid[i][j]!=cons)
                    return false;
            }
        return true;
    }
```