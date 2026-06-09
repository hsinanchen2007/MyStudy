public class LRUCache {

    class Node {
        Integer key;
        Integer value;
        Node next;
        Node pre;

        public Node(Integer key, Integer value) {
            this.key = key;
            this.value = value;
        }
    }

    class DeQue {
        Node head;
        Node last;

        public void addFirst(Node node) {
            node.pre = null;
            if (head == null) {
                node.next = null;
                head = last = node;
            } else {
                node.next = head;
                head.pre = node;
                head = node;
            }
        }

        public Node removeLast() {
            Node res = null;
            if (last != null) {
                res = last;
                last = last.pre;
                if (last == null) {
                    head = null;
                }else
                    last.next=null;
            }
            return res;
        }

        public Node remove(Node node) {
            if (head != null) {
                if (node.pre == null)
                    head = node.next;
                else
                    node.pre.next = node.next;
                if (node.next == null)
                    last = node.pre;
                else
                    node.next.pre = node.pre;
                return node;
            }
            return null;
        }

    }

    Map<Integer, Node> cache;
    DeQue deQue;
    int capacity;

    public LRUCache(int capacity) {
        cache = new HashMap<>(capacity);
        deQue = new DeQue();
        this.capacity = capacity;
    }

    public int get(int key) {
        int res = -1;
        if (cache.containsKey(key)) {
            Node node = cache.get(key);
            res = node.value;
            deQue.remove(node);
            deQue.addFirst(node);
        }
        System.out.println(res);
        return res;
    }

    public void put(int key, int value) {
        Node node;
        if (cache.containsKey(key)) {
            node = cache.get(key);
            deQue.remove(node);
            node.value = value;
        } else {
            if (cache.size() >= capacity) {
                node = deQue.removeLast();
                cache.remove(node.key);
                node.key = key;
                node.value = value;
            } else
                node = new Node(key, value);
        }
        deQue.addFirst(node);
        cache.put(key, node);
    }
}