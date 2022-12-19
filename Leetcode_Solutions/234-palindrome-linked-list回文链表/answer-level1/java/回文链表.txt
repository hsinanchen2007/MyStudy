
分析问题，找到回文链表的特性：**从头到尾遍历链表**和**从尾到头遍历链表**，得到的序列是相同的，类似于**回文字符串**

## 解法一：借助于栈

### 算法简介 

借助于栈的先进后出特性

1. 先遍历一次单链表，将链表中的结点都压入栈中；
2. 再遍历一次单链表，每次遍历到一个结点，都从栈中弹出一个结点，比较两个结点是否相等，在这个过程中，只要有一个结点不相等，则此单链表就不是回文链表

### 代码实现

```
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null) return true;
        
        Deque<Integer> stack = new ArrayDeque<>();
        
        for (ListNode x = head; x != null; x = x.next) {
            stack.push(x.val);    
        }
        
        boolean isPalindrome = true;
        for (ListNode x = head; isPalindrome && x != null; x = x.next) {
            if (x.val != stack.pop()) {
                isPalindrome = false;
            }
        }
        
        return isPalindrome;
    }
}
```


### 复杂度分析
* 时间复杂度：O(n)
* 空间复杂度：O(n)


## 解法二：反转链表后半部分，再比较

### 算法简介

题目要求空间复杂度为O(1)，这本身就一种提示。

仔细分析回文链表的特性，我们很容易发现，回文链表是前后对称的。而且，题目并没有要求不能破坏单链表，所以，我们可以以中点为轴，切断单链表，并反转后半部分，再比较前后两部分。

解法二分析到这，我们再回过头分析下第一种解法，不难发现，我们多做了很多比较。其实只要比较链表的前半部分和后半部分就可以了。

### 代码实现

```
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null) return true;

        // 计算链表中心结点的位置
        int len = 0;
        for (ListNode x = head; x != null; x = x.next) {
            len++;
        }
        int mid = (int)Math.ceil(len / 2f);

        len = 0;
        ListNode newHead = null;
        for (ListNode x = head; x != null; x = x.next) {
            len++;
            if (len > mid) {
                newHead = x;
                break;
            }
        }

        // 反转
        ListNode cur = newHead;
        newHead = new ListNode(-1);
        while (cur != null) {
            ListNode node = cur;
            cur = cur.next;

            // 插入结点到新链表中
            ListNode node1 = newHead.next;
            newHead.next = node;
            node.next = node1;

        }

        // 比较两个链表
        boolean isPalindrome = true;
        for (ListNode x = newHead.next, y = head;
             x != null && y != null; x = x.next, y = y.next) {
            if (x.val != y.val) {
                isPalindrome = false;
                break;
            }

        }

        return isPalindrome;
    }
}
```

### 优化
寻找中心结点花费：O(n + n/2)，我们可以再优化下：使用快慢指针将时间花费降到O(n)。

稍微解释下快慢指针：程序记录两个指针，快指针每次走两步，慢指针每次走一步，当快指针到达链表尾部时，慢指针刚好到达链表的中点。这种方法要注意链表结点个数为奇数和偶数的情况。

优化过后的代码如下：

```
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null) return true;

        // 计算链表中心结点的位置
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            if (fast != null) {
                slow = slow.next;
            }
        }
        
        // 得到的中心结点以后单链表
        ListNode newHead = reverseList(slow.next);

        // 比较两个链表
        boolean isPalindrome = true;
        for (ListNode x = newHead, y = head;
             x != null && y != null; x = x.next, y = y.next) {
            if (x.val != y.val) {
                isPalindrome = false;
                break;
            }
        }
        return isPalindrome;
    }
    
    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        ListNode next = null;
        while (cur != null) {
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
}
```

### 复杂度分析
* 时间复杂度：O(n)
* 空间复杂度：O(1)


## 总结

做题可以巩固所学的算法知识，这题虽然不太难，但是可以学到以下知识点：

1. 单链表遍历：可以用while循环，也可以用for循环（for循环，我借鉴自Sedgewick《算法》一书)
2. 单链表反转
3. 快慢指针解法（这种方法，从链表探测环一题中学到）
4. 栈
5. 将算法转为代码的能力
