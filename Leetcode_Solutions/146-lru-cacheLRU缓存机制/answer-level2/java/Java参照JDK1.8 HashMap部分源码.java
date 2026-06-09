# 模拟LRU 缓存机制

## 如何实现LRU的更新：双向链表 Doubly Linked List
Intuition: 越靠近链表开头的元素，越常用；越靠近链表解位的元素，越不常用；
1. 为什么是双向？第一，方便删除；第二，方便取链表末端元素并删除。
2. 当一个Node被加入、更新、修改的时候，都会被放到这个链表的最开头。
3. 当Cache缓存已经满了，链表末端元素会被删除。

## 如何实现HashMap
源码的大制做法（只是笔者的理解）：位桶+链表/红黑树。
当链表长度超过8，该链表就会转成红黑树。

### Node节点，存储key和value，以及双向指针
```java
class Node {
	public int key;
	public int value;
	public Node pre;
	public Node next;
	
	/**
	 * Constructor
	 * */
	public Node( int _key, int _value) {
		key = _key;
		value = _value;
		pre = null;
		next = null;
	}
}
```

### 自定义双向链表
```java
class DoublyLinkedList {
	private Node head;
	private Node tail;
	private int size;
	
	/**
	 * Constructor
	 * */
	public DoublyLinkedList() {
		head = new Node(-1, -1);
		tail = new Node(-1, -1);
		head.next = tail;
		head.pre = null;
		tail.pre = head;
		tail.next = null;
		size = 0;
	}
	
	/**
	 * Add a node in the head of the linked list
	 * */
	public void addFirst(Node node) {
		node.next = head.next;
		node.pre = head;
		
		head.next.pre = node;
		
		head.next = node;
		size++;
	}
	
	/**
	 * Remove a node by key
	 * */
	public void remove(int key) {
		Node p = head.next;
		while( p != null ) {
			if( p.key == key ) {
				p.pre.next = p.next;
				p.next.pre = p.pre;
				p = null;
				size--;
				return ;
			}
			p = p.next;
		}
		// System.out.println("remove error...");
	}
	
	/**
	 * Remove the last node of the list and return this node
	 * */
	public Node removeLast() {
		if( tail.pre == head ) {
			return null;
		}
		Node last = tail.pre;
		last.pre.next = tail;
		tail.pre = last.pre;
		return last;
	}
	
	/**
	 * get value by key
	 * */
	public int getValueByKey(int key) {
		Node p = head.next;
		while( p != null ) {
			if( p.key == key ) {
				return p.value;
			}
			p = p.next;
		}
		
		// System.out.println("Cannot find that key");
		return -1;
	}
	
	/**
	 * set value by key
	 * */
	public void setValueByKey(int key, int value) {
		Node p = head.next;
		while( p != null ) {
			if( p.key == key ) {
				p.value = value;
				return ;
			}
			p = p.next;
		}
		
		// System.out.println("Cannot find that key");
	}
	
	/**
	 * getter for linked size
	 * */
	public int size() {
		return size;
	}
}
```

### 缓存映射图
```java
class LRUCache {
       
    private int capacity;
	private Set<Integer> keySet;
	private static final int MAXIMUM_CAPACITY = 1 << 30;
	private DoublyLinkedList[] table;
	private DoublyLinkedList priorityQueue;
	
	/**
	 * Constructor
	 * */
	public LRUCache(int _capacity) {
		capacity = _capacity;
		keySet = new HashSet<Integer>();
		table = new DoublyLinkedList[getTableSize()];
		priorityQueue = new DoublyLinkedList();
	}
	
	/**
	 * get operation
	 * */
	public int get( int key ) {
		int hash = getHash(key);
		if( table[hash] == null ) {
			return -1;
		}
		
		DoublyLinkedList list = table[hash];
		int value = list.getValueByKey(key);
        if( value == -1 ) {
            return value;
        }
		priorityQueue.remove(key);
		priorityQueue.addFirst(new Node(key, value));
		return value;
	}
	
	/**
	 * put operation
	 * */
	public void put( int key, int value ) {
		// if key exists, overwrite value and add to most recent used.
		if( keySet.contains(key) ) {
			int hash = getHash(key);
			DoublyLinkedList list = table[hash];
			list.setValueByKey(key, value);
			priorityQueue.remove(key);
			priorityQueue.addFirst(new Node(key, value));
			return ;
		}
		
		// if key does not exists
		if( size() == capacity ) {
			System.out.println("Full");
            // if the cache is full               
            // remove and retrieve the last key of the priority list
            Node lru = priorityQueue.removeLast();
            keySet.remove(lru.key);
            // then delete the LRU node
            int hash = getHash(lru.key);
            DoublyLinkedList list = table[hash];
            // System.out.println("Try to remove key: " + lru.key);
            list.remove(lru.key);
        }
		
		// put
		int hash = getHash(key);
		if( table[hash] == null ) {
			table[hash] = new DoublyLinkedList();
		}
		DoublyLinkedList list = table[hash];
		list.addFirst(new Node(key, value));
		keySet.add(key);
		priorityQueue.addFirst(new Node(key, value));
		
	}
	
	/**
	 * getter
	 * */
	public int size() {
		return keySet.size();
	}
	
	public Set<Integer> keySet() {
		return keySet;
	}
	
	/**
	 * helper functions
	 * */
	/**
     * Returns a power of two size for the given target capacity.
     */
    private int getTableSize() {
        int n = capacity - 1;
        n |= n >>> 1;
        n |= n >>> 2;
        n |= n >>> 4;
        n |= n >>> 8;
        n |= n >>> 16;
        return (n < 0) ? 1 : (n >= MAXIMUM_CAPACITY) ? MAXIMUM_CAPACITY : n + 1;
    }
    
    private int getHash(int key) {
    	return key % table.length;
    }
}
```

