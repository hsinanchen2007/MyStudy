### 解题思路
动态规划的核心思想一直都是建立一个数据结构来存储每次计算的结果,然后利用遍历来逐渐完善这个数组.

### 代码

```c
// 这个数组就是用来作为存储的数据结构.
// 注意提示信息
unsigned int res_cache[51][51] = {0};

// res_cache表示以 start 和 end 为底边对其余所有点进行划分
unsigned int dp(int *A, int Asize, int start, int end)
{
    int i;
    // n用来记录传进来数量
    int n = end - start;
    unsigned int res;
    // 建立一个中间变量
    unsigned int tmp;
    // 当n小于2的时候, 数组里面只有0-1,无法构成三角形
    if(n<2) return 0;
    // 这句我还在思考
    if(res_cache[start][end]>0) return res_cache[start][end];
    // 当 n=2 的时候,那么就有这个值就是三条边的乘积
    if(n==2)
    {   // start = 0 end = 2
        // 三角形的值套用公式就行
        res = A[start] * A[start+1] * A[end];
        // 写入三角形的值
        res_cache[start][end] = res;
        return res;
    }
    res = -1;
    for(i=start+1; i<end; i++)
    {
        // 计算以start和end为底边和i生成的三角形的值
        tmp = A[start] * A[i] * A[end];
        // 如果 i 等于 end-1,的时候end和end-1构成了一条底边
        if(i == end-1)
        {
            // 这时候strat - end-1 - end 组成了一个三角形
            // 同时end 和 end-1 已经被占用,只需要添加start和end-1 和其余边组成的新三角形即可
            tmp += dp(A, Asize, start, i);
        }
        else
        {
            // 否则 start-i 和 i-end 均生成了一条边这样就需要去以这两条边为底,去寻找新的最小值了
            tmp += dp(A, Asize, start, i) + dp(A, Asize, i ,end);
        }
        if(res > tmp)
        {
            // 如果计算代价的结果小于tmp,那么我们用res保存里面最小的代价
            res = tmp;
        }
    }  
    // 最后将这个最小代价写入数组中存储
    res_cache[start][end] = res;
    // 返回这个最小代价
    return res;
}



int minScoreTriangulation(int* A, int ASize)
{
    memset(res_cache, 0, sizeof(res_cache));
    return dp(A, ASize, 0, ASize-1);
}
```