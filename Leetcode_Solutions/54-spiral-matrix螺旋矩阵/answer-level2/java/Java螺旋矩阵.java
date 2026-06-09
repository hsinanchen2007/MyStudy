![QQ图片20200311175141.png](https://pic.leetcode-cn.com/3d64757d51a4ed7e00e5a160b3178b64063bbb9ab7f3fa1f71bf5db1cb509291-QQ%E5%9B%BE%E7%89%8720200311175141.png)
第一次写题解嘻嘻，虽然我的方法也不是很好。
建立了一个辅助数组判断某个数是不是已经遍历过，循环m*n次，从第一个元素开始，先把当前元素放入待返回的List，首先判断右边是否有未被遍历的元素，如果有，更改坐标，跳出循环(continue)；如果没有，就判断下边；依次左边和上边......直到判断出来上边有某个未被遍历的元素，此时需要一直往上遍历，直到遇到一个已经被遍历过的元素停止，然后再判断右边是否有未被循环的元素......剩余的同上，直到遍历完所有元素。
```
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans=new ArrayList<>();
        int m=matrix.length;
        if(m==0)
        return ans;
        int n=matrix[0].length;
        int array[][]=new int[m][n];//建立一个辅助矩阵，判断某点有没有被走过
        int x=0;//当前x坐标
        int y=0;//当前y坐标
        int i=0;
        int sigh=0;//标志，标志着是不是已经到达向上走的情况
        for(;i<m*n;i++)
        {
            ans.add(matrix[x][y]);
            array[x][y]=1;
            if(sigh==1&&x-1>=0&&array[x-1][y]==0)
            {
                x--;
                continue;
            }
            if(y+1<n&&array[x][y+1]==0)
            {
                sigh=0;
                //ans.add(matrix[x][y+1]);
                y++;
                continue;
            }
            else if(x+1<m&&array[x+1][y]==0)
            {
                x++;
                continue;
            }
            else if(y-1>=0&&array[x][y-1]==0)
            {
                y--;
                continue;
            }
            else
            {
                sigh=1;
                x--;
                continue;
            }
        }
        return ans;
    }
}
```

