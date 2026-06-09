### 解题思路
此处撰写解题思路

### 代码

```java
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/
class Solution {
    public Node copyRandomList(Node head) {
        if(head==null) return null;

        Node cur = head;
        while(cur.next!=null){
            Node copy = new Node(cur.val);
            copy.next=cur.next;
            cur.next=copy;
            cur = copy.next;
        }
        cur.next = new Node(cur.val);

        cur=head;
        while(cur!=null){
            if(cur.random!=null){
                cur.next.random = cur.random.next;
            }
            cur = cur.next.next;
        }

        cur=head;
        Node cur2 = head.next;
        Node ans = head.next;
        while(cur2.next!=null){
            cur.next = cur2.next;
            cur2.next = cur2.next.next;
            cur = cur.next;
            cur2 = cur2.next;
        }
        cur.next=null;
        
        return ans;
    }
}
```