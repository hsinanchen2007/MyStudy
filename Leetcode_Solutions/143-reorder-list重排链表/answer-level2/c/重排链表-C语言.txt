### 解题思路

1、算法说明：
算法分为三步，举例说明：
链表：1 -> 2 -> 3 -> 4 -> 5 -> 6

第一步，将链表平均分成两半：
1 -> 2 -> 3
4 -> 5 -> 6    
第二步，将第二个链表逆序（反转）：
1 -> 2 -> 3
6 -> 5 -> 4  
第三步，依次连接两个链表：
1 -> 6 -> 2 -> 5 -> 3 -> 4


2、运行结果：
![image.png](https://pic.leetcode-cn.com/5cd88748727f2592bf7ec303126fd8867531d6e6f522bdd25f0d902ba7f4f94e-image.png)

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//反转链表
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode* pstLnTemp = NULL;
    struct ListNode* pstLnCur = NULL;
    struct ListNode* pstLnPre = NULL;

    if(NULL == head)
    {
        return head;
    }
    pstLnCur = head;
    while(NULL != pstLnCur)
    {
        pstLnTemp = pstLnCur->next;
        pstLnCur->next = pstLnPre;
        pstLnPre = pstLnCur;
        pstLnCur = pstLnTemp;
    }

    return pstLnPre;
}

void reorderList(struct ListNode* head){
    struct ListNode* pstLnFast = NULL;
    struct ListNode* pstLnSlow = NULL;
    int iLength = 0;
    struct ListNode stLnHead = {0};
    struct ListNode* pstLnPre = NULL;

    if(NULL == head)
    {
        return head;
    }

    //1.快慢指针将链表平均分成两半。
    pstLnFast = head;
    pstLnSlow = head;
    while((NULL != pstLnFast) && (NULL != pstLnFast->next))
    {
        pstLnSlow = pstLnSlow->next;
        pstLnFast = pstLnFast->next->next;
        iLength++;
    }

    //2.将第二个链表逆序（反转）。
    pstLnSlow = reverseList(pstLnSlow);
    pstLnFast = head;

    //3.利用哨兵节点依次连接两个链表。
    pstLnPre = &stLnHead;
    while(iLength>0)
    {
        pstLnPre->next = pstLnFast;
        pstLnFast = pstLnFast->next;
        pstLnPre = pstLnPre->next;

        pstLnPre->next = pstLnSlow;
        pstLnSlow = pstLnSlow->next;
        pstLnPre = pstLnPre->next;

        iLength--;
    }

    //3.连接两个链表的另一种实现方法。
    /* while(NULL != pstLnFast)
    {
        pstLnTemp = pstLnFast->next;
        pstLnFast->next = pstLnSlow;
        pstLnFast = pstLnSlow;
        pstLnSlow = pstLnTemp;
    } */

}
```