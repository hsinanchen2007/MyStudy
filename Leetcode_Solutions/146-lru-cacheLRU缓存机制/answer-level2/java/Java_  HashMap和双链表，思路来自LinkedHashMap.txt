### 思路

采用双链表+hashmap，模仿java容器中的LinkedHashMap的实现；大致是双链表表尾是最新访问的元素，因此表头就是最近最少访问的元素；维护该顺序，就能使得put空间不够时删除表头元素；



### 注意点

主要是双链表的实现方式：

**1.** 如何把元素移动到表尾？

1）元素本身是表尾，不用移动

2）元素本身不是：元素是表头移动时要修改head指针位置，元素不是表头就按照正常移动方法移动就好

**2.** 如何把元素插入到表尾

1）链表是空的，插入则还需要首先设置head为它

2）链表不是空的，按照正常方式插入





```
class LinkNode{
        int val;
        LinkNode after;
        LinkNode before;
        LinkNode(int val){
            this.val = val;
        }
    }
class LRUCache {
    int capacity;
    int size;
    LinkNode tail;
    LinkNode head;
    HashMap<Integer,LinkNode> keymap;
    HashMap<LinkNode,Integer> nodemap;
    public LRUCache(int capacity) {
        this.capacity = capacity;
        size = 0;
        keymap = new HashMap<>();
        nodemap = new HashMap<>();
        tail = null;
        head = null;
    }
    
    public int get(int key) {
        System.out.println(key);
        if(keymap.get(key)==null){
            return -1;
        }
        LinkNode p = keymap.get(key);
        LinkNode bf = p.before;
        LinkNode af = p.after;
        if(p!=tail){
            if(p==head){
                head = af;
                af.before = null;
            }
            else if(p!=head){
                af.before = bf;
                bf.after = af;
            }
            tail.after = p;
            p.before = tail;
            tail = p;
        }
        return p.val;
    }
    
    public void put(int key, int value) {
        if(size+1>capacity){
            LinkNode thishead = head;
            int beforekey = nodemap.get(head);
            keymap.remove(beforekey);
            nodemap.remove(head);
            head = thishead.after;
            if(head!=null){
                head.before = null;
            }
            
        }
        LinkNode newnode = new LinkNode(value);
        if(tail==null){
            head = newnode;
            tail = newnode;
            newnode.before = null;
        }else{
            tail.after = newnode;
            newnode.before = tail;
            tail = newnode;
        }
        size++;
        keymap.put(key,newnode);
        nodemap.put(newnode,key);
        newnode.after = null;
        return;
    }
}


```
