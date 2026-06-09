执行用时 :18 ms, 在所有 Java 提交中击败了98.01%的用户。内存消耗 :48.2 MB, 在所有 Java 提交中击败了100.00%的用户

### 代码

```java
import java.util.Objects;

public class LRUCache {

    final int MAX_TABLE_SIZE = 1024 * 1024 * 1024;

    private int size;

    private int initCapSize;

    private int n;

    Entry[] table;
    Entry head;
    Entry tail;

    public LRUCache(int capacity) {
        size = 0;
        head = tail = null;
        table = new Entry[n = this.resetSize(initCapSize = capacity)];
    }

    public int size() {
        return size;
    }

    private int resetSize(int n) {
        n = -1 >>> Integer.numberOfLeadingZeros(n);
        return n < 0 ? 1 : (n >= MAX_TABLE_SIZE ? MAX_TABLE_SIZE : (n + 1));
    }

    public void put(int key, int value) {
        int hash = this.hash(key);
        Entry newNode = new Entry(hash, key, value, null);
        int index;
        Entry node = table[index = (hash & (n - 1))];
        if (node == null) {
            table[index] = newNode;
            // 调整位置
            ++size;
            this.setTail(newNode);
        } else {
            while (true) {
                if (this.isSame(node, newNode)) {
                    node.value = newNode.value;
                    // 调整位置
                    this.moveNodeToTail(node);
                    break;
                }
                if (node.next == null) {
                    node.next = newNode;
                    // 调整位置
                    ++size;
                    this.setTail(newNode);
                    break;
                }
                node = node.next;
            }
        }
    }

    private boolean isSame(Entry a, Entry b) {
        if (a == null || b == null) {
            return false;
        }
        return (a.hashCode == b.hashCode && Objects.equals(b.key, a.key));
    }

    public int get(int key) {
        int h = this.hash(key);
        Entry e = table[h & (n - 1)];
        if (e == null) {
            return -1;
        }
        while (true) {
            if (e == null) {
                break;
            }
            if (h == e.hashCode && Objects.equals(key, e.key)) {
                // 调整位置
                this.moveNodeToTail(e);
                return e.value;
            }
            e = e.next;
        }
        return -1;
    }

    public boolean remove(int key) {
        int h = this.hash(key);
        int i;
        Entry e = table[i = (h & (n - 1))];
        if (e == null) {
            return false;
        }
        Entry pre = null;
        while (true) {
            if (e == null) {
                break;
            }
            if (h == e.hashCode && Objects.equals(key, e.key)) {
                // 调整位置
                this.changeNode(e);
                --size;
                if (pre == null) {
                    table[i] = e.next;
                } else {
                    pre.next = e.next;
                }

                return true;
            }
            pre = e;
            e = e.next;
        }
        return false;
    }

    private void changeNode(Entry e) {
        if (e == null) {
            return;
        }
        if (e == head) {
            head = head.after;
            return;
        }
        if (e == tail) {
            tail = e.before;
            return;
        }
        Entry before = e.before;
        Entry after = e.after;
        if (before != null) {
            before.after = after;
        }
        if (after != null) {
            after.before = before;
        }
    }

    private void moveNodeToTail(Entry node) {
        this.changeNode(node);
        this.setTail(node);
    }

    private void setTail(Entry newNode) {
        // 检查LRU容量
        this.checkSize();
        if (head == null) {
            head = newNode;
        } else {
            if (tail == null) {
                tail = newNode;
                head.after = tail;
                tail.before = head;
                tail.after = null;
            } else {
                tail.after = newNode;
                newNode.before = tail;
                tail = newNode;
                tail.after = null;
            }
        }
    }

    private void checkSize() {
        if (size <= initCapSize) {
            return;
        }
        // 去掉第一个
        if (head != null) {
            this.remove(head.key);
        }
    }

    private int hash(int key) {
        return key;
    }

    static class Entry {

        final int hashCode;
        final int key;
        int value;
        Entry next;

        Entry before;
        Entry after;

        public Entry(int hashCode, int key, int value, Entry next) {
            this.hashCode = hashCode;
            this.key = key;
            this.value = value;
            this.next = next;
            this.before = this.after = null;
        }
    }
}

```