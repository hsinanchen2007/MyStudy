### 解题思路1-栈
（1）利用栈结构的先进后出的特性，先将元素全部压入栈，再依次弹出。
（2）注意在重新构建链表的指针时是 `new ListNode(stack.pop().val)`,否则会与之前的next混乱。
（3）O(n)的时间复杂度和O(n)的空间复杂度。
### 代码1
```java
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode root = new ListNode(0);
        ListNode root2 = root;
        Stack<ListNode> stack = new Stack();
        while(head != null){
            stack.push(head);
            head = head.next;
        }
        while(!stack.isEmpty()){
            root.next = new ListNode(stack.pop().val);
            root = root.next;
        }

        return root2.next;        
    }
}

```
### 解题思路2-迭代法
（1）建立三个指针`pre, cur, next`;三个结点依次循环迭代

### 代码2
```java
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        while(cur != null){
            ListNode nextNode = cur.next;
            cur.next = pre;
            pre = cur;
            cur = nextNode;
        }

        return pre;
    }
}
```

