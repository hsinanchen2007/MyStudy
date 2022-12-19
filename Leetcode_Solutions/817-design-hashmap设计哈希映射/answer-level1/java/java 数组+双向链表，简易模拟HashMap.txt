* 由于是简易模拟HashMap的key存储，所以不带扩容，使用固定长度数组
* 冲突时使用双向链表在同一个bucket下存储
* y = x ％ length 作为哈希函数
* 用时85ms，战胜95.74%的java提交记录

```java
class MyHashMap {

    class Node{
        int key, value;
        Node prev, next;
        
        Node (int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    private int length = 100;
    private Node[] data = new Node[length];
    
    /** Initialize your data structure here. */
    public MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    public void put(int key, int value) {
        int index = key % length;
        Node curr = data[index];
        if (curr == null) {
            Node node = new Node(key, value);
            data[index] = node;
            return;
        }
        while(true) {
            if (curr.key == key) {
                curr.value = value;
                return;
            }
            if(curr.next == null) {
                Node node = new Node(key, value);
                node.prev = curr;
                curr.next = node;
                return;
            } else {
                curr = curr.next;
            }
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        int index = key % length;
        Node curr = data[index];
        while(curr != null) {
            if (curr.key == key) {
                return curr.value;
            }
            curr = curr.next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        int index = key % length;
        Node curr = data[index];
        if (curr != null && curr.key == key) {
            Node next = curr.next;
            if (next != null) {
                next.prev = null;
            }
            data[index] = next;
            return;
        }
        while(curr != null) {
            if (curr.key == key) {
                Node next = curr.next;
                Node prev = curr.prev;
                if (next != null) {
                    next.prev = prev;
                }
                if (prev != null) {
                    prev.next = next;
                }
                return;
            }
            curr = curr.next;
        }
    }
}
```