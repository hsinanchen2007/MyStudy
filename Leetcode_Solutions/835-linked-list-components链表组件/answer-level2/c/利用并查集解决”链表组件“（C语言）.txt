### 解题思路
题目可以转换为：

有一组N以内的元素，元素间链接关系由单链表表示，元素是单链表节点val的子集。求最终独立的元素组的个数。

使用并查集解决此类问题。

1.构建并查集表，不在G内的用-1表示

2.遍历单链表，只考虑在G内的元素之间建立链接

3.统计并查集表，算出独立集合个数

![image.png](https://pic.leetcode-cn.com/3db5237864a207cca57c32aaad7e476b6e686d7903f2961d6d94cd88744d4324-image.png)


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define FA_SIZE     10000

int find(int *fa, int x)
{
    if(fa[x] == x)
    {
        return fa[x];
    }

    fa[x] = find(fa, fa[x]);

    return fa[x];
}

void join(int *fa, int x, int y)
{
    int xx = find(fa, x);
    int yy = find(fa, y);

    if(xx == yy)
    {
        return;
    }

    if(xx < yy)
    {
        fa[yy] = xx;
    }
    else
    {
        fa[xx] = yy;
    }
}

int fa[FA_SIZE];

//【算法思路】并查集。将未在G中的元素置为-1，g中元素建立表格，根据链表建立并查关系，最终找到非-1的根节点个数
int numComponents(struct ListNode* head, int* G, int GSize){
    for(int i = 0; i < FA_SIZE; i++)
    {
        fa[i] = -1;
    }

    for(int i = 0; i < GSize; i++)
    {
        fa[G[i]] = G[i];
    }

    struct ListNode *cur = head;

    int lid = cur->val;
    cur = cur->next;

    int tsize= 1;
    while (cur != NULL)
    {
        tsize++;

        int rid = cur->val;

        //建立连接
        if(fa[lid] != -1 && fa[rid] != -1)
        {
            join(fa, lid, rid);
        }

        //为下一次处理更新
        lid =rid;
        cur = cur->next;
    }
/*
    for(int i = 0; i < tsize; i++)
    {
        printf("[%d, %d]   ", i, fa[i]);
    }
    printf("\n");
*/
    int cnt = 0;
    for(int i = 0; i < tsize; i++)
    {
        if(fa[i] == -1)
        {
            continue;
        }
        else if(fa[i] == i)
        {
            cnt++;
        }
    }

    return cnt;
}
```