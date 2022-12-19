因为做出的时间和空间复杂度较好，简单记一下笔记。

这是一道最经典的动态规划问题，核心思想就是子问题的划分。记f(11)为问题的解，那么这个零钱面额coins[i] = {1, 2, 5}可以划分成f(11-5), f(11-2), f(11-1)三个子问题，子问题找到了，目标就是寻找递归的结束条件。易知f(0) = 0, f(coins[i]) = 1, f(amount < min(coins[i])) = -1，即子问题划分到n=0， 或者刚好等于零钱面额时返回， 当小于最小面额时进行错误处理。

即状态转移方程为f(0)= 0, f(n) = 1 + min(f(n - coins[i])), n>0。

所以构建一个大小为n+1的数组dp用来存储当n=i时，问题的最优解。

![QQ图片20191011172006.png](https://pic.leetcode-cn.com/02326d5346951744eafe3dd351d4df416e2df190d8f15852678e6d9bf57d63bb-QQ%E5%9B%BE%E7%89%8720191011172006.png)

如图f(6)的分解过程，f(9), f(10)同理。这里注意已经将dp[6], dp[4], dp[3]的结果算出，f(9)和f(10)中遇到这三个节点就可以直接将存储的结果返回，不必重新计算，这也是使用备忘录法的好处。

然后这种题的处理要点就是可以将coins数组排序，即贪心的思想从大数向小数递归，比较容易得到正确答案，简化计算时间。

不能找开零钱的情况有两种，第一种是直接小于最小面额数值，直接返回；第二种是任意零钱面额值大于自己，那么这种零钱面额肯定是不计入考虑的，比如图中节点为4，那么只能划分成f(4-1), f(4-2), 面值5不进行考虑。

```
int min_size;
int error = 0x7ffffffe;

int dynamic_planning(vector<int>& coins, int* dp, int n){
    if(n == 0)
        return 0;
    if(dp[n] != -1)
        return dp[n];
    if(n < min_size)
        return error;

    int min = 0x7FFFFFFF; 
    for (int i = coins.size() - 1; i >= 0; i--){
        int tmp;
        if(n - coins[i] >= 0){
            int ret = dynamic_planning(coins, dp, n - coins[i]);
            tmp = (ret == error) ? error : ret + 1;
        }
        else
            tmp = error;
            
        if(min > tmp){
            min = tmp;
            dp[n] = tmp;
        }
    }

    return dp[n];
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int *dp = new int[amount+1]();//initialize

    for (int i = 1; i <= amount; i++){//f(0) = 0
        dp[i] = -1;
    }
    
    //if unsorted
    sort(coins.begin(), coins.end());

    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= amount)
            dp[coins[i]] = 1;
    }

    min_size = coins[0];

    int min_num = dynamic_planning(coins, dp, amount);

    delete[] dp;

    if(min_num == error)
        return -1;
    return min_num;
}
```
