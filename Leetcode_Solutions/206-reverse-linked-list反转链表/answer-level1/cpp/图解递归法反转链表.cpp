* reverseList函数返回值为反转后的链表头部，即链表的最后一个节点
* 想象各节点的位置不变，每层的步骤只是反转一次当前节点 'head'和他的下一个节点'head->next'的指针方向而已。
![IMG_20200401_105705.jpg](https://pic.leetcode-cn.com/1f0f9241a9b4bdddf352c353b3b3865f7f63ff958caa5933f851d663e4d101de-IMG_20200401_105705.jpg)
```cpp

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        
        //如果链表只有一个节点时
        if(!head->next)return head;

        //每次返回的都是反转后的链表头部，一直保持是最后一个节点不变
        ListNode*newHead=reverseList(head->next);
        //让后面的节点反向指向自己
        head->next->next=head;
        //让自己作为链表尾部，指向NULL
        head->next=NULL;
        return newHead;
    }
};
```