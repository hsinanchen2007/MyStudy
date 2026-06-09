### 解题思路
典型的动态规划类问题，问题模型为：

**每一次不同的选择，都会产生后续不同的结果（指数级增长），而且不是每次选择最优就能得到最优（非贪心）。**

符合思维习惯的解法就是使用DFS遍历各种可能，通过记忆化进行剪枝。

DFS的难点在于构造递归函数，本题递归函数构造为：

**根据位置id和M，计算和本次奇偶相同次的结果之和。**

其中，求解“计算和本次奇偶相同次的结果之和”，通过总数减去下一次迭代函数返回值实现。

注意总数需要在调用迭代函数前减小，然后调用完成后恢复。

![image.png](https://pic.leetcode-cn.com/c8258bd913d42755304bd5e60f1d66d28495ff06e4f0fe29be4604a6d8340f49-image.png)


### 代码

```c
/*
 * @lc app=leetcode.cn id=1140 lang=c
 *
 * [1140] 石子游戏 II
 */

// @lc code=start
#define M0_SIZE         100
#define M1_SIZE         100
#define MMAX(a, b)      ((a) > (b)? (a) : (b))

int *ppiles;
int psize;
int total;

int memo[M0_SIZE][M1_SIZE];

//int all_num = 0;
//int real_num = 0;

int helper(int id, int m)
{
    //all_num++;
    if(memo[id][m] != 0)
    {
        return memo[id][m] - 1;
    }
    //real_num++;

    if(id + 2 * m - 1 >= psize - 1)
    {
        memo[id][m] = total + 1;
        return total;
    }

    int max = 0;

    for(int i = 1; i <= 2 * m; i++)
    {
        int sum = 0;
        for(int j = id; j <= id + i - 1; j++)
        {
            sum += ppiles[j];
        }

        int nm = MMAX(m, i);

        total -= sum;
        int nsum = helper(id + i, nm);
        total += sum;

        max = MMAX(max, total - nsum);
    }

    memo[id][m] = max + 1;
    return max;
}

//【算法思路】DFS+memo。DFS遍历1~2M的可能；问题的决定因素是位置下标id，上限M，因此建立二维memo记录结果进行加速。
// dfs构造为给定id，m值，找到奇/偶最大和。
int stoneGameII(int* piles, int pilesSize){
    if(pilesSize <= 2)
    {
        return (pilesSize == 1)? piles[0] : piles[0] + piles[1];
    }

    ppiles = piles;
    psize = pilesSize;

    for(int i = 0; i < M0_SIZE; i++)
    {
        for(int j = 0; j < M1_SIZE; j++)
        {
            memo[i][j] = 0;
        }
    }

    total = 0;
    for(int i = 0; i < pilesSize; i++)
    {
        total += piles[i];
    }

    int res =  helper(0, 1);
    //printf("all = %d, real = %d\n", all_num, real_num);
    return res;
}


// @lc code=end


```