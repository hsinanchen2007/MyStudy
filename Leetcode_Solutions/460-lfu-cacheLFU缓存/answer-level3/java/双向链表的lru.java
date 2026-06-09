### 解题思路
此处撰写解题思路

### 代码

```java
class LFUCache {

   
    private Map<Integer,Node> map = new HashMap<>();
    private Map<Integer,DoubleLink> doubleList = new HashMap<>();

    private int size;

    private int minNums;

    public LFUCache(int capacity) {
        size = capacity;
    }

    public int get(int key) {
         Node node = map.get(key);
         if(node==null){
             return -1;
         }
        onceNow(node);
         return node.getValue();
    }

    public void put(int key, int value) {
        if(size==0)return;
        if(map.containsKey(key)){
            Node node = map.get(key);
            node.value = value;
            onceNow(node);
            return;
        }




        if(size == map.size()){
            DoubleLink doubleLink = doubleList.get(minNums);
            Node removeNode =doubleLink.removeLast();
            if(removeNode!=null){
                map.remove(removeNode.getKey());
            }
        }

        Node node = new Node(key,value);
        map.put(key,node);
        DoubleLink s = doubleList.get(1);
        if(s==null) s = new DoubleLink();

        s.put(node);
        doubleList.put(1,s);


        minNums=1;

    }

    /**
     * 立马更新node的最近使用率
     * @param node
     */
    private void onceNow(Node node ){
        DoubleLink s = doubleList.get(node.getLevel());
        s.remove(node);

        if(s.isEmpty() && minNums == node.getLevel()){
            minNums = node.getLevel()+1;
        }
        node.setLevel(node.getLevel()+1);
        DoubleLink newLink = doubleList.get(node.getLevel());
        if(newLink==null) newLink = new DoubleLink();
        newLink.put(node);
        doubleList.put(node.getLevel(),newLink);
    }


    static class Node {
        private int key;
        private int value;
        private int level;
        private Node next;
        private Node pre;

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
            this.level = 1;
        }

        public int getKey() {
            return key;
        }

        public void setKey(int key) {
            this.key = key;
        }

        public int getValue() {
            return value;
        }

        public void setValue(int value) {
            this.value = value;
        }

        public int getLevel() {
            return level;
        }

        public void setLevel(int level) {
            this.level = level;
        }
    }

    static class DoubleLink{
        private Node header;
        private Node tail;

        public DoubleLink() {
            header = new Node(-1,-1);
            tail = new Node(-2,-2);
            header.next = tail;
            tail.pre = header;
        }

        private void put(Node node){
            Node s = header.next;
            node.pre = header;
            node.next = s;
            header.next = node;
            s.pre = node;

        }

        private boolean isEmpty(){
            if(header.next == tail){
                return true;
            }
            return false;
        }

        private Node removeLast(){
            return remove(tail.pre);
        }

        private Node remove(Node target){

            if(isEmpty())return null;
            Node pre = target.pre;
            Node next = target.next;
            pre.next =next;
            next.pre = pre;
            target.next =null;
            target.pre = null;
            return target;
        }
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```

我第一次解题是 一个map存放 key，和我的Node
Node 里面有key／value／times：使用次数
一个List代表使用频率，接近满的时候，就把list最后一个元素移除
这样做的一个问题是，每次put进去，我最后要排序一次，把times最小的排在后面。
而且每次get的时候也需要排序。

我解体完成之后，看看别人的采用双向链表的方式，我觉得更方便了。

Map，存放 key和Node
再来一个Map 存放 频次和双向链表
每次get的时候，代表这个Node频次升高，从原来双向链表的频次移除，插入到新一个阶段的双向链表头部的后面一个节点

这个方法实在是巧妙