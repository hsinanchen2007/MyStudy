审题不认真，题目给出是个排序链表，所以所有重复元素必定相邻。
可得 head.val == head.next.val 时，head.next指针下移 head.next = head.next.next;
程序如下：
```java
    public ListNode deleteDuplicates(ListNode head) {
        ListNode temp = head;
        while(temp != null && temp.next != null) {
            if (temp.val == temp.next.val) {
                temp.next = temp.next.next;
                continue;
            }
            temp = temp.next;
        }
        return head;
    }
```
但是为什么说提到审题不认真，是指没注意到是个排序链表。可使用Set集合帮助链表去除全部重复元素。
程序如下：
```java
    public ListNode deleteDuplicates(ListNode head) {
        ListNode temp = head;
        Set<Integer> hash = new HashSet<>();
        while(temp != null && temp.next != null) {
            if (temp.val == temp.next.val) {
                temp.next = temp.next.next;
                continue;
            }
            if(hash.contains(temp.next.val)){
                temp.next = temp.next.next;
                continue;
            }
            hash.add(temp.val);
            temp = temp.next;
        }
    }
```