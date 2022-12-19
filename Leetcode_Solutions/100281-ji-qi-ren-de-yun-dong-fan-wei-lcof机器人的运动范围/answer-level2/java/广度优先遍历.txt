### 解题思路
此处撰写解题思路
遍历过程中遍历过的用数组记录，且数组增位和与数组大小的关系为，当数组大小为i增位和为si，i+1位的增位和为，如果i+1%10等于0，则为si-8,否则为si++1.

### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        int res=0;
        boolean[][] visit=new boolean[m][n];
        Queue<int []> queue=new LinkedList<int[]>();
        queue.add(new int []{0,0,0,0});
        while(queue.size()>0){
            int[] s=queue.poll();
            int  i=s[0],j=s[1],l=s[2],p=s[3];
            if(i>=m||j>=n||l+p>k||visit[i][j]==true)continue;
            res++;
            visit[i][j]=true;
            queue.add(new int[] {i,j+1,l,(j+1)%10==0? p-8:p+1});
            queue.add(new int[] {i+1,j,(i+1)%10==0? l-8:l+1,p});
        }
        return res;

    }
    
}
```