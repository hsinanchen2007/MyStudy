### 解题思路
递归记录可以到达的路径，最后计算路径即可

### 代码

```java
class Solution {
    private static int[][] r;
    public int movingCount(int m, int n, int k) {
        r = new int[m][n];
        int sum=0;
        r[0][0]=1;
        move(m,n,0,0,k);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(r[i][j]==1){
                    sum++;
                }
            }
        }
        return sum;
    }

    public void move(int m, int n,int i,int j,int k){
        if(sum(i,j)<=k){
            r[i][j]=1;
            if(i>0){
                if(r[i-1][j]==0)
                    move(m,n,i-1,j,k);
            }
            if(j>0){
                if(r[i][j-1]==0)
                    move(m,n,i,j-1,k);
            }
            if(i<m-1){
                if(r[i+1][j]==0)
                    move(m,n,i+1,j,k);
            }
            if(j<n-1){
                if(r[i][j+1]==0)
                    move(m,n,i,j+1,k);
            }
        }else{
			r[i][j]=-1;
		}
    }

    public int sum(int a,int b){
        int sum=0;
        sum+=a/100;
        sum+=(a%100)/10;
        sum+=a%10;
        sum+=b/100;
        sum+=(b%100)/10;
        sum+=b%10;
        return sum;
    }
}
```