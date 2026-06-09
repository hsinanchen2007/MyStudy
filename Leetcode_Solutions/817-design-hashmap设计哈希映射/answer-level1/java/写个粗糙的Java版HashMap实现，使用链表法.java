参考源码实现
```
class MyHashMap {
    private static final int DEFAULT_CAPACITY = 16;
    private static final float DEFAULT_LOAD_FACTOR = 0.75f;

    private int size;
    private int capacity;
    private float factor; // loadFactor是负载因子，表示整体上table被占用的程度，是一个浮点数，默认为0.75
    private int threshold; // threshold表示阈值，当键值对个数size大于等于threshold时考虑进行扩展，一般而言，threshold等于table.length乘以loadFactor

    private Node[] table;

    @SuppressWarnings("unchecked")
    public MyHashMap(int capacity, float factor) {
        if (capacity <= 0) {
            capacity = DEFAULT_CAPACITY;
        }
        if (factor <= 0) {
            factor = DEFAULT_LOAD_FACTOR;
        }

        // 为了方便，不考虑容量的溢出问题了

        // 获取>=capacity的2的幂次方值
        int minimumCapacity = 1;
        capacity -= 1;
        while (capacity != 0) {
            capacity >>= 1;
            minimumCapacity <<= 1;
        }
        capacity = minimumCapacity;

        this.factor = factor;
        this.capacity = capacity;
        this.threshold = (int) (capacity * factor);

        this.table = new Node[this.capacity];
    }

    public MyHashMap() {
        this(DEFAULT_CAPACITY, DEFAULT_LOAD_FACTOR);
    }

    private class Node {
        private int key;
        private int value;
        private Node next;

        Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }


    private int hash(Object key) {
        if (key == null) {
            return 0;
        }
        int hashCode = key.hashCode();
        // 高位运算 h = key.hashCode()为32位，将这32位的高16位于低16位进行异或运算，是高低bit都参与运算
        return hashCode ^ (hashCode >>> 16);
    }

    public void put(int key, int value) {
        ensureCapacity();

        int pos = getPos(key, table);
        if (table[pos] == null) { // 桶中未有数据
            Node node = new Node(key, value);
            table[pos] = node;
            size++;
        } else {
            Node head = table[pos]; // 取出头节点
            Node tmp = head;
            while (tmp != null) {
                if (key == tmp.key) {
                    tmp.value = value; // 覆盖此key对应的value
                    break;
                }
                tmp = tmp.next;
            }
            if (tmp == null) { // tmp为null说明哈希碰撞了，桶中还没有此键值对
                Node node = new Node(key, value); // 将新节点插入到链表头部
                node.next = head;
                table[pos] = node;
                size++;
            }
        }
    }

    @SuppressWarnings("unchecked")
    private void ensureCapacity() {
        if (size >= threshold) { // 键值对数量大于阈值时，需要扩容
            // 取出桶中的所有链表节点，然后重新计算位置，再放入扩容后的桶中

            capacity <<= 1; // 容量扩大两倍
            threshold = (int) (capacity * factor);// 重新计算阈值

            Node[] newTable = new Node[capacity];
            for (Node node : table) {
                Node tmp = node; // 取出原数组的头节点
                while (tmp != null) { // 记得链表每个点都要调整位置
                    int pos = getPos(tmp.key, newTable); // 求出所在的新数组的位置

                    Node next = tmp.next;

                    tmp.next = newTable[pos];
                    newTable[pos] = tmp;

                    tmp = next;
                }
            }
            table = newTable;
        }
    }

    // 算出key所在的桶的位置
    private int getPos(Object key, Node[] table) {
        // length为2的幂次方，h & (length-1)等同于求模运算：h % length
        return hash(key) & (table.length - 1);
    }

    public int get(int key) {
        int pos = getPos(key, table);
        if (table[pos] == null) { // 没有发现此键
            return -1;
        } else { // 可能存在哈希碰撞
            Node head = table[pos]; // 取出头节点
            while (head != null) {
                if (key == head.key) {
                    return head.value;
                }
                head = head.next;
            }
            return -1;
        }
    }

    public void remove(int key) {
        int pos = getPos(key, table);

        if (table[pos] == null) { // 没有发现此键
            return;
        } else {
            Node head = table[pos]; // 取出头节点
            Node preNode = null;
            while (head != null) {
                if (key == head.key) {
                    break;
                }
                preNode = head;
                head = head.next;
            }
            if (head != null) { // 找到了删除的节点
                Node next = head.next;
                head.next = null;
                if (preNode == null) { // 删除的节点是头节点的情况
                    table[pos] = next;
                } else {
                    preNode.next = next;
                }
                size--;
            }
        }
    }

    public int size() {
        return size;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (Node node : table) {
            Node tmp = node;
            sb.append("(");
            while (tmp != null) {
                sb.append("{").append(tmp.key).append(":").append(tmp.value).append("},");
                tmp = tmp.next;
            }
            sb.append(")");
        }
        sb.append("]，大小为：").append(size());
        return sb.toString();
    }
}
```