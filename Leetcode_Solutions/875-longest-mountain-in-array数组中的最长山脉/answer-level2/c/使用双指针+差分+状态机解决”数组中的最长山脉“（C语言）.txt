### 解题思路
1.寻找数组数据连续变化规律，首先使用差分预处理数据

2.寻找最长满足条件的间隔，使用双指针的编程模型

3.右指针需要实现的功能有：寻找第一个+，第一个-，和第一个非-，使用状态机进行控制

![image.png](https://pic.leetcode-cn.com/69913de0efb4917a563bf8286da54687670b867e0a3273fd42e9747cd5645243-image.png)


### 代码

```c
#define MMAX(a, b)		((a) > (b)? (a) : (b))

// 【算法思路】差分+双指针+状态机。差分出数据的分布形式，然后首先找到左山脚，再找由山脚，遇到0则重新初始化。
// 状态机控制右指针寻找不同的目标值
int longestMountain(int* A, int ASize){
    if(ASize < 3)
    {
        return 0;
    }

    int *diff = (int *)calloc(ASize - 1, sizeof(int));

    for(int i = 0; i < ASize - 1; i++)
    {
        diff[i] = A[i + 1] - A[i];
    }

    // state 为0，寻找起始+，1寻找连续+后第一个-，2寻找连续-后的非-，状态转为0
    // 中间遇到异常状态，转为0
    int state = 0;
    int max = 0;

    int ll = 0, rr = 0;

    while(rr < ASize - 1)
    {
        if(state == 0)
        {
            if(diff[rr] <= 0)
            {
                rr++;
                continue;
            }

            ll = rr;
            state = 1;

            //printf("start ll = %d\n", ll);

            rr++;
            continue;
        }
        else if(state == 1)
        {
            if(diff[rr] > 0)
            {
                rr++;
                continue;
            }
            else if(diff[rr] == 0)
            {
                state = 0;

                rr++;
                continue;
            }
            else
            {
                //下山
                state = 2;

                //printf("top rr = %d\n", rr);
                continue;
            }
        }
        else
        {
            if(diff[rr] < 0)
            {
                rr++;
                continue;
            }
            else
            {
                //结算
                max = MMAX(max, rr - ll + 1);

                //printf("bot rr = %d, len = %d\n", rr, rr - ll + 1);

                state = 0;
                continue;
            }
        }
    }

    //结算
    if(state == 2)
    {
        max = MMAX(max, rr - ll + 1);
        printf("bot rr = %d, len = %d\n", rr, rr - ll + 1);
    }
    return max;
}
```