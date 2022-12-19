### 解题思路
本题关键点在于只需要关注minsize即可。

1.使用滑动窗口遍历字串，找到满足maxLetters的字串

2.使用uthash进行统计记录

![image.png](https://pic.leetcode-cn.com/3ce7474aec00ec3e266222b28cc36eaaef67131f87a915d688f675ee0886a916-image.png)


### 代码

```c
/*
 * @lc app=leetcode.cn id=1297 lang=c
 *
 * [1297] 子串的最大出现次数
 */

// @lc code=start
#define POOL_SIZE   20000
#define MMAX(a, b)  ((a) > (b)? (a) : (b))

typedef struct _hash_st
{
    char *key;
    int val;
    UT_hash_handle hh;
}hash_st;

//【算法思路】hash + 滑窗。只需要考虑最小值，针对最小值滑窗，满足maxletter条件，则调用uthash进行统计。
// 只需要考虑最小值的原因是：最大值满足，最小值必定满足。
int maxFreq(char * s, int maxLetters, int minSize, int maxSize){
    hash_st *pool = (hash_st *)calloc(POOL_SIZE, sizeof(hash_st));
    int psize = 0;

    int hcnt = 0;
    int hash[26] = {0};

    int slen = strlen(s);
    int ll = 0, rr = 0;

    hash_st *head = NULL;

    int max = 0;
    while(rr < slen)
    {
        //printf("ll = %d, rr = %d\n", ll, rr);

        int tlen = rr - ll + 1;

        if(tlen < minSize)
        {
            //更新hash统计
            int cid = s[rr] - 'a';
            hash[cid]++;
            if(hash[cid] == 1)
            {
                hcnt++;
            }

            rr++;
            continue;
        }

        //为最后一个字符更新hash统计
        int cid = s[rr] - 'a';
        hash[cid]++;
        if(hash[cid] == 1)
        {
            hcnt++;
        }

        rr++;

        //printf("hcnt = %d\n", hcnt);
        if(hcnt <= maxLetters)
        {
            // 满足条件时，进行uthash操作
            char *tmps = (char *)calloc(minSize + 1, sizeof(char));
            for(int i = ll; i < rr; i++)
            {
                tmps[i - ll] = s[i];
            }

            //printf("%s\n", tmps);

            hash_st *cur = &pool[psize];
            cur->key = tmps;
            cur->val = 1;
            hash_st *tmph;

            HASH_FIND(hh, head, cur->key, minSize, tmph);

            if(tmph == NULL)
            {
                HASH_ADD_KEYPTR(hh, head, cur->key, minSize, cur);
                psize++;

                max = MMAX(max, 1);
            }
            else
            {
                tmph->val++;

                max = MMAX(max, tmph->val);
            }

            // 移动ll，并更新hash统计
            int lid = s[ll] - 'a';
            hash[lid]--;
            if(hash[lid] == 0)
            {
                hcnt--;
            }

            ll++;
        }
        else
        {
            // 不满足条件，移动ll，并更新hash统计
            int lid = s[ll] - 'a';
            hash[lid]--;
            if(hash[lid] == 0)
            {
                hcnt--;
            }

            ll++;
        }
    }

    return max;
}


// @lc code=end


```