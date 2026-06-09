代码实际上参考Redis的`skiplist`写法，那边的代码写的是真的漂亮。
下面只是在它上面的基础上，精简而成。

```java
class Skiplist {

    static class Entry {
        Entry[] next;
        int val;
        int count;
        int level;

        public Entry(int val, int level) {
            this.val = val;
            this.count = 1;
            this.level = level;
            this.next = new Entry[level];
        }
    }

    private static final int MAX_LEVEL = 64;

    private Entry head;

    private Random random;

    public Skiplist() {
        this.head = new Entry(Integer.MIN_VALUE, MAX_LEVEL);
        this.random = new Random();
    }

    public boolean search(int target) {
        Entry cur = head;
        for(int i = MAX_LEVEL - 1; i >= 0; i--) {
            while(cur.next[i] != null && cur.next[i].val < target) {
                cur = cur.next[i];
            }
        }
        cur = cur.next[0];
        if(cur == null) {
            return false;
        }
        return cur.val == target;
    }

    public void add(int num) {
        Entry[] prev = new Entry[MAX_LEVEL];
        Entry cur = head;
        for(int i = MAX_LEVEL - 1; i >= 0; i--) {
            while(cur.next[i] != null && cur.next[i].val < num) {
                cur = cur.next[i];
            }
            prev[i] = cur;
        }
        if(cur.next[0] != null && cur.next[0].val == num) {
            cur.next[0].count += 1;
            return;
        }

        Entry newEntry = newEntry(num);
        int newLevel = newEntry.level;
        for(int i = newLevel - 1; i >= 0; i--) {
            newEntry.next[i] = prev[i].next[i];
            prev[i].next[i] = newEntry;
        }
    }

    public boolean erase(int num) {
        Entry[] prev = new Entry[MAX_LEVEL];
        Entry cur = head;
        for(int i = MAX_LEVEL - 1; i >= 0; i--) {
            while(cur.next[i] != null && cur.next[i].val < num) {
                cur = cur.next[i];
            }
            prev[i] = cur;
        }
        cur = cur.next[0];
        if(cur == null || cur.val != num) {
            return false;
        }
        if(cur.count > 1) {
            cur.count -= 1;
        } else {
            int level = cur.level;
            for(int i = level - 1; i >= 0; i--) {
                prev[i].next[i] = cur.next[i];
            }
        }
        return true;
    }

    private Entry newEntry(int num) {
        int level = randomLevel();
        return new Entry(num, level);
    }

    private int randomLevel() {
        int level = 1;
        while(random.nextInt(100) < 25) {
            level++;
            if(level == MAX_LEVEL) {
                break;
            }
        }
        return level;
    }
}
```