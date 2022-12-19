### 解题思路
递归其实有点麻烦，不像迭代那样清楚。
1、递归的出口其实还好，但是要注意顺序
这是我最开始写的，if(head->next==nullptr||head==nullptr) return head。
提交后，发现输入的为空链表时，会报错。
然后修改成 if(head==nullptr||head->next==nullptr) return head。
成功ac

2、递归的过程
其实递归的过程，我觉得就想象只有两个节点就好了，比如1->2->nullptr
反正节点再多，递归的时候也只是处理两个节点，那就干脆直接简化节点数量。
这样容易想明白为什么代码里
是 head->next->next=head;
而不是 newhead->next=head;

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
    ListNode* reverseList(ListNode* head) {
        //递归解法
        
        //递归出口
        //
        if(head==nullptr||head->next==nullptr) return head;

        //递归过程
        //假设只有两个节点
        ListNode* newhead=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;

        return newhead;
    }
};
```