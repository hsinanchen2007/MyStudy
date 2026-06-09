### 解题思路
这个代码是大佬的
首先明确可达解的达到条件
![QQ截图20200408140626.png](https://pic.leetcode-cn.com/55281329a9ad45bfc6e3f8f80a5d47172d533afea1d31fc2e13c70eefba5b606-QQ%E6%88%AA%E5%9B%BE20200408140626.png)
![QQ截图20200408140641.png](https://pic.leetcode-cn.com/04b269da925aa1338ce000104788440af820742fabb0cd459826e65d267d95b3-QQ%E6%88%AA%E5%9B%BE20200408140641.png)

广度优先搜索：
要借助辅助数组visited和队列queue
（1）如果队列不为空，则弹出队列头部的元素，判断此元素是否符合终止条件，如果符合终止条件则跳过此次循环继续continue；如果不符合终止条件。将遍历到的位置的右和下位置的索引及数位和存入队列中。
（2）如果队列为空，则表示已到可达范围边缘，此外空间不可达。跳出循环，返回可达范围即可。
```java
class Solution {
    public int movingCount(int m, int n, int k) {
        boolean[][]visited=new boolean[m][n];//辅助数组，保存某个位置是否遍历到并属于运动范围
        //直到当前位置所涉及到的位置，存储（i,j,si,sj）即行列索引值，行索引的数位值，列索引的数位值
        Queue<int[]>queue=new LinkedList<>();
        queue.add(new int[]{0,0,0,0});
        int res=0;
        while (queue.size()!=0){
            int[]cur=queue.poll();
            int i=cur[0];int j=cur[1]; int si=cur[2];int sj=cur[3];
            if(i>=m||j>=n||si+sj>k||visited[i][j])continue;
            visited[i][j]=true;
            res++;
            queue.add(new int[]{i+1,j,(i+1)%10==0?(si-8):(si+1),sj});
            queue.add(new int[]{i,j+1,si,(j+1)%10==0?(sj-8):(sj+1)});
        }
        return res;
    }
}
```
深度优先搜索：
向一个方向一直搜索下去，直到遇到不符合条件的返回，再向另一个方向搜索。
（1）返回的条件为i,j超出索引最大值或者数位和大于k或者当前位置已被标记。
（2）运用递归以某个位置为起点反复调用本身，最初的起点为（0,0）
（3）借助辅助数组visited标识已搜索的位置，
```java
class Solution {
    int m;
    int n;
    int k;
    boolean[][]visited;
    //深度优先搜索
    public int movingCount(int m, int n, int k) {
        this.m=m;
        this.k=k;
        this.n=n;
        this.visited=new boolean[m][n];
        return dfs(0,0,0,0);
    }

    private int dfs(int i,int j,int si,int sj){
        if(i>=m||j>=n||(si+sj)>k||visited[i][j])return 0;
        visited[i][j]=true;
        return 1+dfs(i+1,j,(i+1)%10==0?si-8:si+1,sj)+dfs(i,j+1,si,(j+1)%10==0?sj-8:sj+1);
    }
}
```



