![image.png](https://pic.leetcode-cn.com/0943d5bbcf61da4431ff4937cdb807e3cf150df9f38d713989918d174545cca5-image.png)


1.解析richer数组，使用类似桶排序的数据结构存储对应比person x更富有的人;
题目中的例子可以解析为如下结构
```
person 0：Head->1->NUll
person 1：Head->2->3->NUll
person 2：Head->NUll
person 3：Head->4->5->6->NUll
person 4：Head->NUll
person 5：Head->NUll
person 6：Head->NUll
person 7：Head->3->NUll
```

2.对person x，若没有比他更富有的人，则`ans[x] = x`;
  若有比他更富有的人(假设为a, b, c)，则ans[x]为比他更富有的人中（包括x本身）最沉默的人；
  公式化表示为：
    `ans[x] = y which quiet[y] = min{quiet[x], quiet[ans[a]], quiet[ans[b]], quiet[ans[c]]};`
  在获取用户x的答案过程中使用了DFS搜索的思想，如果用户a的ans没有计算过，则先计算用户a的ans；
3.优化：对于同一个用户，在计算过程中可能被计算多次。例如，person a 既比x富有，也比y富有。在计算ans[x]时，计算了ans[a], 计算ans[y]时也会使用到ans[a];
因此将已经计算过的用户结果保存在ans数组中，可以避免重复计算。
4.代码：


```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* 链表节点数据结构 */
typedef struct LinkNode {
    int val;
    struct LinkNode *next;
}LinkNode;
/* 插入链表  */
void insert(LinkNode *head, int val) {
    LinkNode *tmp = head;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = (LinkNode *)malloc(sizeof(LinkNode));
    tmp->next->val = val;
    tmp->next->next = NULL;
}
/* 计算用户i的答案，若ans[i] = -1,说明未计算过 */
void getAns(int *ans, LinkNode *rich, int *quiet, int i) {
    if (ans[i] != -1) {
        return;
    } else {
        LinkNode *tmp = &rich[i];
        int min = i;
        /* DFS 计算每个用户及比他富有的用户的答案 */
        while(tmp->next) {
            tmp = tmp->next;
            getAns(ans, rich, quiet, tmp->val);
            min = quiet[min] < quiet[ans[tmp->val]] ? min : ans[tmp->val];
        }
        ans[i] = min;
    }
}
int* loudAndRich(int** richer, int richerSize, int* richerColSize, int* quiet, int quietSize, int* returnSize){
    LinkNode *rich = (LinkNode *)malloc(sizeof(LinkNode) * quietSize);
    for (int i = 0; i < quietSize; i++) {
        rich[i].val = -1;
        rich[i].next = NULL;
    }
    /* 解析richer数组 */
    for (int i = 0;i < richerSize; i++) {
        insert(&rich[richer[i][1]], richer[i][0]);
    }
    int *ans = (int *)malloc(sizeof(int) * quietSize);
    /* 初始化结果为-1, 用来标记用户是否已经被计算过 */
    for (int i = 0; i < quietSize; i++) {
        ans[i] = -1;
    }
    for (int i = 0; i < quietSize; i++) {
        getAns(ans, rich, quiet, i);
    }
    *returnSize = quietSize;
    free(rich);
    return ans;
}
```
