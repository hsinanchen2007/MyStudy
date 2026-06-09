自底向上自然比自顶向下更好，其他解题中写得很好，只是写中规中矩的方法
```
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if(triangle.size()==0)
            return 0;
        int [][] results=new int[triangle.size()][]; //存放到triangle[i][j]的最小路径和
        int [][] triangle_=new int[triangle.size()][]; //将triangle转化为数组
        
        //初始化results和triangle_
        for(int i=0;i<triangle.size();i++)
        {
            results[i]=new int[i+1];
            triangle_[i]=new int[i+1];
        }
        //复制triangle中元素到triangle_
        for(int i=0;i<triangle.size();i++)
            for(int j=0;j<=i;j++)
                triangle_[i][j]=triangle.get(i).get(j);
        
        int i=0;
        for(;i<triangle.size();i++)
            for(int j=0;j<triangle.get(i).size();j++)
            {
                //以下为状态转移方程
                if(i==0&&j==0)
                {
                    results[0][0]=triangle_[0][0]; 
                }
                else if(j==0)
                    results[i][j]=results[i-1][j]+triangle_[i][j];
                else if(i==j)
                    results[i][j]=results[i-1][j-1]+triangle_[i][j];
                else 
                {
                    results[i][j]=Math.min(results[i-1][j-1],results[i-1][j])+triangle_[i][j];
                }
            }
        //找出results中最后一行中最小值作为结果
        int min=results[i-1][0];
        for(int t=1;t<i;t++)
            if(results[i-1][t]<min)
                min=results[i-1][t];
        return min;
    }
}
```
