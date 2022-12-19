### 解题思路
此处撰写解题思路

### 代码

```java
class MyHashSet {
    private LinkNode[] nodes;
    public static final int DEFAULT_SIZE=769;
    /** Initialize your data structure here. */
    public MyHashSet() {
        nodes=new LinkNode[DEFAULT_SIZE];
        for(int i=0;i<DEFAULT_SIZE;i++){
            nodes[i]=new LinkNode(0);
        }
    }
    
    protected int hash(int key){
        return key%DEFAULT_SIZE;
    }

    public void add(int key) {
        int index=hash(key);
        
        if(nodes[index].val==0){
            nodes[index].next=new LinkNode(key);
            nodes[index].val++;
            return;
        }
        LinkNode p=nodes[index].next;
        while(p.next!=null){
            if(p.val==key)
                return;
            p=p.next;
        }
        if(p.val==key) return;
        p.next=new LinkNode(key);
        nodes[index].val++;
    }
    
    public void remove(int key) {
        int index=hash(key);
        if(nodes[index].val==0) return;
        LinkNode p=nodes[index];
        LinkNode q=p.next;
        while(q!=null){
            if(q.val==key){
                p.next=q.next;
                nodes[index].val--;
                q=null;
                break;
            }
            q=q.next;
            p=p.next;
        }

    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        int index=hash(key);
        if(nodes[index].val==0) return false;
        LinkNode p=nodes[index].next;
        while(p!=null){
            if(p.val==key){
                return true;
            }
            p=p.next;
        }
        return false;
    }
}

class LinkNode {
    public int val;
    public LinkNode next;
    public LinkNode(){}
    public LinkNode(int x){
        val=x;
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
```