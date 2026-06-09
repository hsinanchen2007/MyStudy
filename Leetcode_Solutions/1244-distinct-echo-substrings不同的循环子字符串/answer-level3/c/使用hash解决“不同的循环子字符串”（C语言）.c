### 解题思路
1.本题没有使用复杂的算法，只用最基本的遍历比较，然后使用hash去除重复。

2.问题在于，会存在已经查找过的字串，重复查找的问题，出现超时。

3.增加一步剪枝，即在遍历判断一个新的字串之前，先hash判断该字串是否已经被处理。

![image.png](https://pic.leetcode-cn.com/576b0ee33b22dd301c2c7ab903957882e654ae08b75f33f7f7032c2738b48c96-image.png)


### 代码

```c
#define POOL_SIZE   1000

typedef struct _hash_st
{
    char *key;
    int val;
    UT_hash_handle hh;
}hash_st;

//【算法思路】hash+字符串。strncmp比较，然后使用hash去重
int distinctEchoSubstrings(char * text){
    int tlen = strlen(text);

    hash_st *pool = (hash_st *)calloc(POOL_SIZE, sizeof(hash_st));
    int psize = 0;

    hash_st *head = NULL;

    int sum = 0;
    for(int i = 0; i < tlen; i++)
    {
        //进入之前查一下重，如果最长序列已经找过，则无需继续查找
        hash_st *tmph;
        HASH_FIND(hh, head, &text[i], strlen(&text[i]) + 1, tmph);

        if(tmph != NULL)
        {
            continue;
        }

        for(int len = 2; i + len <= tlen; len += 2)
        {
            //起点为i和i + len/2，长度为len/2
            int hlen = len / 2;

            //printf("sid = %d, mid = %d\n", i, i + hlen);
            if(strncmp(&text[i], &text[i + hlen], hlen) == 0)
            {
                char *tmps = (char *)calloc(len + 1, sizeof(char));
                strncpy(tmps, &text[i], len);

                //开始查重
                hash_st *cur = &pool[psize];
                cur->key = tmps;
                cur->val = 1;

                hash_st *tmph;
                HASH_FIND(hh, head, cur->key, len + 1, tmph);

                if(tmph == NULL)
                {
                    HASH_ADD_KEYPTR(hh, head, cur->key, len + 1, cur);
                    psize++;

                    sum++;
                    continue;
                }
            }
        }
    }

    return sum;
}
```