### Method1:双指针
定义两个指针cur和pre，分别表示当前遍历的节点和当前节点的前一个结点。
再定义一个指针tmp,暂存cur指向的结点(cur-next)。每次都让cur指向pre(cur->next=pre)，再将cur的值赋给pre(pre=cur)，最后，将tmp赋给cur，进行下一次操作

### code

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur=head;
        ListNode* pre=nullptr;
        while(cur)
        {
            ListNode* tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        return pre;
    }
};
```

### Method2:递归
使用递归，直到链表的最后一个节点，用一个指针指向该节点，作为反转后的链表的头节点
在递归返回的过程中，让该节点的下一个节点指向该节点(head->next->next=head)，
并让该节点指向NULL。这样就从链表尾部一步步实现了反转
![1.png](https://pic.leetcode-cn.com/56cb637b1f9984cd642836890fbe4d38e37d78953b0d2c2360ef72be5967b251-1.png)


人生第一次实现双百😄
![2.png](https://pic.leetcode-cn.com/bf85dfe5f1ed97ef0c5d2eb37bbced703df862c7937a527363a987b48b95343a-2.png)

### code
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)  return head;
        ListNode* ptr=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        
        return ptr;
    }
};
```

