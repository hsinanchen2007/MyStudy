HashMap+ 双向链表 
利用哨兵简化头尾判断
```
class LRUCache {
    private Map<Integer,ListNode> mMap = new HashMap<>();

    private int mMaxCount = 0;
    private int mCount=0;

    private final ListNode mHead = new ListNode(-1,-1);
    private final ListNode mTail = new ListNode(-1,-1);

    private class ListNode{
        int val;
        int key;
        ListNode prev;
        ListNode next;

        ListNode(int key,int val){
            this.key = key;
            this.val =val;
        }
    }


    public LRUCache(int capacity) {
        mMaxCount = capacity;
        mHead.next = mTail;
        mHead.prev =null;

        mTail.prev = mHead;
        mTail.next = null;
    }

    private void addLast(ListNode node){
        mTail.prev.next = node;
        node.prev = mTail.prev;

        mTail.prev = node;
        node.next = mTail;
        mMap.put(node.key,node);
        mCount++;
    }

    private void remove(ListNode node){
        node.prev.next = node.next;
        node.next.prev = node.prev;

        mMap.remove(node.key);
        mCount--;
    }

    private void removeFirst(){
        ListNode head = mHead.next;
        mMap.remove(head.key);
        mCount--;
        mHead.next = mHead.next.next;
        mHead.next.prev = mHead;
    }

    public int get(int key) {
        if(mMap.containsKey(key)){
            ListNode node = mMap.get(key);
            remove(node);
            addLast(node);
            return  node.val;

        }else{
            return -1;
        }
    }


    public void put(int key, int value) {
        if(mMap.containsKey(key)){
            ListNode node  = mMap.get(key);
            node.val = value;
            remove(node);
            addLast(node);
        }else{
            if(mCount == mMaxCount){
                removeFirst();
            }

            ListNode node = new ListNode(key,value);
            addLast(node);
        }
    }
}

```