### 解题思路
用的官方解法
利用对角线跟次对角线的属性，相加为常量跟相减为常量，利用该常量作为下标的数组存储boolean值，来表示该对角线或次对角线是否有Q，用column表示该列是否有对角线
然后从上往下递归，进行发射回溯，如果到达N行，为终点，结果+1
### 代码

```java
class Solution {
    int res=0;
    public int totalNQueens(int n) {
            int[] column=new int[n];
            int[] diagonals=new int[2*n];
            int[] hill_diagonals=new int[4*n];
//        nt res=0;
        helper(0,n,0,column,diagonals,hill_diagonals);
        return  res;

    }
    public boolean isValid(int[] column, int[] diagonals, int[] hill_diagonals,int row, int col,int n)
    {
        int res=column[col]+diagonals[row+col]+hill_diagonals[row-col+2*n];
        return res==0? true:false;
    }
    public void helper(int start,int n,int count, int[] column, int[] diagonals, int[] hill_diagonals)
    {
        if(start>=n)
        {
            res++;
            return;
        }
//            return count;
        for(int i=0;i<n;i++)
        {
            if (isValid(column,diagonals,hill_diagonals,start,i,n))
            {
                hill_diagonals[start-i+2*n]=1;
                diagonals[start+i]=1;
                column[i]=1;

                helper(start+1,n,count,column,diagonals,hill_diagonals);

                hill_diagonals[start-i+2*n]=0;
                diagonals[start+i]=0;
                column[i]=0;
            }
        }
    }
}

```