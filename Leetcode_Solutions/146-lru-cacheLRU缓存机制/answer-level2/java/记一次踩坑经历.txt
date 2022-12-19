### 解题思路
本题的解答相信学过操作系统的人都知道思路，维护一个栈的栈头和栈尾来模拟最近最少使用的情况，同时为了时间复杂度为常数级，将栈改成双向链表，这样维护双向链表的头和尾也可以达到一样的效果，同时配合哈稀映射操作就降为O(1)
这里我主要要记录的是我踩的一个坑：以为一个key可以对应多个value。。。。导致每次put一个key已拥有的节点时，我总是按照一样的更新流程进行。导致了答案的错误。

### 代码

```java
class LRUCache {
    class CacheNode
    {
        int key;
        int value;
        CacheNode prev;
        CacheNode next;
        public CacheNode(int key,int value)
        {
            this.key=key;
            this.value=value;
            prev=null;
            next=null;
        }
    }
    private int capacity;
    private Map<Integer,CacheNode> cache;
    private CacheNode head,tail;
    public LRUCache(int capacity) {
        this.capacity=capacity;
        this.cache=new HashMap(capacity);
        head=new CacheNode(-1,-1);
        tail=new CacheNode(-1,-1);
        head.next=tail;
        tail.prev=head;
    }
    
    public int get(int key) 
    {
        CacheNode node=cache.get(key);
        if(node==null)return -1;
        updateTail(node);
        return node.value;
    }
    
    public void put(int key, int value) 
    {
        CacheNode newNode=new CacheNode(key,value);
        CacheNode node=cache.get(key);
        if(node==null)
        {
            if(cache.size()>=capacity)
            {
                CacheNode oldNode=head.next;
                
                deleteNode(oldNode);
                cache.remove(oldNode.key);
            }
            addNode(newNode);
            cache.put(key,newNode);
        }
        else{
            node.value=value;
            updateTail(node);
        }
    }
    //remove the head and add to tail;
    private void updateTail(CacheNode node)
    {
        //shed connection
        deleteNode(node);
        //add to tail
        addNode(node);
    }
    //shed connection 
    private void deleteNode(CacheNode node)
    {
        CacheNode prev=node.prev;
        CacheNode next=node.next;
        prev.next=next;
        next.prev=prev;

    }
    //add to tail connection
    private void addNode(CacheNode newNode)
    {
        newNode.prev=tail.prev;
        newNode.next=tail;
        tail.prev.next=newNode;
        tail.prev=newNode;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```