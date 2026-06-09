### 解题思路
循环翻转

### 代码

```java []
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;

        ListNode prev = dummy;
        while(prev != null){
            prev = reverseNextKNodes(prev, k);
        }
        // D->head
        return dummy.next;
    }

    // prev->n1->n2->..->nk->nk+1
    // prev->nk->nk-1->..->n1->nk+1
    private ListNode reverseNextKNodes(ListNode prev, int k){
        // find kth node
        ListNode cur = prev;
        ListNode n1 = cur.next;
        for(int i=0; i<k; ++i){
            cur = cur.next;
            if(cur == null){
                return null;
            }   
        }

        ListNode nk = cur;
        ListNode nkp = cur.next;

        // reverse 
        ListNode p = prev;
        cur = prev.next;
        while(cur != nkp){
            ListNode temp = cur.next;
            cur.next = p;
            p = cur;
            cur = temp;
        }
        
        // prev->n1
        // nk->nk-1->..->n1<->prev
        prev.next = nk;
        n1.next = nkp;
        return n1;
    }
}
```
```python []
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if head == None or k<=1:
            return head

        # 子函数
        def reverseKNodes(prev, k):
            cur = prev
            N1 = cur.next
            for _ in range(k):
                cur = cur.next
                if cur == None:
                    return cur

            NK = cur
            NKP = cur.next
            # p记录前驱
            p = prev
            cur = p.next

            while cur != NKP:
                temp = cur.next
                cur.next = p
                p = cur
                cur = temp

            prev.next, N1.next = p, NKP 
            
            return N1

        dummy = ListNode(-1)
        dummy.next = head

        prev = dummy
        while prev != None:
            prev = reverseKNodes(prev, k)

        return dummy.next
```
```c++ []
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 将辅助变量开辟在栈空间上, 待程序结束时自动回收
        if(head == nullptr || k <=1)
            return head;
        ListNode dummy;
        dummy.next = head;
        ListNode *prev = &dummy;
        while(prev != nullptr){
            prev = reverseKNodes(prev, k);
        }

        return dummy.next;
    }

private:
    ListNode *reverseKNodes(ListNode* prev, int k){
        ListNode *cur = prev;
        // 指向待翻转的第一个节点
        ListNode *N1 = cur->next;
        for(int i=0; i<k; ++i){
            cur = cur->next;
            // 如果在k步之内到达末尾, 说明已经不需要翻转该部分
            if(cur == nullptr)
                return cur;
        }

        // 翻转N1~NK部分
        ListNode *NK = cur;
        ListNode *NKP = cur->next;
        ListNode *p = prev;
        cur = p->next;
        while(cur != NKP){
            ListNode *temp = cur->next;
            cur->next = p;
            p = cur;
            cur = temp;
        }

        prev->next = p;
        N1->next = NKP;

        return N1;
    }
};
```