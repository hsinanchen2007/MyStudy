### 解题思路
此处撰写解题思路

### 代码

```java
class Skiplist {
    private final int MAX_LEVEL = 1 << 4;
    Node[] heads = {};
    private static Random random = new Random();

    public Skiplist() {

    }
    
    private void initialize() {
        heads = new Node[heads.length + 1];
        for (int i = 0; i < heads.length; i++) {
            heads[i] = new Node(-1);
        }
        for (int i = 1; i < heads.length; i++) {
            heads[i].below = heads[i - 1];
        }
    }
    public boolean search(int target) {
        Node p = heads[heads.length - 1];
        if (p.value == target) return true;
        while (p != null) {
            while (p.next == null && p.below != null) {
                p = p.below;
            }
            while (p.next != null && p.next.value <= target) {
                p = p.next;
            }
            if (p.value == target) {
                return true;
            } else {
                p = p.below;
            }
        }
        return false;
    }
    
    public void add(int num) {
    if (heads.length == 0) initialize();
        for (int i = heads.length - 1; i >= 0; i--) {
            Node p = heads[i];
            while (p.next != null && p.next.value < num) {
                p = p.next;
            }
            if (i == 0) {
                insertNewNode(num, p, p.next);
            }
        }
    }
     private void insertNewNode(int value, Node left, Node right) {
        Node newNode = new Node(value);
        left.next = newNode;
        newNode.next = right;
        int newNodeLevel = randomLevel();
        int oldNodeLevel = heads.length;
        if (newNodeLevel > heads.length) {
            Node[] newHeads = Arrays.copyOf(heads, newNodeLevel);
            heads = null;
            for (int i = oldNodeLevel; i < newNodeLevel; i++) {
                newHeads[i] = new Node(-1);
                newHeads[i].below = newHeads[i - 1];
            }
            heads = newHeads;
        }
        {
            Node _preNewNode = newNode;
            for (int i = 1; i < newNodeLevel; i++) {
                Node p = heads[i];
                while (p.value < value && p.next != null && p.next.value < value) {
                    p = p.next;
                }
                Node _tmpNode = p.next;
                p.next = new Node(value);
                p.next.below = _preNewNode;
                p.next.next = _tmpNode;
                _preNewNode = p.next;
            }
        }
    }
    public boolean erase(int num) {
        if (!search(num)) return false;
        return erase(num, heads.length - 1);
    }
    private boolean erase(int num, int level) {
        if (!search(num)) return false;
        Node p = heads[level];
        Node leftNode = p;
        while (p != null) {
            while (p.next == null) {
                p = p.below;
                if (p == null) {
                    return false;
                }
            }
            if (p.next.value < num) {
                leftNode = p;
                p = p.next;
                while (p.next == null) {
                    p = p.below;
                    leftNode = leftNode.below;
                }
            } else if (p.next.value > num) {
                p = p.below;
                leftNode = leftNode.below;
            } else {
                leftNode = p;
                p = p.next;
                leftNode.next = p.next;
                if (p.below != null) {
                    return erase(num, level - 1);
                }
                return true;
            }
        }
        return false;
    }

  private int randomLevel() {
        int level = 1;
        while (random.nextInt() % 2 == 1 && level <= heads.length && level < MAX_LEVEL) {
            level++;
        }
        return level;
    }


    static class Node {
        int value;
        Node next;
        Node below;

        public Node(int value) {
            this.value = value;
        }
    }
}

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist obj = new Skiplist();
 * boolean param_1 = obj.search(target);
 * obj.add(num);
 * boolean param_3 = obj.erase(num);
 */
```