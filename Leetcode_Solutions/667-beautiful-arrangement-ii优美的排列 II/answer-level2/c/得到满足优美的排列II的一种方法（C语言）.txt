### 解题思路
本题的标签可以归为数学。首先想到dfs，但是会超时，因为停止条件太迟，必须凑到k。
从数组的角度考虑，凑k个不同答案，可以通过1~(n-k),然后n,(n-k)+1,n-1,n-k+2...，这样凑出来的序列就是
1,1,1,1.......1,k,k-1,k-2,k-3...3,2,1

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#if 1
int res[10000];

// 【算法思路】数学。凑k个不同答案，可以通过1~(n-k),然后n,(n-k)+1,n-1,n-k+2...
// dfs + 计数hash。会超时，因为停止条件太迟，必须凑到k。
int* constructArray(int n, int k, int* returnSize){
    for(int i = 0; i < n - k; i++)
    {
        res[i] = i + 1;
    }

    int step = 0;
    for(int i = n - k; i < n; i += 2)
    {
        res[i] = n - step++;
    }

    step = 1;
    for(int i = n - k + 1; i < n; i += 2)
    {
        res[i] = n - k + step++;
    }

    *returnSize = n;
    return res;
}
#endif

#if 0
int *flags;
int *hash;
int res[10000];
int kk;
int nums;

//判断在起始位置id是否能够形成有效序列
bool helper(int n, int k, int id)
{
    if(k - kk > nums)
        return false;

    if(id == n)
        return false;

    for(int i = 1; i <= n; i++)
    {
        if(flags[i] == 0)
        {
            //计算域前一个的差绝对值
            int dif = abs(res[id - 1] - i);

            flags[i] = 1;
            res[id] = i;

            hash[dif]++;
            if(hash[dif] == 1)
            {
                kk++;
            }
            nums--;

            if(kk == k && id == n - 1)
            {
                return true;
            }

            if(helper(n, k, id + 1) == true)
            {
                return true;
            }

            nums++;

            if(hash[dif] == 1)
            {
                kk--;
            }
            hash[dif]--;
            flags[i] = 0;
        }
    }

    return false;
}

// 【算法思路】dfs + 计数hash。
int* constructArray(int n, int k, int* returnSize){
    nums = n;

    flags = (int *)calloc(n + 1, sizeof(int));
    hash = (int *)calloc(n + 1, sizeof(int));
    kk = 0;

    bool flag = false;

    for(int i = 1; i <= n; i++)
    {
        //在位置0使用i
        flags[i] = 1;
        res[0] = i;
        nums--;
        
        //判断起始位置为1是否能够有有效序列
        if(helper(n, k, 1) == true)
        {
            flag = true;
            break;
        }

        nums++;
        flags[i] = 0;
    }

    *returnSize = (flag == true)? n : 0;
    return res;
}
#endif
```