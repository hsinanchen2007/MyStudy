### 解题思路
题目要求为比较数值大小及位置距离，因此对数值和id进行二重排序，可以起到加速作用。

题目特殊的地方在于int没有限定范围，需要特殊处理边界条件。

由于qsort只能返回int，因此需要将比较结果处理为int类型。

![image.png](https://pic.leetcode-cn.com/1f83562cd6c858662dfa1a389f3f5834847ffe86a5e9b3e2f3be3baa70e9e326-image.png)


### 代码

```c
/*
 * @lc app=leetcode.cn id=220 lang=c
 *
 * [220] 存在重复元素 III
 */

// @lc code=start

typedef long long ll_t;

typedef struct _info_st
{
    ll_t num;
    int id;
}info_st;

int compare(const void *a, const void *b)
{
    if((*(info_st *)a).num != (*(info_st *)b).num)
    {
        //return (*(info_st *)a).num - (*(info_st *)b).num;
        int res =   (*(info_st *)a).num > (*(info_st *)b).num? 1 : 
                    ((*(info_st *)a).num == (*(info_st *)b).num? 0 : -1);
        return res;
    }
    else
    {
        return (*(info_st *)a).id - (*(info_st *)b).id;
    }
    
}

// 【算法思路】排序。将数组按照大小和位置进行二重条件排序，然后双指针比较
// 注意整数边界，需要扩展为long long
// 注意qsort为了处理边界情况，需要使用比较运算转换为1,0,-1
bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t){
    if(k <= 0 || t < 0)
    {
        return false;
    }

    info_st *info = (info_st *)calloc(numsSize, sizeof(info_st));

    for(int i = 0; i < numsSize; i++)
    {
        info[i].num = nums[i];
        info[i].id = i;
    }

    qsort(info, numsSize, sizeof(info_st), compare);

    int ll = 0, rr = 0;

    for(int i = 0; i < numsSize - 1; i++)
    {
        int rr = i + 1;

        while(rr < numsSize)
        {
            if(info[rr].num - info[i].num > t)
            {
                break;
            }

            //printf("[%d, %d]  - [%d, %d] = %ld\n", info[rr].num, info[rr].id, info[i].num, info[i].id, info[rr].num - info[i].num);

            if(abs(info[rr].id - info[i].id) <= k)
            {
                return true;
            }

            rr++;
        }
    }

    return false;
}


// @lc code=end


```