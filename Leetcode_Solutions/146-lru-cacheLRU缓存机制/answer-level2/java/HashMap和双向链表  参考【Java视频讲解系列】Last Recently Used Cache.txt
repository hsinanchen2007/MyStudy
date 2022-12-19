我真的是菜是原罪呀，参考别人的代码和视频，扣了半天才码出来。
首先，先设计一个DoubleListNode双向链表的类，这个链表包含 key 和value
使用dummy将头尾节点设置出来
那么这里需要了解下 LRU缓存机制是怎么样的，查了下，好像说是内存缓存机制，管理虚拟内存的时候，将要用的数据置换进来，就需要将之前的内存中的不常用的数据置换出去，这里的LRU 全称是Least  Recently used 最近最少使用算法。简单理解就是 将最久没有使用过的页面数据置换出去。
那么这里借助双向链表，将最近使用的过的放置在头部，当达到缓存区域阈值的时候，将末尾的页面删除。

这里分为get和put

首先来讲一下get
    当缓存区不存在该元素的时候，返回-1；如果存在该元素的时候，我们就需要将原来链表中的节点删除，在将该节点添加到链表的头部。返回该节点的value；
然后put的时候，如果不存在该元素，那么我们需要判断以下，缓存区的大小是否大于map的大小，如果大于的话，我们需要将尾部节点删除，然后在进行添加操作；如果存在该元素就需要更新该元素的值，以及更新该元素的位置。

```
class LRUCache {
    DoubleListNode list;
    Map<Integer,DoubleListNode> map ;
    int size;
    static DoubleListNode head;
    static DoubleListNode tail;
    public LRUCache(int capacity) {
        size =capacity;
        map = new HashMap<Integer,DoubleListNode>();
        head = new DoubleListNode(-1,-1);
        tail = new DoubleListNode(-1,-1);
        head.next =tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        if(size==0){
            return -1;
        }
        if(map.containsKey(key)){
        	DoubleListNode node = map.get(key);
            delete(node);
            add(node);
            return map.get(key).val;
        }
        return -1;
        
    }
    
    public void put(int key, int value) {
        if(size ==0)
            return;
        if(!map.containsKey(key)) {
            if(map.size()>=size){
                DoubleListNode OldTail = tail.prev;
                delete(OldTail);
                map.remove(OldTail.key);
            }
            DoubleListNode node = new DoubleListNode(key,value);
            add(node);
            map.put(key,node);
            
        }else{
            DoubleListNode node_0 = map.get(key);
            delete(node_0);
            map.remove(node_0.key);
            DoubleListNode node2 = new DoubleListNode(key,value);
            add(node2);
            
            map.put(key,node2);
        }
    }

    private static void delete(DoubleListNode node){
    	DoubleListNode prev = node.prev;
    	DoubleListNode next = node.next;
        prev.next = next;
        next.prev =prev;
        
    }
    
    private static void add(DoubleListNode node){
        DoubleListNode OldFirst = head.next;
        head.next = node;
        node.prev = head;
        node.next = OldFirst;
        OldFirst.prev = node;
    }
    
}
 class DoubleListNode{
    DoubleListNode prev;
    DoubleListNode next;
    int val;
    int key;
    public DoubleListNode(int key,int val){
    	this.key = key;
    	this.val = val;
    	
    }

}

```
