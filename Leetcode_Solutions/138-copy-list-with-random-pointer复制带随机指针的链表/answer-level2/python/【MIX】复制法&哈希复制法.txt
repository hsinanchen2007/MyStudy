### 解题思路
1. 将new-old映射关系存储在hash map中
2. 构建临时双链表, 返回备份链表
3. 调用python内置函数

### 代码

```java []
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
        if(head == null)
            return head;
        copyNext(head);
        copyRandom(head);
        return splitLinkedList(head);
    }

    private void copyNext(Node head){
        Node cur = head;
        while(cur != null){
            Node newNode = new Node(cur.val);
            newNode.next = cur.next;
            newNode.random = cur.random;
            cur.next = newNode;
            cur = newNode.next;
        }
    }

    private void copyRandom(Node head){
        Node cur = head;
        while(cur != null){
            if(cur.next.random != null){
                cur.next.random = cur.random.next;
            }
            cur = cur.next.next;
        }
    }

    private Node splitLinkedList(Node head){
        Node cur = head;
        Node retHead = cur.next;
        while(cur != null){
            Node temp = cur.next;
            cur.next = temp.next;
            cur = temp.next;
            if(temp.next != null)
                temp.next = cur.next;
        }
        return retHead;
    }
}
```
```python []
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        return copy.deepcopy(head)
```
```c++ []
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 使用hash map存储新-旧节点映射关系
        unordered_map<Node*, Node*> rec;
        Node *cur = head;
        while(cur != nullptr){
            Node *newNode = new Node(cur->val);
            rec[cur] = newNode;
            cur = cur->next;
        }

        // next关系维护
        cur = head;
        while(cur != nullptr){
            rec[cur]->next = rec[cur->next];
            cur = cur->next;
        }

        // random关系维护
        cur = head;
        while(cur != nullptr){
            rec[cur]->random = rec[cur->random];
            cur = cur->next;
        }

        return rec[head];
    }
};
```