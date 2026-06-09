// ### 学习思路

// - 类似 [LRU](https://leetcode-cn.com/problems/lru-cache/) 的题
// - 考察点核心：设计数据结构、链表操作、细心(肉眼debug)
// - 建议
//   - 先试着完全自己设计数据结构，画画图，至少有个自己的思路
//   - 实在想不出来，或想出来了但总是不通过
//     - 或心态崩溃老子不干了但好像还可以再抢救一下
//     - 可以开始看别人的思路了
//   - 笔者的学习方法：**一点一点学，一点一点自己写**
//     - `Node` 节点怎么定义，增加 `int freq` 频率属性是否更好
//     - `DoubleLinkedList` 双向链表中定义了哪些 `public` 方法，是否加上哨兵节点(`head`, `tail`)更好实现
//     - `Cache` 主类有哪些 `private` 属性，封装了哪些 `private` 方法
//     - 至此，可以说已经把别人的 **思路关键点** 放到自己的脑袋里了
//       - 毕竟最希望在题解中找到的，是「我到底差了 **哪一点** 就全通了」
// - 参考 [Sweetiee 🍬](https://leetcode-cn.com/problems/lfu-cache/solution/java-13ms-shuang-100-shuang-xiang-lian-biao-duo-ji/)
// - 参考 [liweiwei1419](https://leetcode-cn.com/problems/lfu-cache/solution/ha-xi-biao-shuang-xiang-lian-biao-java-by-liweiwei/)

// ### 构建节点

// - 除了 `freq` ，其他属性应该是大多能想到的（建议先做 LRU 的题）
// - `freq` 没有会怎样，是否有其他方式解决，都不如自己试试更深刻

// ```java
public class LFUCacheNode {
    int key, value, freq; // freq 频率
    LFUCacheNode prev, next;
    public LFUCacheNode(int key, int value) {
        this.key = key;
        this.value = value;
        this.freq = 1;
        this.prev = this.next = null;
    }
}
// ```

// ### 构建双向链表

// - 需要支持的操作有：
//   - 从已有频率的链表中删除 `remove(node)`
//   - 加入到新频率的链表中 `addFirst(node)`
//   - 挤出 **最低频率** 链表中的最后一位 `removeLast()`
// - 增加哨兵节点
// - 是否需要 `size`、`capacity` ？可以先加上，不用再删嘛~

// ```java
public class LFUCacheDbLinkedList {
    private LFUCacheNode head, tail; // 哨兵节点，有助于增删操作的实现

    public LFUCacheDbLinkedList() {
        head = new LFUCacheNode(-1, -1);
        tail = new LFUCacheNode(-2, -2);
        head.next = tail;
        tail.prev = head;
    }

    // addFirst
    public void add(LFUCacheNode target) {
        // 先写好增加后的样子
        // head -> (target) -> node

        // 老老实实先拿出 node
        LFUCacheNode node = head.next; 
        target.prev = head;
        target.next = node;

        head.next = target;
        node.prev = target;
    }

    // 若不确定是否返回值，就都先返着，不需要的话再改回 void 嘛~
    public LFUCacheNode removeLast() {
        return remove(tail.prev);
    }

    // 删除指定某一个节点
    public LFUCacheNode remove(LFUCacheNode target) {
        if (isEmpty()) return null;

        // 先写好删除前的样子
        // node1 - target - node2
        LFUCacheNode node1 = target.prev, node2 = target.next;

        node1.next = node2;
        node2.prev = node1;

        target.prev = target.next = null;
        return target;
    }

    // 怎么需要有方法？不了解的统统删掉，写着写着就悟出来了
    public boolean isEmpty() {
        return head.next == tail;
    }
}
// ```

// ### 完善主类

// - 肯定需要一个 `map` 存储数据
// - 根据大佬们的思路，每个频率都有一个双向链表，故 `freqMap`
// - `size` , `capacity` 先写着就当全局变量
// - `minF` 当前最低频率是什么东东？即上文「构建双向链表」步骤中提到的「挤出 **最低频率** 链表中最后一位」，为了快速定位而存在

// ```java
public class LFUCache {
    private Map<Integer, LFUCacheNode> map;
    private Map<Integer, LFUCacheDbLinkedList> freqMap;
    private int size, capacity, minF; // minF 当前最低频率

    public LFUCache(int capacity) {
        map = new HashMap<>();
        freqMap = new HashMap<>();
        freqMap.put(1, new LFUCacheDbLinkedList()); // 默认开一个频率为 1 的链表
        this.capacity = capacity;
        size = 0;
        minF = 1; // 当前最低频率 1
    }

    public int get(int key) {
        int res = -1;
        if (map.containsKey(key)) {
            LFUCacheNode node = map.get(key);
            res = node.value;
            useOnce(node); // 封装更新节点频率的所有操作
        }
        return res;
    }

    public void put(int key, int value) {
        if (map.containsKey(key)) {
            // exist
            LFUCacheNode node = map.get(key);
            node.value = value; // 别忘了更新值
            useOnce(node); // 封装更新节点频率的所有操作
            return;
        }

        // not exist
        // 新建节点
        LFUCacheNode newOne = new LFUCacheNode(key, value);
        map.put(key, newOne);
        // 加入频率 1 的链表
        LFUCacheDbLinkedList list1 = freqMap.get(1);
        list1.add(newOne);
        if (size == capacity) {
            // 挤出 当前最低频率 里的最后一个
            LFUCacheDbLinkedList listMin = freqMap.get(minF);
            LFUCacheNode removed = listMin.removeLast();
            // 【易漏】移除数据映射
            map.remove(removed.key);
        } else size++;

        // 【易漏】更新当前最低频率
        minF = 1;
    }

    // 封装更新节点频率的所有操作
    private void useOnce(LFUCacheNode node) {
        // 原来频率的链表
        LFUCacheDbLinkedList oriList = freqMap.get(node.freq);
        oriList.remove(node);

        // 新的频率
        int newF = node.freq + 1;
        // 【易错】若旧链表里已经清空，则更新当前最低频率
        if (minF == node.freq && oriList.isEmpty()) minF = newF;

        // 新频率的链表增加节点
        if (!freqMap.containsKey(newF)) freqMap.put(newF, new LFUCacheDbLinkedList());
        LFUCacheDbLinkedList newList = freqMap.get(newF);
        newList.add(node);

        // 更新节点频率
        node.freq = newF;
    }
}
// ```