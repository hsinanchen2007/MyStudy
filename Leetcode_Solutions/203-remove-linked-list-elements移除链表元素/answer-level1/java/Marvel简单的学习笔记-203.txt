## 解题思路
本题实现不难，但删除时需要注意到头结点的问题。给定的链表可能头结点就需要删除，甚至头结点及其之后连续的若干个结点也需要删除，这样一来就会面临一个问题：什么时候处理头结点？
自然，可以在一开始时就处理头结点的问题；也可以最后才来处理头结点的问题；还可以使用一个辅助头结点，统一处理链表就不需要额外考虑原头结点的问题了。
基于此，下面给出三种解法分别对应以上三种情况。最后第四种解法则是使用递归的思想，前三种为非递归。

### 解法一：优先处理头结点

代码
```java
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        while(head != null && head.val == val)
        {
            head = head.next;
        }
        if(head == null)    return null;
        ListNode old = head, current = head.next;
        while(current != null)
        {
            if(current.val == val)  
                old.next = current.next;
            else                    
                old = current;
            current = current.next;
        }
        return head;
    }
}
```

### 解法二：最后处理头结点
到了最后，只剩一个头结点未被检查，故单独检查一个头结点即可。

代码
```java
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if(head == null)    return null;
        ListNode old = head, current = head.next;
        while(current != null)
        {
            if(current.val == val)  
                old.next = current.next;
            else                    
                old = current;
            current = current.next;
        }        
        if(head.val == val) return head.next;
        else                return head;
    }
}
```

### 解法三：使用辅助头结点统一处理

代码
```java
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode aux = new ListNode(0);
        aux.next = head;
        ListNode old = aux, current = aux.next;
        while(current != null)
        {
            if(current.val == val) 
                old.next = current.next;
            else
                old = current;
            current = current.next;
        }        
        return aux.next;
    }
}
```

### 解法四：递归

代码
```java
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if(head == null)    return null;
        if(head.val == val) return removeElements(head.next, val); 
        head.next = removeElements(head.next, val);
        return head;
    }
}
```