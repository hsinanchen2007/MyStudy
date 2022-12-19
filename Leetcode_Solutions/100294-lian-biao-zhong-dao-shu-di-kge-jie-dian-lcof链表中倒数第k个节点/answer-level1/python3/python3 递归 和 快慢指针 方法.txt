### 解题思路
此处撰写解题思路 @路漫漫我不畏

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 快慢指针
# class Solution:
#     def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
#         fast = head 
#         slow = head
#         while fast:
#             fast = fast.next
#             if k==0:
#                 slow = slow.next
#             else:
#                 k-=1
#         return slow



# class Solution {
# public:
#     ListNode* getKthFromEnd(ListNode* head, int k) {
#         ListNode* fast = head;
#         ListNode* low = head;
#         while (fast != NULL) {
#             fast = fast->next;
#             if (k == 0) {
#                 low = low->next;
#             } else {
#                 k--;
#             }
#         }
#         return low;        
#     }
# };

# 作者：huwt
# 链接：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/solution/lian-biao-zhong-dao-shu-di-kge-jie-dian-kuai-man-z/
# 来源：力扣（LeetCode）
# 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


# 递归
class Solution:
    def __init__(self):
        self.pos=0
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        if not head: return 0
        ret = self.getKthFromEnd(head.next,k)
        self.pos+=1
        if self.pos==k: return head
        return ret
# class Solution {
# public:
#     int pos = 0;
#     ListNode* getKthFromEnd(ListNode* head, int k) {
#         if (head == NULL) {
#             return 0;
#         }
#         ListNode* ret = getKthFromEnd(head->next, k);
#         pos++;
#         if (pos == k) {
#             return head;
#         }
#         return ret;    
#     }
# };

# 作者：huwt
# 链接：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/solution/lian-biao-zhong-dao-shu-di-kge-jie-dian-kuai-man-z/
# 来源：力扣（LeetCode）
# 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```