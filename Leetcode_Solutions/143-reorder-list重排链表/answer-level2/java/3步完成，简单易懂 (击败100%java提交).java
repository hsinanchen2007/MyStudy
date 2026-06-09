#### 结果
![result.png](https://pic.leetcode-cn.com/43fd2a0222c89e1332acadcb2cc29862a55c45eda63a1f9b3bc6684b2628fef6-result.png)

#### 思路：
1. 先将链表一分为二，比如`1->2->3->4->5->null`，就分为`1->2-null`，`3->4->5->null`。
2. 将第二部分链表翻转，`3->4->5->null`变为`5->4->3->null`
3. 经过第二步，原链表变为`1->2-null`和`5->4->3->null`，再把这两部分结合起来就行。
#### 解决方案：
1. 第一步可以用快慢指针，这样只需要遍历一次链表就可以完成。假设指针为`fast`和`slow`。
    注意：
    1. 屡清楚`fast`和`slow`是从哑结点开始还是从`head`节点开始对这个操作有没有影响。
    2. 原链表节点个数是奇数个还是偶数个对这个操作有没有影响。
    3. 这里我让`fast`和`slow`从`head`节点开始，如果节点个数为奇数，最终`fast`指向空,如果节点个数为偶数，最终`fast`不指向空。当然，这个题目中不管`fast`是否指向空对这个操作都没有影响。
    4. 代码： 
```java
        ListNode slow = head;
        ListNode fast = head;
        ListNode pre = null;
        //slow、fast起始指向头节点(不是哑结点)，执行以下循环后，将链表一分为二，
        //第一段： [head,pre]，第二段[slow,fast]，
        //如果原链表节点为奇数个，fast不为null,
        //如果原链表节点为偶数个，fast为null,
        while(fast != null && fast.next != null){
            pre = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        pre.next = null;
```
2. 翻转链表的操作为[LeetCode 206](https://leetcode-cn.com/problems/reverse-linked-list/)题，代码：
    
```java
        //将第二段链表翻转,翻转之后头节点为 preNode
        ListNode preNode = null;
        ListNode curNode = slow;
        ListNode nextNode = null;
        while(curNode != null){
            nextNode = curNode.next;
            curNode.next = preNode;
            preNode = curNode;
            curNode = nextNode;
        }
```
3. 这个题目中返回值为`void`，所以最终我们需要修改`head`，而不是返回某一个节点，可以另起一个链表节点，然后遍历`1->2-null`和`5->4->3->null`追加到它的后面即可。
    注意
    1. 当原链表节点个数为偶数时，这个两个子链表长度一样，当原链表节点个数为奇数时，第二个子链表比第一个子链表多一个节点，所以最后还需要再判断一下。
    2. 代码：
```java
        //将两段链表合并为一段
        ListNode header = new ListNode(Integer.MAX_VALUE);
        ListNode list = header;
        while(head != null && preNode != null){
            list.next = head;
            head = head.next;
            
            list.next.next = preNode;
            preNode = preNode.next;

            list = list.next.next;
        }
        if(preNode != null){
            list.next = preNode;
        }
        head = header.next;
```
4. 完整代码：
```java
public class Test143 {
    public static void main(String[] args) {
        //尾插法构建链表进行测试
        ListNode header = new ListNode(Integer.MAX_VALUE);
        ListNode tail = header;
        ListNode newNode = null;
        int arr [] = new int[]{1,2,3,4,5};
        for (int i = 0; i < arr.length; i++) {
            newNode = new ListNode(arr[i]);
            tail.next = newNode;
            tail = tail.next;
        }
        header = header.next;

        reorderList(header);

        while(header != null){
            System.out.print(header.val + "\t");
            header = header.next;
        }

    }
    public static void reorderList(ListNode head) {
        if(head == null || head.next == null || head.next.next == null){
            return;
        }
        ListNode slow = head;
        ListNode fast = head;
        ListNode pre = null;
        //slow、fast起始指向头节点(不是哑结点)，执行以下循环后，将链表一分为二，
        //第一段： [head,pre]，第二段[slow,fast]，
        //如果原链表节点为奇数个，fast不为null,
        //如果原链表节点为偶数个，fast为null,
        while(fast != null && fast.next != null){
            pre = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        pre.next = null;

        //将第二段链表翻转,翻转之后头节点为 preNode
        ListNode preNode = null;
        ListNode curNode = slow;
        ListNode nextNode = null;
        while(curNode != null){
            nextNode = curNode.next;
            curNode.next = preNode;
            preNode = curNode;
            curNode = nextNode;
        }
        //将两段链表合并为一段
        ListNode header = new ListNode(Integer.MAX_VALUE);
        ListNode list = header;
        while(head != null && preNode != null){
            list.next = head;
            head = head.next;
            
            list.next.next = preNode;
            preNode = preNode.next;

            list = list.next.next;
        }
        if(preNode != null){
            list.next = preNode;
        }
        head = header.next;
    }
}
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
    }
}
```

