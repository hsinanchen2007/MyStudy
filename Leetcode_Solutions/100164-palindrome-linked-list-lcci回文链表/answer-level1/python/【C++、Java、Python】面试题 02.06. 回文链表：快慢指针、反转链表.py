### 方法一：快慢指针找中点，反转后半部分 ###
#### 思路 ####
- `fast`指针和`slow`指针都从`head`开始，`fast`每次前进两步，`slow`每次前进一步
- 从`slow`停止的位置开始，反转链表的后半部分，得到表尾`tail`
- `head`和`tail`分别从链表两端向中间移动，每移动一步比较一次是否相同
  - 当链表长度为偶数时，前半部分和后半部分等长，因此当`tail`为空时即表示比较完毕
  - 当链表长度为奇数时，后半部分比前半部分长一个节点，由于前半部分的最后一个节点仍指向`slow`停止的位置，因此在`tail->next`为空时，`head == tail`，因此也可以将`tail`为空视为终止条件
#### 代码 ####
```cpp []
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *tail = reverse(slow);
        while (tail) {
            if (head->val != tail->val) return false;
            head = head->next;
            tail = tail->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
```
```java []
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode fast = head, slow = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        ListNode tail = reverse(slow);
        while (tail != null) {
            if (head.val != tail.val) return false;
            head = head.next;
            tail = tail.next;
        }
        return true;
    }
    public ListNode reverse(ListNode head) {
        ListNode prev = null, curr = head;
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}
```
```python []
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        fast, slow = head, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        def reverse(head = slow):
            prev, curr = None, head
            while curr:
                next = curr.next
                curr.next = prev
                prev = curr
                curr = next
            return prev
        tail = reverse()
        while tail:
            if head.val != tail.val:
                return False
            head = head.next
            tail = tail.next
        return True
```
#### 复杂度分析 ####
- 时间复杂度 $O(n)$
- 空间复杂度 $O(1)$

***
### 方法二：快慢指针找中点，同时反转前半部分 ###
#### 思路 ####
- `fast`指针和`slow`指针都从`head`开始，`fast`每次前进两步，`slow`每次前进一步，同时反转链表，得到前半部分的尾结点`prev`
- 当链表长度为奇数时`fast`指针停在表尾，当链表长度为偶数时`fast`指针最后为空
  - 若`fast`不为空，说明链表长度为奇数，`slow`指向正中间的节点，不需要进行比较，因此应该再向后移动一步
  - 若`fast`为空，说明链表长度为偶数，两部分等长，不需要再移动`slow`
- `prev`和`slow`从链表中间开始，分别向两端移动，每移动一步比较一次是否相同
#### 代码 ####
```cpp []
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head, *prev = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode *next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        if (fast) slow = slow->next;
        while (slow) {
            if (prev->val != slow->val) return false;
            prev = prev->next;
            slow = slow->next;
        }
        return true;
    }
};
```
```java []
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode fast = head, slow = head, prev = null;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            ListNode next = slow.next;
            slow.next = prev;
            prev = slow;
            slow = next;
        }
        if (fast != null) slow = slow.next;
        while (slow != null) {
            if (prev.val != slow.val) return false;
            prev = prev.next;
            slow = slow.next;
        }
        return true;
    }
}
```
```python []
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        fast, slow, prev = head, head, None
        while fast and fast.next:
            fast = fast.next.next
            next = slow.next
            slow.next = prev
            prev = slow
            slow = next
        if fast:
            slow = slow.next
        while slow:
            if prev.val != slow.val:
                return False
            prev = prev.next
            slow = slow.next
        return True
```
#### 复杂度分析 ####
- 时间复杂度 $O(n)$
- 空间复杂度 $O(1)$