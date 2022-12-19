### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/* First to count the number of linkNode */
int LinkTraveral(struct ListNode *head)
{
    int LinkNodeNum = 0;
    struct ListNode *temp = head;

    while(temp != NULL)
    {
        LinkNodeNum++;
        temp = temp->next;
    }

    return LinkNodeNum;
}

struct ListNode* middleNode(struct ListNode* head){
    int MidLinkNodeIndex = 0;
    int TotalLinkNode = 0;
    struct ListNode *MidLinkNode = NULL;
    struct ListNode *temp = head;

    /* Get the total link node number */
    TotalLinkNode = LinkTraveral(head);
    if(TotalLinkNode == 0 || TotalLinkNode == 1)
    {
        return head;
    }

    /* Get the index of the middle link node */
    MidLinkNodeIndex = TotalLinkNode / 2;

    int i = 0;
    while(i < MidLinkNodeIndex)
    {
        i++;
        temp = temp->next;
    }

    /* Traver the pre MidLinkNodeIndex link node, the following is the link node we want */
    MidLinkNode = temp;

    return MidLinkNode;
}
```