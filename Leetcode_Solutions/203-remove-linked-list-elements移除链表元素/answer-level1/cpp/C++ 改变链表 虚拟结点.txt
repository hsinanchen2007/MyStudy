### 解题思路
创建一个空结点指向头结点，这样返回新链表的头结点时就不会因为头结点可能被删除而带来bug。

### 代码

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        ListNode* H = new ListNode(-1);     //创建一个新的头结点
        H->next = head;                     //将其指向传入的头结点
        ListNode* p = H;                    //这才是实际操作改变的链表结点
        while(p->next!=NULL)
        {
            if(p->next->val==val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return H->next;         //返回的是新链表 指向头节点的无意义结点
    }
};
```
![image.png](https://pic.leetcode-cn.com/1de16c57ac9732f7e4c73f7d67274742f24067ce93e62c70198cbdc8c024d192-image.png)
