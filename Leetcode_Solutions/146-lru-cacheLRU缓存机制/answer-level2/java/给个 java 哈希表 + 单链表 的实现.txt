好像没有看到单链表的解法，其实使用单链表也是可以的
value 保存当前 key 对应结点的前一个结点
这样删除某个 key 对应的结点就不需要重头遍历链表了
```java
public class LRUCache {
	private class Node{
		int key;
		int value;
		Node next;
	}
	private int capacity;
	private HashMap<Integer, Node> cache;
	private Node head;
	private Node tail;
	
    public LRUCache(int capacity) {
    	this.capacity = capacity;
    	cache = new HashMap<>(capacity);
    	head = new Node();
    	head.next = null;
    	tail = head;
    }
    
    private void removeNode(Node preNode, Node node){
    	if(null != node.next){
    		// 此时 node 会被放到链首，node.key 的 value 会被 head 结点覆盖
    		cache.put(node.next.key, preNode);
    	}else{
    		tail = preNode;
    		cache.remove(node.key); // 此时 node 是淘汰数据
    	}
    	preNode.next = node.next;
    }
    
    private void insertNode(Node node){
    	if(null != head.next) cache.put(head.next.key, node);
    	else tail = node;
    	cache.put(node.key, head);
    	node.next = head.next;
    	head.next = node;
    }
    
    public int get(int key) {
    	Node preNode, node;
    	if(null == (preNode = cache.get(key)) 
    			|| null == (node = preNode.next)) return -1;
    	// 删除结点
    	removeNode(preNode, node);
    	// 头插
    	insertNode(node);
    	return node.value;
    }
    
    public void put(int key, int value) {
    	Node preNode, node;
    	if(null != (preNode = cache.get(key))
    			&& null != (node = preNode.next)){
        	// 删除结点
        	removeNode(preNode, node);
        	// 头插
        	insertNode(node);
        	node.value = value;
        	return;
    	}
    	if(cache.size() >= capacity) removeNode(cache.get(tail.key), tail);
    	Node newNode = new Node();
    	newNode.key = key;
    	newNode.value = value;
	insertNode(newNode);
    }
}
```


