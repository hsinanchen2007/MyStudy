### 解题思路
首先我们读题，关于LRU算法的题，主要有以下三个信息点：
1：容量是确定的，不动态扩容。
2：超过容量后采取的措施，抛弃最早的key。但是还有一点，保证key的唯一性，如果key存在，则需要替换value。
3：LRU最重要的一点是保证顺序，get 和 put都是操作，顺序都需要调整到最前面。

以上是这个题了传达出来的信息。解读完题目后，要实现以上几个点，我们的思路有以下：
1：容量确定，可以选择固定的数组，也可以选择链表。容量在我们插入的时候需要重点保证。
2：顺序，数组只是存储空间上的顺序，数据与数据间没有顺序上的联系。如果采用数组，增加和删除，移动的数组成本会比较大，最坏的情况O(N)。单链表主要的问题是操作get 和 put的时候需要额外查找前任节点的耗时。综合看，最好的数据结构是双向链表。
3：双向链表，在remove和put时，优势很明显，直接调整前驱节点和后驱节点即可。但是get 和 put 我们都需要判断key是否存在，双向链表的查询是需要遍历节点，最坏的情况是O(N)。
4：在空间不限制的情况下，我们可以借助hash，来存储每个key的节点信息，辅助查询。hash的查询耗时只需要O(1)。

综合以上的思路，我们就比较清楚如何来实现这个LRU了。以下是实现。当然，我们也可以直接使用LinkedHashMap。重点看面试官看重什么，官方封装好的，肯定是各方面都经受过考验的，一般没啥问题，直接使用能体现对LinkedHashMap的理解。如果面试官想考察数据结构方面的，我们用下面这种方式就更适合一些。

### 代码

```java
 class LRUCache {

        private Map<Integer,Node> map = new HashMap<Integer, Node>();
        private Node head;
        private Node tail;
        int capacity = 0;
        int count = 0;
        public LRUCache(int capacity) {
            this.capacity = capacity;
        }

        public int get(int key) {

            Node node = getNode(key);
            if (node == null) return  -1;
            remove(node);
            add(node);
            return  node.getValue().intValue();
        }
        public  Node getNode(int key){
            return  map.get(key);
        }

        public void put(int key, int value) {
            Node p = new Node();
            p.setKey(key);
            p.setValue(value);
            add(p);
        }

        public void remove(Node node){
            if (node == head && node == tail){
                head = null;
                tail = null;
                count --;
                map.remove(node.getKey());
                return;
            }
            if(node == head ){
                head = node.after;
                head.before = null;
            }else if(node == tail){
                tail = node.before;
                tail.after = null;
            }else{
                Node tmp = node;
                node.after.before = tmp.before;
                node.before.after = tmp.after;
            }
            map.remove(node.getKey());
            count--;
           
        }
        public void add(Node node){
                Node oldNode = getNode(node.getKey());
                if(oldNode == null){
                    if (count >= capacity){
                        remove(head);
                    }
                }else{
                    remove(oldNode);
                }
                if (head == null || tail == null){
                    head = node;
                    tail = node;
                }else{
                    node.before = tail;
                    tail.after = node;
                    tail = node;
                }
                map.put(node.getKey(),node);
                count++ ;
        }

        class Node{
            private Integer key;
            private Integer value;
            private Node before;
            private Node after;

            public void setKey(Integer key){
                this.key=key;
            }
            public void setValue(Integer value){
                this.value = value;
            }
            public void setBefore(Node before){
                this.before = before;
            }
            public void setAfter(Node after){
                this.after = after;
            }
            public Integer getKey(){
                return key;
            }
            public Integer getValue(){
                return value;
            }
            public Node getBefore(){
                return before;
            }
            public Node getAfter(){
                return after;
            }
        }
    }
```