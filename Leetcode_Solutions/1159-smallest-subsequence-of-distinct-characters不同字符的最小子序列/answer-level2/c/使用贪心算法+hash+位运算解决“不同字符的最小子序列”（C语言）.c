### 解题思路
本题算法思路和编程实现属于“较难”题型。

基本思路为贪心算法，统计待输出字符个数，然后逐个使用贪心算法确认适合的字符。

判断是否适合的条件为，“该字符对应位置的后续字符，能够包括所有待放置字符”。此条件需要使用位运算来实现。

具体算法步骤为：

1.构建信息结构，表示每类字符是否在字串中出现，出现的每个位置以及该位置后面的字符hash统计（映射到位）

2.计算总共出现的字符类型个数，及hash统计（映射到位）

3.按照类型个数进行遍历，遍历内容如下：

4.每次遍历内部，按照26个字母进行遍历，遍历内容如下：

5.“找到当前已使用字符的位置之后出现的最小有效字符”

6.判断其后hash表是否和剩余字符hash表相同；如果相同则更新剩余字符hash表，并去掉已经使用的字符信息。

注意，设置一个mask用于去掉已经使用的字符。

![image.png](https://pic.leetcode-cn.com/60bd96ee717c4fbd9a07331efc8a0936d0a10db2332755f710f7680a2d6e9900-image.png)


### 代码

```c
/*
 * @lc app=leetcode.cn id=1081 lang=c
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
char res[27];

typedef unsigned int uint;

typedef struct _info_st
{
    int valid;
    int ids[500];
    uint hashs[500];
    int cnt;
}info_st;

//【算法思路】贪心+hash位运算。贪心算法，26个字母从小到大，确认是否加入。使用hash位运算加速。
// 是否可以加入的条件时，看后面剩余的字串中是否包含所有剩下的字母
char * smallestSubsequence(char * text){
    int slen = strlen(text);

    info_st *info = (info_st *)calloc(26, sizeof(info_st));

    uint hash_base = 0;
    //构建构建info表，记录每个字符出现的位置，及每个位置对应的后续hash
    //注意id的添加顺序为从后向前，但访问时只需要访问在当前位置之后的一个位置即可
    for(int i = slen - 1; i >= 0; i--)
    {
        int tid = text[i] - 'a';
        
        info[tid].valid = 1;

        int iid = info[tid].cnt++;

        hash_base |= 1 << (tid);
        info[tid].hashs[iid] = hash_base;
        info[tid].ids[iid] = i;
    }
/*
    for(int i = 0; i < 26; i++)
    {
        printf("%d| valid = %d, cnt = %d\n", i, info[i].valid, info[i].cnt);

        for(int j = 0; j < info[i].cnt; j++)
        {
            printf("        id = %d, hash = 0x%x\n", info[i].ids[j], info[i].hashs[j]);
        }
    }
    printf("\n");
*/
    //计算出现字符的种类
    int loop = 0;
    for(int i = 0; i < 26; i++)
    {
        if(info[i].valid == 1)
        {
            loop++;
        }
    }
    //printf("loop = %d\n", loop);

    int rsize = 0;
    uint mask = -1;

    //确认各个字母的位置
    int cur_id = -1;        // 记录在text中已经确认的位置
    for(int i = 0; i < loop; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(info[j].valid == 1)
            {
                bool find = false;
                //寻找在cur_id之后的第一个字符，看是否满足要求
                for(int k = info[j].cnt - 1; k >= 0; k--)
                {
                    //printf("cur_id = %d, id = %d, hash_base = 0x%x, mask = 0x%x\n", cur_id, info[j].ids[k], hash_base, mask);

                    if(info[j].ids[k] > cur_id)
                    {
                        if((hash_base & mask) == (info[j].hashs[k] & mask))
                        {
                            find = true;

                            //刷新cur_id,hash_base,valid,res
                            cur_id = info[j].ids[k];
                            mask ^= 1 << j;
                            info[j].valid = 0;

                            res[rsize++] = j + 'a';
                            break;
                        }
                    }
                }

                if(find == true)
                {
                    break;
                }
            }
        }
    }

    res[rsize] = '\0';
    return res;
}


// @lc code=end


```