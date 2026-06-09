![123.png](https://pic.leetcode-cn.com/0601031491feaa5b621c7bda35c243403b84964a8804bf9edd090b82c029453d-123.png)


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode *p;
    p = head;
    int count = 0;
    int i;
    while(p != NULL)    // 判断共有多少个节点
    {
        p = p->next;
        count ++;
    }
    p = head;
    for(i=0; i<count/2; i++)    // 指向中间节点
    {
        p = p->next;
    }
    return p;

}


