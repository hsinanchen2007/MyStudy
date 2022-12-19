LFU数据结构设计：
1. 双向链表`HeadEntry`，存：
    - `key`：访问次数
    - `value`：`HeadEntry`下挂的链表长度
    - `head`：`HeadEntry`下挂的链表头
    - `prev`, `next`：指针
   `HeadEntry`会用散列表`headers`存储起来（以`key`作为键）
2. 每个`HeadEntry`挂一个键值双向链表`Entry`，且首尾相连
    - `key`：对应的键
    - `value`：对应的值
    -  `prev`, `next`：指针
    `Entry`也会用散列表`storage`存储起来（以`key`作为键）
3. `counts`散列表：存储某个`key`的访问次数

`get`时：根据`counts`表和`headers`表获得表头和表项，将表项移除原链表，并放到下一个链表头（若没有则需创建），原表空（即`headEntry.value == 0`）则需删除对应表头，然后更新`counts`, `storage`, `headers`等字段

`put`时：
- 若键值存在，则直接更新并执行一次`get`
- 若不存在，则先找是否需要删除，删除项只要移除第一个链表的尾部即可（`headers[0].next.head.prev`），表空则对应表头要删除，然后将新项插入第一个链表里（但要保证第一个链表头的`key`是1，若没有则需新创建），然后更新`counts`, `storage`, `headers`等字段

---
> 而LRU只需维护一个双向链表栈+散列表就可以了
---

具体的参考：http://dhruvbird.com/lfu.pdf，也有人贴出图了。

代码如下（随便写的，很丑）：
```java
class LFUCache {

    // count linked list: 0 <-> 1 <-> ...
    // value list               |
    //                          v
    //                          x
    // loop double-linked list

    private int capacity;

    private Map<Integer, Entry> storage = new HashMap<>();

    private Map<Integer, Integer> counts = new HashMap<>();

    private Map<Integer, HeaderEntry> headers = new HashMap<>();

    private HeaderEntry countHeader = new HeaderEntry(0, 0);

    static class HeaderEntry {
        int key;
        int value;
        Entry head;
        HeaderEntry prev;
        HeaderEntry next;
        HeaderEntry(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    static class Entry {
        int key;
        int value;
        Entry prev;
        Entry next;

        Entry(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    public LFUCache(int capacity) {
        this.capacity = capacity;
    }

    public int get(int key) {
        if(capacity == 0) {
            return -1;
        }
        Entry entry = storage.get(key);
        if(entry == null) {
            return -1;
        }

        int originCount = counts.get(key);
        counts.put(key, originCount + 1);
        HeaderEntry header = headers.get(originCount);
        if(header.head == entry) {
            if(header.value == 1) {
                header.head = null;
            } else {
                header.head = entry.next;
            }
        }
        header.value -= 1;
        entry.prev.next = entry.next;
        entry.next.prev = entry.prev;
        entry.prev = entry.next = entry;

        if(header.next == null || header.next.key != originCount + 1) {
            HeaderEntry newHeadEntry = new HeaderEntry(originCount + 1, 1);
            headers.put(originCount + 1, newHeadEntry);
            newHeadEntry.head = entry;
            newHeadEntry.prev = header;
            if(header.next != null) {
                newHeadEntry.next = header.next;
                header.next.prev = newHeadEntry;
            }
            header.next = newHeadEntry;
        } else {
            HeaderEntry newHeadEntry = header.next;
            newHeadEntry.value += 1;
            Entry next = newHeadEntry.head;
            Entry prev = next.prev;
            entry.next = next;
            entry.prev = prev;
            next.prev = entry;
            prev.next = entry;
            newHeadEntry.head = entry;
        }
        if(header.value == 0) {
            headers.remove(header.key);
            header.prev.next = header.next;
            if(header.next != null) {
                header.next.prev = header.prev;
            }
        }
        return entry.value;
    }

    public void put(int key, int value) {
        if(capacity == 0) {
            return;
        }
        if(storage.containsKey(key)) {
            storage.get(key).value = value;
            get(key);
        } else {
            Entry entry = new Entry(key, value);
            entry.prev = entry.next = entry;
            storage.put(key, entry);
            counts.put(key, 1);
            if (storage.size() > capacity) {
                HeaderEntry header = countHeader.next;
                header.value -= 1;
                Entry evictEntry = header.head.prev;
                storage.remove(evictEntry.key);
                counts.remove(evictEntry.key);
                Entry prev = evictEntry.prev;
                Entry next = evictEntry.next;
                if(header.head == evictEntry) {
                    header.head = null;
                } else {
                    prev.next = next;
                    next.prev = prev;
                }
                if(header.value == 0) {
                    headers.remove(header.key);
                    header.prev.next = header.next;
                    if(header.next != null) {
                        header.next.prev = header.prev;
                    }
                }
            }

            if(countHeader.next == null || countHeader.next.key != 1) {
                HeaderEntry newHeadEntry = new HeaderEntry(1, 1);
                headers.put(1, newHeadEntry);
                newHeadEntry.head = entry;
                newHeadEntry.prev = countHeader;
                if(countHeader.next != null) {
                    newHeadEntry.next = countHeader.next;
                    countHeader.next.prev = newHeadEntry;
                }
                countHeader.next = newHeadEntry;
            } else {
                HeaderEntry newHeadEntry = countHeader.next;
                newHeadEntry.value += 1;
                Entry next = newHeadEntry.head;
                Entry prev = next.prev;
                entry.next = next;
                entry.prev = prev;
                next.prev = entry;
                prev.next = entry;
                newHeadEntry.head = entry;
            }
        }
    }
}
```
