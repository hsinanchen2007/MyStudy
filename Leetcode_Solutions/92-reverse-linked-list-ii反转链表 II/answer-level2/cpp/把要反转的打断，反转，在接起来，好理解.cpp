```
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *emptyHead = new ListNode(-1);
        emptyHead->next = head;
        ListNode *leftend = emptyHead, *rightstart = emptyHead;
        ListNode *revStart, *revEnd;//需要反转的开始终点

        while(n--)//右边的先过去，不然左边断开了，过不去了
            rightstart = rightstart->next;
        revEnd = rightstart;
        rightstart = rightstart->next;
        revEnd->next = NULL;//断开需要反转的右端点

        while(--m)
            leftend = leftend->next;
        revStart = leftend->next;
        leftend->next = NULL;//断开需要反转的左端点

        reverseList(revStart, revEnd);//反转中间段
        leftend->next = revStart;
        revEnd->next = rightstart;
        return emptyHead->next;
    }

    void reverseList(ListNode* &head, ListNode* &tail)//传入的是引用
    {
        tail = head;//尾巴是现在的起点
        ListNode *tempH = head;
        if(!tempH || !tempH->next)
            return;
        ListNode *prev = NULL, *nexNode;
        while(tempH)
        {
            nexNode = tempH->next;
            tempH->next = prev;
            prev = tempH;
            tempH = nexNode;
        }
        head = prev;//起点是现在的尾巴
    }
};
```
![image.png](https://pic.leetcode-cn.com/04a8cf39a068651293970207fc0a4038e49a5bddd1de8e5fb5825e3bd1e03ea6-image.png)

