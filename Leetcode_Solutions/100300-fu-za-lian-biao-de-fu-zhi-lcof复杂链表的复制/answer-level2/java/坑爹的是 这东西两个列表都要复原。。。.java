### 解题思路
执行用时 : 0 ms , 在所有 Java 提交中击败了 100.00% 的用户 
内存消耗 : 39.2 MB , 在所有 Java 提交中击败了 100.00% 的用户

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
        if(head==null){
            return null;
        }
        Node temp = head;
        while(temp !=null){
            Node newNode = new Node(temp .val);
            newNode.next = temp .next;
            temp.next = newNode;
            temp = newNode.next;
        }
        temp = head;
        while(temp!=null){
            Node copyNode= temp.next;
            if(temp.random==null){
                copyNode.random = null;
            }else{
                copyNode.random = temp.random.next;
            }
            temp = copyNode.next;
        }
        temp = head;//7
        Node ans = temp.next; 
        while(temp!=null ){
            Node next = temp.next;//7'
            Node cur = temp; // 13
            temp = next.next; //13
            if(temp!=null){ 
                next.next = temp.next; //7'->13'
            }
            cur.next = temp;
        }
        
        return ans;
    }
    
}
```