// 🙋**我以前的题解竟然被每日一题翻牌了，今天终于不用新更了呢**

// **以下解法中，方法 3 相对于其他人很多几百毫秒的 $O(1)$ 实现来说，是目前最优的 $O(1)$ 实现哦，只需要 13 毫秒！~**
// **想看更多干货题解，请戳 [我的主页](https://leetcode-cn.com/u/sweetiee/)！**

// ----


//  [TOC]

// ### 一、$O(1)$ 解法

// 下面要说的 $O(1)$ 的 3 种 Java 写法其实是 1 种解法，因为具体实现细节中使用的数据结构不同，导致性能有所差异。为方便理解，下面 3 个实现，**性能从略挫逐步优化**：

// 1. `HashMap<Integer, Node> cache` 存缓存的内容; `min` 是最小访问频次; `HashMap<Integer, LinkedHashSet<Node>> freqMap` 存每个访问频次对应的 Node 的双向链表（写法 1 为了方便，直接用了 JDK 现有的 LinkedHashSet，其实现了 1 条双向链表贯穿哈希表中的所有 Entry，支持以插入的先后顺序对原本无序的 HashSet 进行迭代）

// 2. `HashMap<Integer, Node> cache` 存缓存的内容; `min` 是最小访问频次; `HashMap<Integer, DoublyLinkedList>freqMap` 存每个访问频次对应的 Node 的双向链表（写法 2 与写法 1 一样，只不过将 JDK 自带的 LinkedHashSet 双向链表实现改成了自定义的双向链表 DoublyLinkedList，减少了一些哈希相关的耗时）

// 3. `HashMap<Integer, Node> cache` 存缓存的内容; 将写法 1 写法 2 中的 freqMap 不再用 HashMap 来表示，而是直接用双向链表 `DoublyLinkedList firstLinkedList; DoublyLinkedList lastLinkedList`，省去了一些哈希相关的耗时，也不需要用 min 来存储最小频次了，lastLinkedList.pre 这条 DoublyLinkedList 即为最小频次对应的 Node 双向链表，lastLinkedList.pre.tail.pre 这个 Node 即为最小频次的双向链表中的所有 Node 中最先访问的 Node，即容量满了后要删除的 Node。


// **下面贴这仨实现，不多哔哔了直接在代码中注释啦**
// **最优解是第三种，详尽注释了。 其他的实现实在懒得注释了哎🥺，没法折叠好傻x，直接跳去第三种叭**


// #### O(1) 解法 —— 双向链表直接使用LinkedHashSet
// ``` Java
class LFUCache {
    Map<Integer, Node> cache;  // 存储缓存的内容
    Map<Integer, LinkedHashSet<Node>> freqMap; // 存储每个频次对应的双向链表
    int size;
    int capacity;
    int min; // 存储当前最小频次

    public LFUCache(int capacity) {
        cache = new HashMap<> (capacity);
        freqMap = new HashMap<>();
        this.capacity = capacity;
    }
    
    public int get(int key) {
        Node node = cache.get(key);
        if (node == null) {
            return -1;
        }
        freqInc(node);
        return node.value;
    }
    
    public void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        Node node = cache.get(key);
        if (node != null) {
            node.value = value;
            freqInc(node);
        } else {
            if (size == capacity) {
                Node deadNode = removeNode();
                cache.remove(deadNode.key);
                size--;
            }
            Node newNode = new Node(key, value);
            cache.put(key, newNode);
            addNode(newNode);
            size++;     
        }
    }

    void freqInc(Node node) {
        // 从原freq对应的链表里移除, 并更新min
        int freq = node.freq;
        LinkedHashSet<Node> set = freqMap.get(freq);
        set.remove(node);
        if (freq == min && set.size() == 0) { 
            min = freq + 1;
        }
        // 加入新freq对应的链表
        node.freq++;
        LinkedHashSet<Node> newSet = freqMap.get(freq + 1);
        if (newSet == null) {
            newSet = new LinkedHashSet<>();
            freqMap.put(freq + 1, newSet);
        }
        newSet.add(node);
    }

    void addNode(Node node) {
        LinkedHashSet<Node> set = freqMap.get(1);
        if (set == null) {
            set = new LinkedHashSet<>();
            freqMap.put(1, set);
        } 
        set.add(node); 
        min = 1;
    }

    Node removeNode() {
        LinkedHashSet<Node> set = freqMap.get(min);
        Node deadNode = set.iterator().next();
        set.remove(deadNode);
        return deadNode;
    }
}

class Node {
    int key;
    int value;
    int freq = 1;

    public Node() {}
    
    public Node(int key, int value) {
        this.key = key;
        this.value = value;
    }
}
// ```

// #### O(1) 解法 —— 自定义双向链表
// ``` Java
class LFUCache {
    Map<Integer, Node> cache; // 存储缓存的内容
    Map<Integer, DoublyLinkedList> freqMap; // 存储每个频次对应的双向链表
    int size;
    int capacity;
    int min; // 存储当前最小频次

    public LFUCache(int capacity) {
        cache = new HashMap<> (capacity);
        freqMap = new HashMap<>();
        this.capacity = capacity;
    }
    
    public int get(int key) {
        Node node = cache.get(key);
        if (node == null) {
            return -1;
        }
        freqInc(node);
        return node.value;
    }
    
    public void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        Node node = cache.get(key);
        if (node != null) {
            node.value = value;
            freqInc(node);
        } else {
            if (size == capacity) {
                DoublyLinkedList minFreqLinkedList = freqMap.get(min);
                cache.remove(minFreqLinkedList.tail.pre.key);
                minFreqLinkedList.removeNode(minFreqLinkedList.tail.pre); // 这里不需要维护min, 因为下面add了newNode后min肯定是1.
                size--;
            }
            Node newNode = new Node(key, value);
            cache.put(key, newNode);
            DoublyLinkedList linkedList = freqMap.get(1);
            if (linkedList == null) {
                linkedList = new DoublyLinkedList();
                freqMap.put(1, linkedList);
            }
            linkedList.addNode(newNode);
            size++;  
            min = 1;   
        }
    }

    void freqInc(Node node) {
        // 从原freq对应的链表里移除, 并更新min
        int freq = node.freq;
        DoublyLinkedList linkedList = freqMap.get(freq);
        linkedList.removeNode(node);
        if (freq == min && linkedList.head.post == linkedList.tail) { 
            min = freq + 1;
        }
        // 加入新freq对应的链表
        node.freq++;
        linkedList = freqMap.get(freq + 1);
        if (linkedList == null) {
            linkedList = new DoublyLinkedList();
            freqMap.put(freq + 1, linkedList);
        }
        linkedList.addNode(node);
    }
}

class Node {
    int key;
    int value;
    int freq = 1;
    Node pre;
    Node post;

    public Node() {}
    
    public Node(int key, int value) {
        this.key = key;
        this.value = value;
    }
}

class DoublyLinkedList {
    Node head;
    Node tail;

    public DoublyLinkedList() {
        head = new Node();
        tail = new Node();
        head.post = tail;
        tail.pre = head;
    }

    void removeNode(Node node) {
        node.pre.post = node.post;
        node.post.pre = node.pre;
    }

    void addNode(Node node) {
        node.post = head.post;
        head.post.pre = node;
        head.post = node;
        node.pre = head;
    }
}
// ```

// #### O(1) 解法 —— 存储频次的HashMap改为直接用双向链表（最优实现 13ms 双100%）

// ``` Java

class LFUCache {

  Map<Integer, Node> cache;  // 存储缓存的内容，Node中除了value值外，还有key、freq、所在doublyLinkedList、所在doublyLinkedList中的postNode、所在doublyLinkedList中的preNode，具体定义在下方。

  DoublyLinkedList firstLinkedList; // firstLinkedList.post 是频次最大的双向链表

  DoublyLinkedList lastLinkedList;  // lastLinkedList.pre 是频次最小的双向链表，满了之后删除 lastLinkedList.pre.tail.pre 这个Node即为频次最小且访问最早的Node

  int size;

  int capacity;



  public LFUCache(int capacity) {

​    cache = new HashMap<> (capacity);

​    firstLinkedList = new DoublyLinkedList();

​    lastLinkedList = new DoublyLinkedList();

​    firstLinkedList.post = lastLinkedList;

​    lastLinkedList.pre = firstLinkedList;

​    this.capacity = capacity;

  }

  

  public int get(int key) {

​    Node node = cache.get(key);

​    if (node == null) {

​      return -1;

​    }

    // 该key访问频次+1

​    freqInc(node);

​    return node.value;

  }

  

  public void put(int key, int value) {

​    if (capacity == 0) {

​      return;

​    }

​    Node node = cache.get(key);

    // 若key存在，则更新value，访问频次+1

​    if (node != null) {

​      node.value = value;

​      freqInc(node);

​    } else {

      // 若key不存在

​      if (size == capacity) {

​        // 如果缓存满了，删除lastLinkedList.pre这个链表（即表示最小频次的链表）中的tail.pre这个Node（即最小频次链表中最先访问的Node），如果该链表中的元素删空了，则删掉该链表。

​        cache.remove(lastLinkedList.pre.tail.pre.key);

​        lastLinkedList.removeNode(lastLinkedList.pre.tail.pre);

​        size--;

​        if (lastLinkedList.pre.head.post == lastLinkedList.pre.tail) {

​          removeDoublyLinkedList(lastLinkedList.pre);

​        } 

​      }

      // cache中put新Key-Node对儿，并将新node加入表示freq为1的DoublyLinkedList中，若不存在freq为1的DoublyLinkedList则新建。

​      Node newNode = new Node(key, value);

​      cache.put(key, newNode);

​      if (lastLinkedList.pre.freq != 1) {

​        DoublyLinkedList newDoublyLinedList = new DoublyLinkedList(1);

​        addDoublyLinkedList(newDoublyLinedList, lastLinkedList.pre);

​        newDoublyLinedList.addNode(newNode);

​      } else {

​        lastLinkedList.pre.addNode(newNode);

​      }

​      size++;

​    }

  }


  /**
   * node的访问频次 + 1
   */
  void freqInc(Node node) {

​    // 将node从原freq对应的双向链表里移除, 如果链表空了则删除链表。

​    DoublyLinkedList linkedList = node.doublyLinkedList;

​    DoublyLinkedList preLinkedList = linkedList.pre;

​    linkedList.removeNode(node);

​    if (linkedList.head.post == linkedList.tail) { 

​      removeDoublyLinkedList(linkedList);

​    }


​    // 将node加入新freq对应的双向链表，若该链表不存在，则先创建该链表。

​    node.freq++;

​    if (preLinkedList.freq != node.freq) {

​      DoublyLinkedList newDoublyLinedList = new DoublyLinkedList(node.freq);

​      addDoublyLinkedList(newDoublyLinedList, preLinkedList);

​      newDoublyLinedList.addNode(node);

​    } else {

​      preLinkedList.addNode(node);

​    }

  }


  /**
   * 增加代表某1频次的双向链表
   */
  void addDoublyLinkedList(DoublyLinkedList newDoublyLinedList, DoublyLinkedList preLinkedList) {

​    newDoublyLinedList.post = preLinkedList.post;

​    newDoublyLinedList.post.pre = newDoublyLinedList;

​    newDoublyLinedList.pre = preLinkedList;

​    preLinkedList.post = newDoublyLinedList; 

  }


  /**
   * 删除代表某1频次的双向链表
   */
  void removeDoublyLinkedList(DoublyLinkedList doublyLinkedList) {

​    doublyLinkedList.pre.post = doublyLinkedList.post;

​    doublyLinkedList.post.pre = doublyLinkedList.pre;

  }

}



class Node {

  int key;

  int value;

  int freq = 1;

  Node pre; // Node所在频次的双向链表的前继Node 

  Node post; // Node所在频次的双向链表的后继Node

  DoublyLinkedList doublyLinkedList;  // Node所在频次的双向链表



  public Node() {}

  

  public Node(int key, int value) {

​    this.key = key;

​    this.value = value;

  }

}



class DoublyLinkedList {

  int freq; // 该双向链表表示的频次

  DoublyLinkedList pre;  // 该双向链表的前继链表（pre.freq < this.freq）

  DoublyLinkedList post; // 该双向链表的后继链表 (post.freq > this.freq)

  Node head; // 该双向链表的头节点，新节点从头部加入，表示最近访问

  Node tail; // 该双向链表的尾节点，删除节点从尾部删除，表示最久访问



  public DoublyLinkedList() {

​    head = new Node();

​    tail = new Node();

​    head.post = tail;

​    tail.pre = head;

  }



  public DoublyLinkedList(int freq) {

​    head = new Node();

​    tail = new Node();

​    head.post = tail;

​    tail.pre = head;

​    this.freq = freq;

  }



  void removeNode(Node node) {

​    node.pre.post = node.post;

​    node.post.pre = node.pre;

  }



  void addNode(Node node) {

​    node.post = head.post;

​    head.post.pre = node;

​    head.post = node;

​    node.pre = head;

​    node.doublyLinkedList = this;

  }



}

// ```



// ---

// ## 二、$O(logN)$ 解法

// #### O(logN) 解法 —— 使用小根堆找到 `freq` 最小，因为 Java 中的 PriorityQueue 默认就是小根堆, 实现最简单

// 每次将访问频次 `freq` 最小的且最先访问的上浮到堆顶，下面用全局自增 `idx` 表示访问的先后，或者可以直接改成 `idx = System.nanoTime()` 用以比较访问时间的先后。

// ``` Java
class LFUCache {

    Map<Integer, Node> cache;
    Queue<Node> queue;
    int capacity;
    int size;
    int idx = 0;

    public LFUCache(int capacity) {
        cache = new HashMap<>(capacity);
        if (capacity > 0) {
            queue = new PriorityQueue<>(capacity);
        }
        this.capacity = capacity;
    }
    
    public int get(int key) {
        Node node = cache.get(key);
        if (node == null) {
            return -1;
        }
        node.freq++;
        node.idx = idx++;
        queue.remove(node);
        queue.offer(node);
        return node.value;

    }
    
    public void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        Node node = cache.get(key);
        if (node != null) {
            node.value = value;
            node.freq++;
            node.idx = idx++;
            queue.remove(node);
            queue.offer(node);
        } else {
            if (size == capacity) {
                cache.remove(queue.peek().key);
                queue.poll();
                size--;
            } 
            Node newNode = new Node(key, value, idx++);
            cache.put(key, newNode);
            queue.offer(newNode);
            size++;
        }
    }
}

class Node implements Comparable<Node> {
    int key;
    int value;
    int freq;
    int idx;

    public Node() {}

    public Node(int key, int value, int idx) {
        this.key = key;
        this.value = value;
        freq = 1;
        this.idx = idx;
    }

    public int compareTo(Node node) {
		int diff = freq - node.freq;
        return diff != 0? diff: idx - node.idx;
    }
}
// ```

// ## 三、O(N) 解法

// #### 最傻fufuの O(N) —— 只用1条双向链表

// 使 `freq` 小的 `Node` 在链表的左边，`freq` 大的 `Node` 在链表的右边，`freq` 相等的话最久使用的 `Node` 在左边、最近使用的 `Node` 在右边，因此满了之后删除 `head.post`，该 `Node` 即 `freq` 最小且最久访问的。
// 每次 `node` 的 `freq++` 后，从当前位置向后遍历链表，直到 `nextNode.freq > node.freq || nextNode == tail`，在 `nextNode` 之前插入该 `node`。

// ``` Java
class LFUCache {

    HashMap<Integer, Node> cache;
    Node head;
    Node tail;
    int capacity;
    int size;

    public LFUCache(int capacity) {
        cache = new HashMap<Integer, Node>(capacity);
        this.capacity = capacity;
        head = new Node();
        tail = new Node();
        head.post = tail;
        tail.pre = head;
    }
    
    public int get(int key) {
        Node node = cache.get(key);
        if (node == null) {
            return -1;
        }
        node.freq++;
        moveToNewPosition(node);
        return node.value;
    }
    
    public void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        Node node = cache.get(key);
        if (node != null) {
            node.value = value;
            node.freq++;
            moveToNewPosition(node);
        } else {
            if (size == capacity) {
                cache.remove(head.post.key);
                removeNode(head.post);
                size--;
            }
            Node newNode = new Node(key, value);
            addNode(newNode);
            cache.put(key, newNode);
            size++;
        }
    }

    private void moveToNewPosition(Node node) {
        Node nextNode = node.post;
        removeNode(node);
        while (nextNode.freq <= node.freq && nextNode != tail) {
            nextNode = nextNode.post;
        }
        nextNode.pre.post = node;
        node.pre = nextNode.pre;
        node.post = nextNode;
        nextNode.pre = node;
    }

    private void addNode(Node node) {
        node.post = head.post;
        node.pre = head;
        head.post.pre = node;
        head.post = node;
        moveToNewPosition(node);
    }

    private void removeNode(Node node) {
        node.pre.post = node.post;
        node.post.pre = node.pre;
    }
}

class Node {
    int key;
    int value;
    int freq = 1;
    Node pre;
    Node post;

    public Node() {}
    public Node(int key, int value) {
        this.key = key;
        this.value = value;
    }
}
// ```


// ---

// 嗯，很全/::)