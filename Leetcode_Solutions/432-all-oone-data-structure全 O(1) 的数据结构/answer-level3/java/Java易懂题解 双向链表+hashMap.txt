
```
class AllOne {

    class Node{
        int value;
        String key;
        Node pre;
        Node next;
        public Node(String key, int value) {
            this.key = key;
            this.value = value;
        }
    }
    
    HashMap<String, Node> map = new HashMap<>();
    
    Node head;
    Node tail;
    /** Initialize your data structure here. */
    public AllOne() {
        head = new Node("", -1);
        tail = new Node("", -1);
        head.next = tail;
        tail.pre = head;
    }
    
    // 将src插入到des的前面
    public void insertPre(Node src, Node des) {
        Node temp = des.pre;
        temp.next = src;
        src.pre = temp;
        des.pre = src;
        src.next = des;
    }
    
    // 将src插入到des的后面
    public void insertNext(Node src, Node des) {
        Node temp = des.next;
        temp.pre = src;
        src.next = temp;
        des.next = src;
        src.pre = des;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    public void inc(String key) {
        // 如果map中包含key,找到key对应的node
        if(map.containsKey(key)) {
            Node node = map.get(key);
            node.value ++;
            // 找到大于等于它的第一个Node,插入到其前面
            if(node.next != tail) {
                Node temp = node.next;
                while(temp!=tail && temp.value<node.value) {
                    temp = temp.next;
                }
                // 连接node断开处前面的和后面的节点
                node.pre.next = node.next;
                node.next.pre = node.pre;
                // 将node插入到temp的前面
                insertPre(node, temp);
            }
          
        } else {
            // 如果map中不包含key,则直接创建一个node插入到head的后面，同时将key记录到map中
            Node node = new Node(key, 1);
            map.put(key, node);
            insertNext(node, head);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    public void dec(String key) {
        // map中包含key,不包含的话不管了
        if(map.containsKey(key)) {
            Node node = map.get(key);
            // 如果key对应的node值为1，则从链表中移除节点，map中也移除该key
            if(node.value == 1) {
              node.pre.next = node.next;
              node.next.pre = node.pre;  
              map.remove(key);
            } else {
              // 如果key对应的node值不为1，则向前寻找到它前方的第一个小于它的节点temp，插入到temp后方
              node.value --;
              if(node.pre != head) {
                Node temp = node.pre;
                while(temp!=head && temp.value>node.value) {
                    temp = temp.pre;
                }
                // 连接断开处的
                node.pre.next = node.next;
                node.next.pre = node.pre;
                // 插入到temp后方
                insertNext(node, temp);
                
              }
                
            }
            
        }
    }
    
    /** Returns one of the keys with maximal value. */
    public String getMaxKey() {
        return tail.pre.key;
    }
    
    /** Returns one of the keys with Minimal value. */
    public String getMinKey() {
        return head.next.key;
    }
}
```
