### 解题思路
1. 归并排序(空间复杂度$O(1)$)
2. 快速排序(未实现)

### 代码

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
    ListNode* sortList(ListNode* head) {
        // mergeSort
        if(head == nullptr || head->next == nullptr)
            return head;
        return mergeSort(head);
    }

private:
    ListNode* mergeSort(ListNode* head){
        if(head != nullptr && head->next != nullptr){
            ListNode *mid = findMidNode(head);
            ListNode *right = mergeSort(mid->next);
            // 断开链表
            mid->next = nullptr;
            ListNode *left = mergeSort(head);

            return merge(left, right);
        }
        return head;
    }

    ListNode* merge(ListNode *left, ListNode *right){
        ListNode *dummy = new ListNode(-1);
        
        ListNode *cur = dummy;
        while(left != nullptr && right != nullptr){
            if(left->val <= right->val){
                cur->next = left;
                cur = cur->next;
                left = left->next;
            }
            else if(left->val > right->val){
                cur->next = right;
                cur = cur->next;
                right = right->next;
            }
        }

        if(left != nullptr)
            cur->next = left;
        if(right != nullptr)
            cur->next = right;

        return dummy->next;
        
    }

    // 定位链表的中间节点
    ListNode* findMidNode(ListNode* head){
        // 先让pFast移动一步, 使得mid位于链表中间前半部分
        ListNode *pFast = head->next, *pSlow = head;
        while(pFast != nullptr && pFast->next != nullptr){
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }

        return pSlow;
    }
};
```
```java []
class Solution {
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null)
            return head;

        return mergeSort(head);
    }

    private ListNode merge(ListNode left, ListNode right){
        ListNode dummy = new ListNode(-1);
        ListNode p = dummy;
        while(left != null && right != null){
            if(left.val < right.val){
                p.next = left;
                p = p.next;
                left = left.next;
            }
            else{
                p.next = right;
                p = p.next;
                right = right.next;
            }
        }
        if(left != null)
            p.next = left;

        if(right != null)
            p.next = right;

        return dummy.next;

    }

    private ListNode mergeSort(ListNode head){
        if(head != null && head.next != null){
            ListNode mid = findMidNode(head);
            ListNode right = mergeSort(mid.next);
            mid.next = null;
            ListNode left = mergeSort(head);

            return merge(left, right);
        }

        return head;
    }

    // 快慢指针定位中间节点
    private ListNode findMidNode(ListNode head){
        ListNode pFast = head.next;
        ListNode pSlow = head;
        while(pFast != null && pFast.next != null){
            pFast = pFast.next.next;
            pSlow = pSlow.next;
        }
        return pSlow;
    }
}
```
```python []
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head

        return self.mergeSort(head)

    def mergeSort(self, head):
        if head and head.next:
            mid = self.findMidNode(head)
            right = self.mergeSort(mid.next)
            mid.next = None
            left = self.mergeSort(head)

            return self.merge(left, right)

        return head

    def merge(self, left, right):
        dummy = ListNode(-1)
        p = dummy
        while left and right:
            if left.val < right.val:
                p.next = left
                p = p.next
                left = left.next
            else:
                p.next = right
                p = p.next
                right = right.next
        
        if left:
            p.next = left

        if right:
            p.next = right

        return dummy.next


    def findMidNode(self, head):
        pFast, pSlow = head.next, head
        while pFast and pFast.next:
            pFast = pFast.next.next
            pSlow = pSlow.next
        return pSlow
```