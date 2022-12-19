### 解题思路
HashMap + 双向链表
Map中存<key, Node>,注意，这里的value存的是链表的节点对象，为什么要这样存，主要有两个原因：
* get方法的时候，先通过map获取值，但是还需要将链表对应节点移到末尾，这里存node就可以很方便找到对应链表的节点
* 容量不足移除链表头结点的时候，还需要去map中移除对应键值对，node节点包含key，去map移除就很方便

也就是说<key, node>这里的node是map和链表之间的纽带，方便从map去查询链表，同时也方便链表去map查询对应元素

### 代码

```java
public class LRUCache {
    private Map<Integer, Node> nodeMap;
    private NodeLinkedList nodeList;
    private int capacity;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.nodeMap = new HashMap<>();
        this.nodeList = new NodeLinkedList();
    }
    
    public int get(int key) {
        if(nodeMap.containsKey(key)) {
            Node node = nodeMap.get(key);
            nodeList.moveItemToTail(node);
            return node.value;
        }
        return -1;
    }
    
    public void put(int key, int value) {
        if(nodeMap.containsKey(key)) {
            Node node = nodeMap.get(key);
            node.value = value;
            nodeList.moveItemToTail(node);
        } else {
                Node newNode = new Node(key, value);
                nodeList.addNode(newNode);
                nodeMap.put(key, newNode);
                //超出容量，移除map和链表中元素
                if(nodeMap.size() == capacity + 1) {
                    removeUnusedItem();
                }
        }
    }

    private void removeUnusedItem() {
            Node removeNode = nodeList.removeHead();
            int removeKey = removeNode.key;
            nodeMap.remove(removeKey);
        }


    class Node {
        private int key;
        private int value;
        //前指针
        private Node pre;
        //后指针
        private Node next;

        Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    //自定义双向链表和三个方法
    class NodeLinkedList {
        private Node head;
        private Node tail;

        public void addNode(Node newNode) {
            if(head == null) {
                head = newNode;
                tail = newNode;
            } else { //头结点不空将新节点放入队尾
                tail.next = newNode;
                newNode.pre = tail;
                tail = newNode;
            }
        }

        //移除头结点
        public Node removeHead() {
            Node removeNode = head;

            if(head == tail) {
                head = null;
                tail = null;
            } else {
                head = removeNode.next;
                head.pre = null;
                removeNode.next = null;
            }
            return removeNode;
        }

        //移动指定被访问节点到队尾
        public void moveItemToTail(Node node) {
            if(node == tail) return;
            //断开节点，其实还没有断开，只是将指定节点的前驱节点和后驱节点建立联系
            if(node == head) {
                head = node.next;
                head.pre = null;
            } else {
                node.next.pre = node.pre;
                node.pre.next = node.next;
            }
            //断开节点，将节点移动到队尾
            tail.next = node;
            node.pre = tail;
            node.next = null;
            tail = node;
        }
    }
}

```