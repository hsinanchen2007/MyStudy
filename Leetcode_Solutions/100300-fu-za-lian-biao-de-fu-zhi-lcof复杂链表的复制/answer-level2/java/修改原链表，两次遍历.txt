### 复杂度分析
时间复杂度：O(2*n)
空间复杂度：O(n)

### 解题思路
两次遍历
分两次遍历
第一次遍历，哈希表存储节点在链表中的位置和节点，并修改原链表每个节点值为位置信息
第二次遍历，填充 random 指针

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

/**
 * 分两次遍历
 * 第一次遍历，哈希表存储节点在链表中的位置和节点，并修改原链表每个节点值为位置信息
 * 第二次遍历，填充 random 指针
 */
class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }
        
        int i = 0;
        HashMap<Integer, Node> map = new HashMap<>();
        Node newHead = new Node(head.val);
        map.put(i++, newHead);

        Node newNode = newHead;
        Node node = head.next;
        // 以 0 作为第一个位置
        head.val = 0;
        // 第一次遍历
        while (node != null) {
            newNode.next = new Node(node.val);
            node.val = i;
            node = node.next;
            newNode = newNode.next;
            map.put(i++, newNode);
        }

        newNode = newHead;
        node = head;
        // 第二次遍历
        while (node != null) {
            if (node.random == null) {
                newNode.random = null;
            }
            else {
                // 找到第 node.random.val 位置的新节点
                Node randomNode = map.get(node.random.val);
                newNode.random = randomNode;
            }
            node = node.next;
            newNode = newNode.next;
        }

        return newHead;
    }
}
```