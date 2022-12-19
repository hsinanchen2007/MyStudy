### get操作
**将缓存提到队列头部、返回value**
### put操作
**key已存在: 更新value, 缓存移动到队列头部**
**key不存在: 新建key、value, 加入队列头部**

# 代码
```
class LRUCache {
    private int max;
    private Node pre = new Node(-1, -1);
    private Node post = new Node(-1, -1);
    private Map<Integer, Node> map = new HashMap<>();

    public LRUCache(int capacity) {
        max = capacity;
        pre.next = post;
        post.prev = pre;
    }

    public int get(int key) {
        if (!map.containsKey(key)) return -1;
        moveToHead(map.get(key));
        return map.get(key).v;
    }

    public void put(int key, int value) {
        if (map.containsKey(key)) {
            map.get(key).v = value;
            moveToHead(map.get(key));
        } else {
            Node t = new Node(key, value);
            map.put(key, t);
            addToHead(t);
        }
    }

    private void moveToHead(Node v){
        v.next.prev = v.prev;
        v.prev.next = v.next;
        addToHead(v);
    }

    private void addToHead(Node x) {
        x.prev = pre;
        x.next = pre.next;
        pre.next.prev = x;
        pre.next = x;
        if (map.size() > max) {
            map.remove(post.prev.k);
            post.prev.prev.next = post;
            post.prev = post.prev.prev;
        }
    }

    private class Node {
        int k;
        int v;
        Node next;
        Node prev;
        public Node(int k, int v) {
            this.k = k;
            this.v = v;
        }
    }
}
```