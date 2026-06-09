### 解题思路
方法一：
快慢指针法（前后指针法）。
1、定义两个指针，快指针 Fast 慢指针 Slow （或者叫做前后指针）；
2、让 Fast 先向前移动 k 个位置，然后 Fast 和 Slow 再一起向前移动 ；
3、当 Fast 到达链表尾部，返回 Slow 。

方法二：
常规求取长度法。
1、先遍历统计链表长度，记为 iLength ；
2、设置一个指针走 (iLength−k) 步，即可找到链表倒数第 k 个节点。

两种方法运行时间：
![image.png](https://pic.leetcode-cn.com/c5d0f06a05c2a2583c79998f128fa4af4f73a0ff81a5a5d85bdfdce501cffd56-image.png)


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//方法一：快慢指针法。
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode* pstLnFast = NULL;
    struct ListNode* pstLnSlow = NULL;
    if(NULL == head)
    {
        return head;
    }

    pstLnFast = head;
    pstLnSlow = head;
    while(NULL != pstLnFast)
    {
        //pstLnFast一直移动到NULL。
        pstLnFast = pstLnFast->next;

        //pstLnSlow前k个节点不移动，构造出pstLnSlow和pstLnFast指针的k个节点距离，然后两个指针同时移动，
        //当pstLnFast一直移动到NULL时，pstLnSlow则指向的就是倒数k节点的位置了。
        if(0 == k)
        {
            pstLnSlow = pstLnSlow->next;
        }
        else
        {
            k--;
        }
    }

    return pstLnSlow;
}

//方法二：常规求取长度法。
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode* pstLnCur = NULL;
    int iLength = 0;
    if(NULL == head)
    {
        return head;
    }
    pstLnCur = head;
    
    //求取链表长度
    while(NULL != pstLnCur)
    {
        iLength++;
        pstLnCur = pstLnCur->next;
    }

    pstLnCur = head;
    //找到倒数k个节点的位置
    while(iLength>k)
    {
        pstLnCur = pstLnCur->next;
        iLength--;
    }

    return pstLnCur;

}
```