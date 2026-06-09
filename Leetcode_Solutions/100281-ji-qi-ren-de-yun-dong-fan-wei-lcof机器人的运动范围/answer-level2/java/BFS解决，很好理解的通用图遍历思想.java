### 解题思路
BFS解决，时间复杂度不太优越啊。。。
但是总觉得对于图这种结构，BFS思路非常好理解，非常清晰，看到这种题型，第一个想起来的肯定是广搜。
有时候可能好理解比时间复杂度更重要。
**需要定义一个队列Queue,和一个与原图同大的visit表示一个点是否被访问过**
先把起点(0,0)放进去，通过向右向下派生新点来模拟机器人走路
由于是K的限制，所以如果一个点满足K的限制，那么他的左侧和上侧一定满足K的限制，而且起点是最左上的(0,0)所以只需要考虑右和下就可以。
（或者可以这样想，一个点是通过右下派生出另一个点，那么该点一定是通过其左上派生出来的，那么他的左上就不用再考虑了，是一种扩散的感觉）
**入列条件是，不越界且满足K的限制且未被访问过，在入列时改变该点的visit以防止被重复访问，重复入队列，重复派生点**

### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        if(k==0){
            return 1;
        }
        Queue<int[]> queue = new LinkedList<int[]>();
        queue.add(new int[]{0,0});//放入原点(0,0)
        int[][] visit = new int[m][n];
        visit[0][0]=1;
        int[] dx = {1,0};
        int[] dy = {0,1};
        int res=1;
        while(!queue.isEmpty()){
            int[] cur = queue.poll();
            int x = cur[0];
            int y = cur[1];
            for(int i=0;i<2;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(check(newx,newy,m,n,k)&&visit[newx][newy]==0){
                    queue.add(new int[]{newx,newy});
                    visit[newx][newy]=1;
                    res++;
                }
            }
        }
        return res;
    }//使用BFS遍历整个数组，从（0，0）开始只考虑向下向右即可

    public boolean check(int i,int j,int m,int n,int k){
        if(i<0||i>=m||j<0||j>=n){
            return false;
        }else{
            int sum=0;
            while(i!=0){
                sum=sum+i%10;
                i=i/10;
            }
            while(j!=0){
                sum=sum+j%10;
                j=j/10;
            }
            return sum <= k;
        }
    }//判断一个位置是否为不可达位置
}
```