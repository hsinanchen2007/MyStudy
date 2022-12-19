题目中有一个计算横纵坐标数位之和的操作，这不是题目的关键点，将这个计算数位之和的方法封装起来不要干扰主要的解题逻辑。

```java
public int sums(int x,int y){
    int ans=0;
    while (x != 0) {
        ans+=x%10;
        x/=10;
    }
    while (y != 0) {
        ans+=y%10;
        y/=10;
    }
    return ans;
}
```

### 思路一：深搜

想法比较直接，就是从起点开始用深搜的方式遍历矩阵，控制深搜边界的同时判断当前访问的位置数位和是否小于等于k，并且需要一个标记数组记录每个位置的访问情况，防止重复计算。

虽然题目说是上下左右都可以移动，但是我们从左上角作为起点开始只能向右或者向下移动，如果发生向左或者向上那一定是重复的搜索。

```java
int m,n,k;
public int movingCount(int m, int n, int k) {
    this.m=m;
    this.n=n;
    this.k=k;
    //标记访问过的位置
    boolean[][] visited=new boolean[m][n];
    return dfs(0,0,0,visited);
}

/**
     * 深搜
     * @param i 横坐标
     * @param j 纵坐标
     * @param sum   坐标数位和
     * @param visited   标记数组
     * @return
     */
private int dfs(int i, int j, int sum, boolean[][] visited) {
    //如果 坐标越界 或者 数位和大于k 或者 已经访问过，则停止当前方向的深搜
    if (i==m||j==n||sum>k||visited[i][j])return 0;
    //标记为已访问
    visited[i][j]=true;
    //向下或者向右深搜
    return 1+dfs(i+1,j,sums(i+1,j),visited)+dfs(i,j+1,sums(i,j+1),visited);
}

//计算数位和
public int sums(int x,int y){
    int ans=0;
    while (x != 0) {
        ans+=x%10;
        x/=10;
    }
    while (y != 0) {
        ans+=y%10;
        y/=10;
    }
    return ans;
}
```

时间复杂度：O(mn)	最坏情况，遍历矩阵。**复杂度不敢确定，不知道需不需要乘上计算位数和的时间。**

### 思路二：广搜

其实和深搜的思路一样，只是换了一个搜索的方式，采用广搜的方式寻找符合要求的位置。

```java
//时间复杂度：O(mn)
public int movingCount(int m, int n, int k) {
    //队列保存坐标
    Queue<int[]> queue=new ArrayDeque<>();
    //标记数组
    boolean[][] visited=new boolean[m][n];
    //广搜
    queue.add(new int[]{0,0});
    int count=0;
    visited[0][0]=true;
    while (!queue.isEmpty()) {
        int[] poll = queue.poll();
        count++;
        //向下、向右寻找符合要求的位置入队并标记访问状态
        //不越界 并且 数位和小于等于k 并且 未访问过
        if (poll[0] + 1 < m
            && sums(poll[0] + 1, poll[1]) <= k
            &&!visited[poll[0]+1][poll[1]]){
            queue.add(new int[]{poll[0]+1,poll[1]});
            visited[poll[0]+1][poll[1]]=true;
        }
        if (poll[1] + 1 < n
            && sums(poll[0], poll[1] + 1) <= k
            &&!visited[poll[0]][poll[1] + 1]){
            queue.add(new int[]{poll[0],poll[1]+1});
            visited[poll[0]][poll[1]+1]=true;
        }
    }
    return count;
}
//计算数位和
public int sums(int x,int y){
    int ans=0;
    while (x != 0) {
        ans+=x%10;
        x/=10;
    }
    while (y != 0) {
        ans+=y%10;
        y/=10;
    }
    return ans;
}
```

时间复杂度：O(mn)	最坏情况，遍历矩阵。**复杂度不敢确定，不知道需不需要乘上计算位数和的时间。**

---

本人菜鸟，有错误请告知，感激不尽！

更多题解和源码:[github](https://github.com/Jerrymouse1998/learning-record-of-leetcode) 