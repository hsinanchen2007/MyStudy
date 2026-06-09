一开始误解了题意，以为是只要陆地上下左右是水就行，结果发现不是；
首先说一下想法，就会染色，把陆地的连通块找出来。然后在删除在边界的联通块；
具体找联通块的方法就是，找到一块陆地标记，再找这块陆地上下左右的陆地并标记。
取消注释就能看到图片了。
我这里先来个例子
输入  示例三
[[1,1,1,1,1,1,1],[1,0,0,0,0,0,1],[1,0,1,1,1,0,1],[1,0,1,0,1,0,1],[1,0,1,1,1,0,1],[1,0,0,0,0,0,1],[1,1,1,1,1,1,1]]
输出图片  第一行是边界联用块标记的数字
接下来是标记后的图
![TIM图片20191110211021.png](https://pic.leetcode-cn.com/a7b244f6c06fd565842d8fb2148ce72753027a485afb417c671c9f071be6193e-TIM%E5%9B%BE%E7%89%8720191110211021.png)

```
class Solution {
	int cnt=1;
    int [][]a;
    HashSet<Integer>hs=new HashSet();
	void f(int [][]a,int [][]grid,int x,int y,int m,int n)
	{
        //System.out.println(x+" "+y+" "+m+" "+n);
		if(x<m&&x>=0&&y>=0&&y<n&&grid[x][y]==0&&a[x][y]==0) 
		{
			a[x][y]=cnt;
			if(x==0||x==m-1||y==0||y==n-1) hs.add(cnt);
			f(a,grid,x+1,y,m,n);
			f(a,grid,x-1,y,m,n);
			f(a,grid,x,y+1,m,n);
			f(a,grid,x,y-1,m,n);
		}
	}
    public int closedIsland(int[][] grid) {
    	int m=grid.length,n=grid[0].length;
    	a=new int[m][n];
    	for(int i=0;i<m;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    		if(grid[i][j]==0&&a[i][j]==0)
    		{
    			f(a,grid,i,j,m,n);
    			cnt+=1;
    		}
    		}
    	}
    	/*System.out.println(hs);
    	for(int i=0;i<m;i++)
    	{
    		for(int j=0;j<n;j++)
            System.out.print(a[i][j]+" ");
    		System.out.println();
    	}*/
        return cnt-hs.size()-1;
    }
}
```
