### 解题思路
典型的hash和+双指针问题，排序是为了准备数据。

关键点：使用hash记录是否新增或减少列表数，判断条件为：增加后，hash[id] == 1,总列表数加一；减少后，hash[id] == 0,总列表数减一

1.将数据和所属id使用结构体记录。

2.将数据排序

3.移动右指针，找到区间内所有列表齐全的位置

4.移动左指针，找到区间列表仍旧齐全的位置(最终位置为缺1个列表位置)

5.该区间如果最小，刷新结果

6.返回3进行迭代

![image.png](https://pic.leetcode-cn.com/38957b5ae487262d0f4dd553b9683d7b4ffd14102a2bb6b51b5febb6bb5e8801-image.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define K_SIZE  3501

int hash[K_SIZE];

typedef struct _info_st
{
    int val;
    int id;
}info_st;

int compare(const void *a, const void *b)
{
    return (*(info_st *)a).val - (*(info_st *)b).val;
}

int min_len;
int res[2];

//【算法思路】排序+hash+双指针。将数字带列表序号排序。然后利用总数hash+双指针找到最小区间.
// 双指针找最小区间的方法是：先移动右指针，获得所有符号，在移动左指针缩小范围。当hash数目从0变1，增加总数；从1变0减少总数
int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize){
    int total_num = 0;
    
    //初始化hash表，记录总数据量
    for(int i = 0; i < numsSize; i++)
    {
        hash[i] = 0;
        total_num += numsColSize[i];
    }

    //开辟空间重排元素
    info_st *info = (info_st *)calloc(total_num, sizeof(info_st));
    int isize = 0;

    //重组元素
    for(int i = 0; i < numsSize; i++)
    {

        for(int j = 0; j < numsColSize[i]; j++)
        {
            info[isize].val = nums[i][j];
            info[isize].id = i;

            isize++;
        }
    }

    //排序
    qsort(info, total_num, sizeof(info_st), compare);
/*
    for(int i = 0; i < total_num; i++)
    {
        printf("%d:[%d, %d]   ", i, info[i].val, info[i].id);
    }
    printf("\n");
*/
    //使用hash和寻找最区间的典型框架
    min_len = INT_MAX;

    int ll = 0, rr = 0;

    int shash = 0;      //hash和计数
    while(rr < total_num)
    {
        //增加右指针及其数据
        int cid = info[rr].id;
        hash[cid]++;
        shash = (hash[cid] == 1)? shash + 1 : shash;

        //未凑齐列表总数，继续增加
        if(shash < numsSize)
        {
            rr++;
            continue;
        }

        //printf("ll = %d, rr = %d\n", ll, rr);

        //凑齐总数，从左侧减少区间范围
        for(int i = ll; i <= rr; i++)
        {
            cid = info[i].id;
            hash[cid]--;
            shash = (hash[cid] == 0)? shash - 1 : shash;

            //已经减到最低
            if(shash < numsSize)
            {
                //判断最短距离
                int dist = info[rr].val - info[i].val;

                //printf("min_len = %d, dist = %d\n", min_len, dist);
            
                if(dist < min_len)
                {
                    min_len = dist;
                    res[0] = info[i].val;
                    res[1] = info[rr].val;
                }

                //目前ll表示已经消耗掉当前元素，因此将ll设置为i+1
                ll = i + 1;
                break;
            }
        }

        //此时ll已经指向不成立的最左边元素
        rr++;
/*
        printf("---->ll = %d, rr = %d\n", ll, rr);
        for(int j = 0; j < numsSize; j++)
        {
            printf("<%d>%d    ", j, hash[j]);
        }
        printf("\n");
*/
    }

    *returnSize = 2;
    return res;
}
```