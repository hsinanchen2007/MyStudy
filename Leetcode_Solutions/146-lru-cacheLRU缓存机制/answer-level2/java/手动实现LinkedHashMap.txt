### 解题思路
1. 关键是Noed类的定义，包含key、value、pre、after、next
2. pre和after是为了维护双向链表，next是为了维护hash冲突时，将冲突元素放在同一条链表中
3. put元素时，除了要放在data数组中，也要维护好在双向链表中的位置
4. get元素时，把get元素挪到链表尾，代表刚刚被访问过，那么需要挪出元素时，就挪走链表头的元素
5. 使用头节点可以简化一部分操作
6. 还有个细节就是，若put元素，发现同key的值，那么不能简单更新其值，也要把该元素挪到双向链表尾

### 代码

```java
class LRUCache {
    
    private Node head;
    private Node tail;
    private Node[] data;
    private int size;

    static class Node{

        int key;
        int value;
        Node pre;
        Node after;
        Node next;

        Node(int k, int v){
            key = k;
            value = v;
            pre = null;
            after = null;
            next = null;
        }
    }

    public LRUCache(int capacity) {
        //初始化头节点
        Node node = new Node(-1, -1);
        data = new Node[capacity];
        size = 0;
        head = node;
        tail = node;
    }

    public int get(int key) {
        int index = key % data.length;
        Node front = data[index];
        while (front != null && front.key != key){
            front = front.next;
        }
        if (front == null)
            return -1;
        //此时front为待访问的元素
        update(front);
        return front.value;
    }

    public void put(int key, int value) {
        int index = key % data.length;
        Node node = data[index];
        Node delete = null;
        while (node != null){
            //记录这个点
            if (node.key == key){
                delete = node;
                break;
            }
            node = node.next;
        }
        //需要插入
        if (node == null){
            if (size < data.length){
                Node temp = new Node(key, value);
                Node front = data[index];
                if (front == null){
                    data[index] = temp;
                }
                else {
                    Node bak = data[index];
                    data[index] = temp;
                    temp.next = bak;
                }
                tail.after = temp;
                temp.pre = tail;
                tail = temp;
                size++;
            }
            else {
                //此时size等于data.length 挪出最近最久未使用的元素 也就是head指向的元素
                Node del = head.after;
                del_from_linkedList();
                //将del从数组中挪出
                del_from_data(del);
                //将元素插入数组
                put(key, value);
            }
        }
        else {
            del_from_linkedList(delete);
            del_from_data(delete);
            put(key, value);
        }
    }

    //将元素从数组中挪出
    private void del_from_data(Node node){
        int index = node.key % data.length;
        //如果是头节点
        if (data[index].key == node.key){
            data[index] = data[index].next;
            size--;
        }
        //如果不是头节点
        else {
            Node front = data[index];
            while (front.next.key != node.key){
                front = front.next;
            }
            front.next = node.next;
            node.next = null;
            size--;
        }
    }

    //将元素从双向链表中挪出
    private void del_from_linkedList(){
        Node del = head.after;
        head.after = del.after;
        if (del.after != null){
            del.after.pre = head;
        }
        del.pre = null;
        del.after = null;
    }

    //将特定元素元素从双向链表中挪出
    private void del_from_linkedList(Node node){
        Node pre = node.pre;
        if (node == tail){
            tail = pre;
            tail.after = null;
            node.pre = null;
        }
        else {
            Node after = node.after;
            pre.after = after;
            after.pre = pre;
        }
    }

    //将元素移动到链表尾
    private void update(Node node){
        if (node != tail){
            Node pre = node.pre;
            Node after = node.after;
            pre.after = after;
            after.pre = pre;

            tail.after = node;
            node.pre = tail;
            tail = node;
            tail.after = null;
        }
    }
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```