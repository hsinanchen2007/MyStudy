### 解题思路
**1、链表操作总结：**
链表操作中比较难掌握的应该就是各种断链、挂接，删除节点等等。下面介绍几个常用的操作链表的技术：
1）dummyHead，哨兵节点，也有叫傀儡节点（处理链表问题的一般技巧）。用于指向链表的头节点。
2）双指针法（快慢指针法，前后指针法等）。诸如获取倒数第k个元素，获取中间位置的元素，判断链表是否存在环，判断环的长度等和长度与位置有关的问题。这些问题都可以通过灵活运用双指针来解决。

    Tips：双指针并不是固定的公式，而是一种思维方式。
    具体可以参考：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/solution/yi-wen-gao-ding-chang-jian-de-lian-biao-wen-ti-h-3/ 面试问题总结部分。

    说明：
    a.如果一个链表存在环，那么快慢指针必然会相遇。
    b.如果存在环，如何判断环的长度呢？方法是，快慢指针相遇后继续移动，直到第二次相遇。两次相遇间的移动次数即为环的长度。
3）空指针看做是一个节点。有时将尾节点指向的空指针看做一个节点来对待可以简化问题。
4）只给当前节点指针来删除当前节点：可以将当前节点next指向的节点复制到当前节点，然后删除当前节点next指向的节点。


**2、在这里归并排序，我们主要用到链表操作的三个技术：**
1）mergeList(l1, l2)：双路归并，合并两个有序的链表。
2）cutList(list, n)：它其实就是一种 splitList 操作，即断链操作。这里感觉使用 cutList 更准确一些，表示将链表 list 切掉前 n 个节点，并返回后半部分的链表头。
3）dummyHead哨兵节点大法。

![image.png](https://pic.leetcode-cn.com/7892bdfe4d9b26e6abf79e87a8f56715dd1e952e2276c32acfd58bbba8e38dc1-image.png)


如图所示：归并思路是这样的：先求出链表的长度iLength，然后循环log(iLength)次，每次循环中，在嵌套循环进行先cut两次（一次一个节点）在merge（两次cut出来的两个节点）操作，完成一轮后，继续cut两次（一次两个节点）在merge（两次cut出来的四个节点）操作，以此类推直到循环结束。
    具体的例子：原序列[4,3,1,7,8,9,2,11,5,6].
    merge操作：
    step=1: (3->4)->(1->7)->(8->9)->(2->11)->(5->6)
    step=2: (1->3->4->7)->(2->8->9->11)->(5->6)
    step=4: (1->2->3->4->7->8->9->11)->5->6
    step=8: (1->2->3->4->5->6->7->8->9->11)

    参考：148. 排序链表-bottom-to-up O(1) 空间
    链接：https://leetcode-cn.com/problems/sort-list/solution/148-pai-xu-lian-biao-bottom-to-up-o1-kong-jian-by-/
    图片参考：Sort List （归并排序链表）
    链接：https://leetcode-cn.com/problems/sort-list/solution/sort-list-gui-bing-pai-xu-lian-biao-by-jyd/



**3、编码：**
推荐方法一：归并排序

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 方法一：归并排序实现链表排序。（局部变量申请哨兵节点） */
struct ListNode* sortList(struct ListNode* head){
    struct ListNode* pstLnCur = NULL;
    struct ListNode* pstLnPre = NULL;
    struct ListNode* pstLnLeft = NULL;
    struct ListNode* pstLnRight = NULL;
    struct ListNode stLnHead = {0};
    int iLength = 0;
    stLnHead.val = 0;
    stLnHead.next = NULL;

    if((NULL == head) || (NULL == head->next))
    {
        return head;
    }
    // 获取链表长度
    iLength = listNodeLength(head);

    //局部变量申请哨兵节点，也有叫傀儡节点（处理链表问题的一般技巧）
    stLnHead.next = head;  //因为head所指节点在排序的过程中会变动。

    // 循环 log n 次
    for(int i=1; i<iLength; i<<=1)
    {
        pstLnPre = &stLnHead;
        pstLnCur = stLnHead.next;
        // 循环 n 次
        while(NULL != pstLnCur)
        {
            pstLnLeft = pstLnCur;
            pstLnRight = splitList(pstLnLeft, i);
            pstLnCur = splitList(pstLnRight, i);

            pstLnPre->next = mergeTwoLists(pstLnLeft, pstLnRight);

            //用于将两两排序好的链表链接到一起。
            while(NULL != pstLnPre->next)
            {
                pstLnPre = pstLnPre->next;
            }
        }
    }

    return stLnHead.next;
}
// 获取链表的长度
int listNodeLength(struct ListNode* head)
{
    struct ListNode* pstLnCur = NULL;
    int iLength = 0;
    if(NULL == head)
    {
        return head;
    }
    pstLnCur = head;
    while(NULL != pstLnCur)
    {
        iLength++;
        pstLnCur = pstLnCur->next;
    }

    return iLength;
}
// 根据步长分隔链表
struct ListNode* splitList(struct ListNode* head, int step)
{
    struct ListNode *pstLnCur = NULL;
    struct ListNode *pstLnPre = NULL;
    if(NULL == head)
    {
        return head;
    }
    pstLnCur = head;
    for(int i=1; (i<step)&&(NULL != pstLnCur->next); i++) //这个判断(NULL != pstLnCur->next)需要有，否则pstLnCur可能会为空，然后出现访问空指针的错误。
    {
        pstLnCur = pstLnCur->next;
    }
    pstLnPre = pstLnCur->next;
    pstLnCur->next = NULL;
    return pstLnPre;

}
// 合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* left, struct ListNode* right)
{
    struct ListNode* pstLnPre = NULL;
    struct ListNode* pstLnLeft = NULL;
    struct ListNode* pstLnRight = NULL;
    struct ListNode stLnHead = {0};
    if(NULL == left)
    {
        return right;
    }
    if(NULL == right)
    {
        return left;
    }
    stLnHead.val = 0;
    stLnHead.next = NULL;

    pstLnPre = &stLnHead;
    pstLnLeft = left;
    pstLnRight = right;

    while((NULL != pstLnLeft) && (NULL != pstLnRight))
    {
        if(pstLnLeft->val > pstLnRight->val)
        {
            pstLnPre->next = pstLnRight;
            pstLnRight = pstLnRight->next;
        }
        else
        {
            pstLnPre->next = pstLnLeft;
            pstLnLeft = pstLnLeft->next;
        }
        pstLnPre = pstLnPre->next;
    }

    pstLnPre->next = (NULL==pstLnLeft)?pstLnRight:pstLnLeft;

    return stLnHead.next;
}

/* 方法二：归并排序实现链表排序。（malloc申请内存） */
struct ListNode* sortList(struct ListNode* head){
    if((NULL == head) || (NULL == head->next))
    {
        return head;
    }

    // 获取链表长度。
    int iLength = listNodeLength(head);

    // 哨兵节点，也有叫傀儡节点（处理链表问题的一般技巧）
    struct ListNode* pstLnHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    pstLnHead->next = head;
    struct ListNode* pstLnCur = NULL;
    struct ListNode* pstLnPre = NULL;
    struct ListNode* pstLnLeft = NULL;
    struct ListNode* pstLnRight = NULL;

    // 循环 log n 次
    for(int i=1; i<iLength; i<<=1)
    {
        pstLnPre = pstLnHead;
        pstLnCur = pstLnHead->next;
        // 循环 n 次
        while(NULL != pstLnCur)
        {
            pstLnLeft = pstLnCur;
            pstLnRight = splitList(pstLnLeft, i);
            pstLnCur = splitList(pstLnRight, i);
            pstLnPre->next = mergeTwoLists(pstLnLeft, pstLnRight);

            while(NULL != pstLnPre->next)
            {
                pstLnPre = pstLnPre->next;
            }
        }
    }

    pstLnPre = pstLnHead->next;
    free(pstLnHead);
    pstLnHead=NULL;
    return pstLnPre;
}

// 获取链表的长度
int listNodeLength(struct ListNode* head)
{
    int iLength = 0;
    
    if(NULL == head)
    {
        return 0;
    }
    while(NULL != head)
    {
        iLength++;
        head = head->next;
    }
    return iLength;
}
// 根据步长分隔链表
struct ListNode* splitList(struct ListNode* head, int step)
{
    if(NULL == head)
    {
        return head;
    }

    for(int i=1; (i < step) && (NULL != head->next); i++)
    {
        head = head->next;
    }
    struct ListNode* pstLnRight = head->next;
    head->next = NULL;
    return pstLnRight;

}
// 合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* left, struct ListNode* right){
    if(NULL == left)
    {
        return right;
    }
    if(NULL == right)
    {
        return left;
    }
    struct ListNode* pstLnHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* pstLnPre = NULL;
    pstLnPre = pstLnHead;
    while((NULL != left) && (NULL != right))
    {
        if(left->val > right->val)
        {
            pstLnPre->next = right;
            right = right->next;
        }
        else
        {
            pstLnPre->next = left;
            left = left->next;
        }
        pstLnPre = pstLnPre->next;
    }

    pstLnPre->next = (NULL==left?right:left);
    pstLnPre = pstLnHead->next;
    free(pstLnHead);
    pstLnHead=NULL;
    return pstLnPre;
}

/* 方法三：冒泡法实现链表排序。 */
struct ListNode* sortList(struct ListNode* head){
    struct ListNode* pstLnHeadA = NULL;
    struct ListNode* pstLnHeadB = NULL;
    int iValTemp = 0;
    if(NULL == head)
    {
        return head;
    }

    pstLnHeadA = head;
    //pstLnHeadB = head->next;
    while(NULL != pstLnHeadA)
    {
        pstLnHeadB = pstLnHeadA->next;
        while(NULL != pstLnHeadB)
        {
            if((pstLnHeadB->val) < (pstLnHeadA->val))
            {
                iValTemp = pstLnHeadA->val;
                pstLnHeadA->val = pstLnHeadB->val;
                pstLnHeadB->val = iValTemp;
            }
            pstLnHeadB = pstLnHeadB->next;
        }
        pstLnHeadA = pstLnHeadA->next;
    }
    return head; //交换的只是链表的值，头指针没有变动。
}


```