// ### 解法

// ```java
	public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        int[] count = new int[n]; // 表示到通知到第i个员工需要几分钟
        Arrays.fill(count, -1);
        count[headID] = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] != -1)
                continue;
            int p = manager[i]; //p 第 i 名员工的直属负责人
            int sum = informTime[p];
            while (count[p] == -1) {
                p = manager[p];
                sum += informTime[p];
            }
            count[i] = sum + count[p];
            res = Math.max(res, count[i]);
            p = manager[i];
            sum = count[i];
            while (count[p] == -1) {
                sum -= informTime[p];
                count[p] = sum;
            }
        }
        return res;
    }
// ```

// 思路分析：

// * 首先理解题目中标号的意义`manager[i]`表示`i`这名员工的上级的标号为`manager[i]`，`manager`数组的值的范围是`0-n-1`，但是有一个例外`manager[headID]=-1`表示编号为`headID`的员工是最高领导。`informTime[i]`表示`i`这名员工将消息传给直接下级的时间。
// * 将员工的上下级关系图画出来，员工之间用有向箭头链接，由上级指向下级，边的权值设置为上级通知下级所用的时间。这就是一个从根到叶子的树，要求的问题就转化为到叶子结点的最长路径。所以很显然进行DFS将所有到叶子的路径都遍历出来，选取最长路径的值即可。
// * 但是用树的做法需要用数据结构来表示这个树（其实说图也可以），这可能会消耗很大。
// * 换一个思路，要找最长时间，可以从领导到最下级；也可以从每一个最下级到最高领导。恰好`manager[i]`的意义就是由下级找到它的上级，这样一直跌打，都会到达`manager[headID]=-1`，这样一条路径就找到了。
// * 但是对于每一个最下级，都进行一次这样的寻找，会有大量的重复计算，因为很多下级会有共同的上级。且要知道最下级到达最高领导需要多少分钟，我们也必需知道次下级到达最高领导需要多少分钟加上次下级到达最下级的时间。
// * 所以我们可以定义一个状态量`int[] count`，`count[i]`表示`i`这个员工到达最高领导需要多少时间。然后我们求出每个`count[i]`，最大的一个就是答案。
// * 在计算`count[i]`时，是一个自底向上的过程，为了避免重复计算，我们将`count[i]`赋初值为-1，表示`i`这个员工到最高领导的时间还没计算，如果已经计算过就设置为结算结果。一个特殊的边界条件就是`count[headID] = 0;`最高领导到其自身的时间为0。
// * 具体计算过程看代码解释。

// 代码解释：

// * 6-8行，已经计算过到达最高领导所需时间的员工直接跳过。
// * 9-14行，不断找到当前员工的领导，并将这二人之间的时间累加，直到某员工到达最高领导的时间已经知道，那么`i`这个员工到达最高领导的时间就是`sum+count[p]`。第四行设置了边界条件，所以循环一定会停止。
// * 16行，更新最大时间。
// * 17-22行，`i`这个员工记录了时间，但是这条路径上还有部分他的领导没有更新，再往上将其领导的`count`进行记录。`p`到达最高领导的时间=他到最高领导的时间-`p`到他的时间。

// 运行结果：17ms

// 更多LeetCode题解请看我的[github](https://github.com/ustcyyw/yyw_algorithm)，地址https://github.com/ustcyyw/yyw_algorithm。还有别的小项目也很好玩~卑微求个小星星💖