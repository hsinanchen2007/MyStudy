### 解题思路
使用深度优先解决

### 代码

```java
class Solution {
    //使用栈
    public int movingCount(int m, int n, int k) {
        Stack<int[]> stack=new Stack<>();
        int result=0;
        stack.push(new int[]{0,0});
        //作为标记数组元素为1说明已经走过,数组元素为0说明没有走过
        int[][] counts=new int[m][n];
        counts[0][0]=1;
        while(!stack.isEmpty()){
            result++;
            int[]nums=stack.pop();
            int a=nums[0],b=nums[1];
            //判断四个方向,可以使用for循环合在一起写
            //四个条件行列都要判断边界情况,并且对应counts[x][y]==0没有走过的情况,
            //并且满足行坐标和列坐标的数位之和小于等于k
            if(a-1>=0 && inspect(a-1,b,k) && counts[a-1][b]==0){
                stack.push(new int[]{a-1,b});
                counts[a-1][b]=1;
            }
            if(a+1<m && inspect(a+1,b,k) && counts[a+1][b]==0){
                stack.push(new int[]{a+1,b});
                counts[a+1][b]=1;
            }
            if(b-1>=0 && inspect(a,b-1,k) && counts[a][b-1]==0){
                stack.push(new int[]{a,b-1});
                counts[a][b-1]=1;
            }
            if(b+1<n && inspect(a,b+1,k) && counts[a][b+1]==0){
                stack.push(new int[]{a,b+1});
                counts[a][b+1]=1;
            }
        }
        return result;
    }
    // 行坐标和列坐标的数位之和是否小于等于k
    private boolean inspect(int x,int y,int k) {
        int sum=0;
        while(x>=10||y>=10){
            if(x<10){
                sum=sum+y%10;
                y=y/10;
            }else if(y <10){
                sum=sum+x%10;
                x=x/10;
            }else{
                sum=sum+y%10+x%10;
                y=y/10;
                x=x/10;
            }
        }
        sum=sum+x+y;
        return sum<=k;
    }
}
class Solution {
    int m,n,k;
    //使用递归
    public int movingCount(int m, int n, int k) {
        int[][] counts=new int[m][n];
        this.m=m;
        this.n=n;
        this.k=k;
        return dfs(counts,0,0,k);
    }
    private int dfs(int[][]counts,int x,int y,int k){
        //判断四个方向是否满足
        if(x<0||x>=m||y<0||y>=n||!inspect(x,y,k)||counts[x][y]==1){
            return 0;
        }
        counts[x][y]=1;
        return 1+dfs(counts,x-1,y,k)+dfs(counts,x+1,y,k)+
                    dfs(counts,x,y-1,k)+dfs(counts,x,y+1,k);
    }
    // 判断是否满足k
    private boolean inspect(int x,int y,int k) {
        int sum=0;
        while(x>=10||y>=10){
            if(x<10){
                sum=sum+y%10;
                y=y/10;
            }else if(y <10){
                sum=sum+x%10;
                x=x/10;
            }else{
                sum=sum+y%10+x%10;
                y=y/10;
                x=x/10;
            }
        }
        sum=sum+x+y;
        return sum<=k;
    }
}
```