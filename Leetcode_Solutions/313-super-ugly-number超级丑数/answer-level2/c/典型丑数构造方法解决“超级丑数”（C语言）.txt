### 解题思路
丑数的经典构造方法为：

1.为素数列表中的每个素数构建一个id

2.遍历素数列表，列表中每个素数可以构造的下一个最小的新丑数为prime * results[id];

3.选取所有下一个最小的新丑数中的最小值作为真正的新丑数(注意最小值有可能有重复，直接更新重复最小值的素数的id)

4.更新取得最小值的素数id

5.循环处理，直到得到n个结果，并将其返回

![image.png](https://pic.leetcode-cn.com/b88d7edcd136393b3dc9349415bd1b0219615a7ac77c906153e8fe9b7d5d9242-image.png)


### 代码

```c
/*
 * @lc app=leetcode.cn id=313 lang=c
 *
 * [313] 超级丑数
 */

// @lc code=start

//【算法思路】数学。丑数的构造方法。
int nthSuperUglyNumber(int n, int* primes, int primesSize){
    if(n == 1)
    {
        return 1;
    }

    int *res = (int *)calloc(n, sizeof(int));
    int rsize = 0;

    int *pids = (int *)calloc(primesSize, sizeof(int));

    res[rsize++] = 1;

    while(rsize < n)
    {
        // 选择最小的(素数*res[pid])，更新其pid
        int min = INT_MAX;
        int id = 0;

        for(int i = 0; i < primesSize; i++)
        {
            int tmin = primes[i] * res[ pids[i] ];

            if(tmin < min)
            {
                min = tmin;
                id = i;
            }
            // 去除重复
            else if(tmin == min)
            {
                pids[i]++;
            }
        }

        res[rsize++] = min;
        pids[id]++;
    }

    return res[n - 1];
}


// @lc code=end


```