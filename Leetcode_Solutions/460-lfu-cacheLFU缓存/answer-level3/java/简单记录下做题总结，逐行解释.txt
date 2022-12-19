### 厘清题目
 
  $LFU cache$，就是 $Least\  Frequently\ Used$，最近最少未使用,假设容量是 $2$，我们现在有两个 $key$， $k1$ 和 $k2$，$k1$ 访问过两次，$k2$ 访问过一次
  - 此时要添加一个 $key$，那么就要把访问次数少的那个给删除，也就是把 $k2$ 删除
  - 如果两个 $key$，$k1$ 和 $k2$ 的访问频率 $freq$ 都是两次，那我们就要把最近没访问的那个给删除
 
  所以对于每一个 $key$，要记录它被访问的次数，那么不仅要记录次数，还要记录相同访问次数下，每个节点的访问的先后顺序，因为如果频率都一样，如果要删除，我们要把最近没访问的删除
 
  时间限制 $O(1)$，如果没这个就可以用 $TreeMap$ 、$heap$ 这玩意自动排序，但时间复杂度是 $log(capacity)$
 
### 数据结构设计

  **首先**：$Map<Integer, DoublyLinkedList> freqMap$ 放的是每个 $freq$ 下对应的一条双向链表，那么对于这个双向列表，我们要定义一个 $head$ 与 $tail$ ，以及记录它的 $len$ 是多少（这个删除时候用），双向链表需要提供这些操作：
- $add()$，添加到头部，表示该 $freq$ 下的最近访问的，最近访问过的我们都放到头部
- $removeTail()$，删除的是 $tail$ 的前一个，最近没用的那个给删了
- $remove()$，删除指定节点，因为我们 $get()$ 的时候 $freq$ 要发生变化，要从原来的双向链表中删除
 
**其次**：再用一个 $Map<Integer,ListNode> map$ 存放当前的 $key$ 及其对应的 $node$
 
### 细化操作
**get() 操作**
1. 如果不存在，直接return -1
2. 如果存在，对应节点的 $freq$ 自增，从原来频率中移除节点，再放到其对应频率的双向链表中去（比如从原来 $freq$ 为 $2$ 的双向链表中删除，放在 $freq$ 为 $3$ 的双向链表中去，并且是放到头的，表示最近用过），当然我们要从 $map$ 中删除这个节点，
       

**put() 操作**
1. 如果 $key$ 存在，就是更新下频率，更新 $value$，再调用 $get()$函数即可
2. 如果 $key$ 不存在，首先 $new$ 一个节点出来，放到 $map$ 中，查看是否需要删除节点即可，这里的删除需要考虑这两种情况
    - 如果 $freq$ 为 $1$ 的双向链表的长度大于 $1$，说明有东西可以删，只需删除该双向链表的最后一个（$tail$ 的前一个）即可
    - 如果 $freq$ 为 $1$ 的双向链表的长度等于 $1$，这个里面的节点就是我们刚才新加进来的，需要从其他双向链表里面删除最后一个，所以我们遍历其余的双向链表，这边我们需要记录个最大频率 $maxFreq$，从小到大找，因为要符合$LFU$。


### 代码

```java
    class LFUCache {
        Map<Integer, ListNode> map;
        Map<Integer, DoublyLinkedList> freqMap;
        int capacity;
        int maxFreq;

        public LFUCache(int capacity) {
            map = new HashMap<>();
            freqMap = new HashMap<>();
            this.capacity = capacity;
            maxFreq = 0;
        }

        public int get(int key) {
            if (!map.containsKey(key)) {
                return -1;
            }
            // 如果有这个 key，首先拿到频率
            ListNode node = map.get(key);
            int freq = node.freq;
            // 根据这个频率拿到其对应的双向链表
            DoublyLinkedList dll1 = freqMap.get(freq);
            // 从这个双向链表中删除该节点,然后在map中也需要删除
            ListNode rmv = dll1.remove(node);
            map.remove(rmv.key);
            // 把访问频率+1,拿到对应的双向链表
            DoublyLinkedList dll2 = freqMap.getOrDefault(freq + 1, new DoublyLinkedList());
            node.freq = freq + 1;
            // 更新下maxFreq
            maxFreq = Math.max(maxFreq, freq + 1);
            dll2.add(node);
            // 更新两个map，对于map可以直接覆盖，对于freqMap 尤其要注意 freqMap 要更新两个双向链表
            map.put(key, node);
            freqMap.put(freq, dll1);
            freqMap.put(freq + 1, dll2);
            return node.val;
        }

        public void put(int key, int value) {
            // 有个恶心的uc是 capacity 为 0 的情况，那就直接返回了
            if (capacity == 0) return;
            // 如果 map 中有这个key，只需要更细这个节点的val即可，再调用 get()
            if (map.containsKey(key)) {
                ListNode node = map.get(key);
                node.val = value;
                get(key);
                return;
            }
            // 如果没有这个 key，新建一个 Node，它对应的频率为 1
            ListNode node = new ListNode(key, value);
            // 拿到频率为 1 的双向链表，并调用 add 添加到头部
            DoublyLinkedList dll = freqMap.getOrDefault(1, new DoublyLinkedList());
            dll.add(node);
            map.put(key, node);
            // 如果需要删除
            if (map.size() > capacity) {
                // 如果 freq 为 1 的双向链表的长度大于 1，说明有东西可以删，否则只能从其他双向链表中删除
                if (dll.len > 1) {
                    ListNode rmv = dll.removeTail();
                    map.remove(rmv.key);
                } else {
                    // 否则就要开始找
                    for (int i = 2; i <= maxFreq; i++) {
                        if (freqMap.containsKey(i) && freqMap.get(i).len > 0) {
                            ListNode rmv = freqMap.get(i).removeTail();
                            map.remove(rmv.key);
                            break;
                        }
                    }
                }
            }
            freqMap.put(1, dll);
        }

    }

    class DoublyLinkedList{
        int len;
        ListNode head;
        ListNode tail;

        public DoublyLinkedList() {
            head = new ListNode(0, 0);
            tail = new ListNode(0, 0);
            head.next = tail;
            tail.next = head;
            len = 0;
        }

        // 添加到头部
        public void add(ListNode node) {
            ListNode temp = head.next;
            head.next = node;
            node.pre = head;
            node.next = temp;
            temp.pre = node;
            len++;
        }

        // 删除该条双向链表中指定的节点，返回删除的节点
        public ListNode remove(ListNode node) {
            ListNode pre = node.pre;
            ListNode next = node.next;
            pre.next = next;
            next.pre = pre;
            len--;
            return node;
        }

        // 删除该条双向链表的最后一个节点（tail的前一个），返回删除的节点
        public ListNode removeTail() {
            ListNode rmv = tail.pre;
            remove(rmv);
            return rmv;
        }
    }

    class ListNode{
        int key;
        int val;
        // 访问次数
        int freq;
        ListNode pre;
        ListNode next;

        public ListNode(int key, int val) {
            this.key = key;
            this.val = val;
            freq = 1;
        }
    }
```