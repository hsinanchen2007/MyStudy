### 解题思路
1.排序，保证根目录最先出现，记录在hash表中

2.逐字符拷贝文件夹路径，遇到'/'判断如果有该长度的key，则进行查找

3.如果找到，则处理下一路径

4.如果未找到，则将当前子串记录在hash表中

注意，使用数组hash表对key的长度进行记录，加速判断。

![image.png](https://pic.leetcode-cn.com/e47e1e5c58ffa8da6b36b1d5ecdadb493ca56dfa111e1c35b6095284555c5cd2-image.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define POOL_SIZE   10000
#define RES_SIZE    10000

int compare(const void *a, const void *b)
{
    return strlen(*(char **)a) - strlen(*(char **)b);
}

typedef struct _hash_st
{
    char key[100];
    UT_hash_handle hh;
}hash_st;

char *res[RES_SIZE];

// 【算法思路】排序 + hash.字符串hash & 长度hash。使用hash表查找是否已经有路径，key为有效路径，使用长度hash加速。
char ** removeSubfolders(char ** folder, int folderSize, int* returnSize){
    qsort(folder, folderSize, sizeof(char *), compare);

    int lhash[100] = {0};

    hash_st *pool = (hash_st *)calloc(POOL_SIZE, sizeof(hash_st));
    int psize = 0;

    hash_st *head = NULL;

    int rsize = 0;

    for(int i = 0; i < folderSize; i++)
    {
        int flen = strlen(folder[i]);

        hash_st *cur = &pool[psize];

        cur->key[0] = '/';

        bool find = false;

        for(int j = 1; j < flen; j++)
        {
            if(folder[i][j] != '/')
            {
                cur->key[j] = folder[i][j];
                continue;
            }

            //如果存在该长度key
            if(lhash[j] > 0)
            {
                cur->key[j] = '\0';

                hash_st *tmph;
                // 查找是否存在key
                HASH_FIND_STR(head, &(cur->key), tmph);

                if(tmph != NULL)
                {
                    find = true;
                    break;
                }
            }

            cur->key[j] = folder[i][j];
        }

        if(find == false)
        {
            res[rsize++] = folder[i];

            cur->key[flen] = '\0';

            HASH_ADD_STR(head, key, cur);
            psize++;

            lhash[flen]++;
        }
    }

    *returnSize = rsize;
    return res;
}
```