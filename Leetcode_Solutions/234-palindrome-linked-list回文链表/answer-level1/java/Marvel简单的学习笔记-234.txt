## 三种解法与复杂度优缺点分析。

### 解法一：借助数组
最直接的想法就是将链表所有结点的值存到数组后再判断，因为数组可以利用索引，同时比较数组前半段和后半段。

时间复杂度：O(n)。
空间复杂度：O(n)。需要额外的数组空间存储各结点的值。

优点：能保持链表的结构不变。
缺点：需要额外的线性空间。

代码：
```java
class Solution {
    public boolean isPalindrome(ListNode head) {
        List<Integer> list = new ArrayList<Integer>();
        while(head != null)
        {
            list.add(head.val);
            head = head.next;
        }
        int len = list.size();
        Integer[] a = list.toArray(new Integer[len]);
        for(int i = 0; i < len/2; i++)
        {
            int x = a[i], y = a[len - 1 - i];
            if(x != y)  return false;
        }
        return true;
    }
}
```

### 解法二：反转链表的一半（快慢指针）
解法一简单直观，是因为借助数组后可以利用索引，既可以顺序遍历数组，也可以逆序遍历数组，因此分别从头尾往中间检查就可以完成整个数组的判断。而链表却不能逆序遍历，那要如何做呢？
反转链表的一半。
这样一来，顺序遍历反转后的那一半，同时顺序遍历另一半，就起到了解法一中数组的效果：从一头和一尾同时向中间检查（或从中间同时向一头一尾检查）。
反转链表我们之前已做过，至于如何反转一半，在于找到链表的中点。这里再次介绍双指针中的快慢指针，通过设置一快一慢的双指针，快指针一次走两步，慢指针一次走一步，快指针走完两圈慢指针走完一圈，快指针走完一圈，慢指针走到一半，这样就找到了中点。由此可注意到，快慢指针除了应用在环形序列循环序列外，还可以用在寻找中点的场景。
既可以反转链表前半段也可以反转链表的后半段，完成反转后，剩下的工作就自然水到渠成了。

时间复杂度：O(n)。
空间复杂度：O(1)。

优点：最优的时空复杂度。
缺点：反转会使得链表的结构被破坏（但是可以通过额外的操作将其恢复）。

反转链表的后半段：
```java
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode fast = head, slow = head;
        while(fast != null && fast.next != null)
        {
            fast = fast.next.next;
            slow = slow.next;
        }
        if(fast != null)    slow = slow.next;
        ListNode prev = null, current = slow;
        while(current != null)
        {
            ListNode temp = current.next;
            current.next = prev;
            prev = current;
            current = temp;
        }
        while(prev != null)
        {
            if(head.val != prev.val)    return false;
            head = head.next;
            prev = prev.next;
        }
        return true;
    }
}
```

寻找链表中点的同时反转链表的前半段：
```java
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode fast = head, slow = head;
        ListNode prev = null, current = head;
        while(fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
            current.next = prev;
            prev = current;
            current = slow;
        }
        if(fast != null)    slow = slow.next;
        while(slow != null)
        {
            if(prev.val != slow.val)    return false;
            prev = prev.next;
            slow = slow.next;
        }
        return true;
    }
}
```

### 解法三：递归
利用递归的特性可以做到从一头一尾同时向中间检查。但理解起来不如前两种方法容易。

时间复杂度：O(n)。
空间复杂度：O(n)。递归会使用n个内存栈，相当于用了额外的栈空间存储了链表。

```java
class Solution {
    private ListNode front;

    public boolean isPalindrome(ListNode head) {
        front = head;
        return recursive(head);
    }
    private boolean recursive(ListNode current) {
        if(current == null) return true;
        if(recursive(current.next))
        {
            if(current.val != front.val)
                return false;
            else
            {
                front = front.next;
                return true;
            }
        }
        return false;
    }
}
```