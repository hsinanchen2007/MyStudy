### 居然这么简单？！！！数数就行了：先数一共有多少个节点len，再返回第len/2+1个节点。当然，快慢指针的方法还是需要学习一下的~~甜姨太厉害了！

### 结果
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8.3 MB, 在所有 C++ 提交中击败了90.94%的用户

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
    ListNode* middleNode(ListNode* head) {
        ListNode* h=head;
        int len=0; //一共有多少个节点
        while(h!=NULL){
            len++;
            h=h->next;
        }
        int tmp=len/2+1; 
        while(tmp>1){
            head=head->next;
            tmp--;
        }
        return head;
    }
};
```
### 快慢指针

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* p=head; //慢指针
        ListNode* q=head; //快指针
        while(q!=NULL && q->next!=NULL){//当然是快指针先走到头啦
            p=p->next;
            q=q->next->next;
        }
        return p;
    }
};
```