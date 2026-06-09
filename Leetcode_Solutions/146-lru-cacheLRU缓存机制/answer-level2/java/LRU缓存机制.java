
```
  class ListNode {
    public int key;
    public int val;class LRUCache {
    public ListNode next;
    public ListNode pre;

    public ListNode(int key, int val) {
      this.key = key;
      this.val = val;
    }
  }

  public ListNode head = new ListNode(0, 0), tail = head;
  private Map<Integer, ListNode> map = new HashMap<>();
  private int cap = 0;

  public LRUCache(int capacity) {
    this.cap = capacity;
  }

  public int get(int key) {
    if (this.map.containsKey(key)) {
      ListNode node = this.map.get(key);
      // 只有一个node
      if (head.next == node) {
        return node.val;
      }
      // node不是最后一个
      if (node != tail) {
        node.next.pre = node.pre;
      } else {
        tail = tail.pre;
      }
      node.pre.next = node.next;
      head.next.pre = node;
      node.next = head.next;
      node.pre = head;
      head.next = node;

      return node.val;
    }
    return -1;
  }

  public void put(int key, int value) {
    if (this.map.containsKey(key)) {
      // 更新，不删除
      this.map.computeIfPresent(key, (k, v) -> {
        v.val = value;
        return v;
      });
      // 放到head后
      this.get(key);
      return;

    }
    if (this.map.size() >= this.cap) {
      // 删除最后的key
      this.map.remove(this.tail.key);
      this.tail = this.tail.pre;
    }
    ListNode node = new ListNode(key, value);
    this.map.put(key, node);
    if (this.tail == this.head) {
      // 为空，直接插入
      this.head.next = node;
      node.pre = this.head;
      tail = tail.next;
      return;
    }
    // 不为空，插到head后
    node.next = this.head.next;
    node.pre = this.head;
    this.head.next.pre = node;
    this.head.next = node;
  }
}

```