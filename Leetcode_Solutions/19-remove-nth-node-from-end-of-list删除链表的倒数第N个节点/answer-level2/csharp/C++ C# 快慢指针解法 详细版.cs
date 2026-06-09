![image.png](https://pic.leetcode-cn.com/202129aed5f3088d9e6f28559ddc5151c919215a214ddad454020f069902f703-image.png)

### 解题思路
刷了几天题，一个心得感悟就是除了数据结构和算法能力，更多的是考察阅读理解的能力。。。

本题要求删除倒数第n个元素，传统做法依次遍历，第一次找到整个链表长度，第二次找到第n个元素，删除，返回删除后链表，但是肯定大家不会选择这个算法。

更好的做法是快慢指针，这个技巧可以说第一次看到有种惊艳的感觉，它定义两个指针，根据实际应用，有可能一个走得快，一个走得慢；或者一个先走，一个后走。本题就是后者案例。

本题的难点是删除元素是第一个的时候该怎么处理，以及如果找到被删元素的前一个，把它和被删元素的后一个拼接起来。

要删除倒数第n个，也就是正着数第K-n+1个，其中K为链表长度。
### c++

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;//快指针
        ListNode* slow = head;//慢指针
        ListNode* pre_slow = head;//慢指针前一个
        while(--n>0)//快指针先走n-1步
            fast = fast->next;
        
        while(fast != nullptr && fast->next != nullptr) {//快慢指针一起跑，直到快指针到达最后一个节点
            pre_slow = slow;//保存慢指针前一个节点
            fast = fast->next;
            slow = slow->next;
        }
        if(slow == head) return head->next;//特殊处理，待删除的是第一个元素
        pre_slow->next = slow->next;//删除slow指针处元素
        return head;
    }
};
```

### C#

```c#
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        ListNode fast = head;//快指针
        ListNode slow = head;//慢指针
        ListNode pre_slow = head;//慢指针前一个
        while(--n > 0) {//快指针先走n-1步
            fast = fast.next;
        }
        while(fast != null && fast.next != null) {//快慢指针一起跑，直到快指针到达最后一个节点
            pre_slow = slow;//保存慢指针前一个节点
            fast = fast.next;
            slow = slow.next;
        }
        if(slow == head)//特殊处理，待删除的是第一个元素
            return head.next;
        pre_slow.next = slow.next;//删除slow指针处元素
        return head;
    }
}
```


### Python3

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        
        fast = head
        slow = head
        pre_slow = head

        while n-1 > 0 :
            fast = fast.next
            n = n-1
        
        while(fast and fast.next):
            pre_slow = slow
            fast = fast.next
            slow = slow.next
        
        if slow == head:
            return head.next
        pre_slow.next = slow.next
        return head
```