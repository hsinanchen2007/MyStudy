这道题是典型的数据结构题，需要对常见的数据结构复杂度有了解。

首先对于任意key的存取不能用数组，必须把key和value一起存起来。
而为了达到O(1)的存取，基于平衡二叉树 O(logN)的map是不可能的了，只有基于hash O(1)的unordered_map是可以的。
所以用一个unordered_map存储key-value对，这样可以解决正常的存储访问和更新。

但是这个没解决达到容量后删除的问题，每次满了需要删除访问次数最少且最早使用的。为了在O(1)时间内完成，我们需要根据访问次数和最近访问时间排序。
访问次数肯定是记录下来的，每次访问加1。
最近访问时间一般有两种解决方式，一种是用一个全局变量表示时间戳不断递增，操作的时候赋值，另一种就是隐性时间，用队列插入先后顺序来表示。

这两个数据，平时一般对于这种排序的要求都是用平衡二叉树来处理，但是也是O(logN)，这里为了达到O(1)，必须要分别处理。所以用了unordered_map和队列的组合。
先找次数最少，为了O(1)，所以还是只能用unordered_map把访问次数映射到一个队列，这个队列里面的元素都是访问次数相同，每次插入从队尾插入，需要删除的时候把队头删除就行，因为队头是最先加入的。因为unordered_map是无序的，所以这个最小的访问次数需要我们记录，并且每次O(1)更新。具体实现后面再说。
但是还剩一个问题，有时候get访问了队列中间的元素，访问次数需要加1然后插入到次数加1对应队列的队尾，这时候用queue不能对中间元素进行操作，所以要用到双指针链表，能O(1)复杂度在中间插入删除。
到这里我们就介绍了核心的数据结构：首先创建节点存储key,value,frequency这三个信息，用一个unordered_map key2val映射key到对应的节点（其实是在链表中的位置，这样方便后续操作），第二个unordered_map freq2list映射访问次数到等于这个访问次数的节点列表。

get函数涉及的操作就是访问key2val中对应key是否存在，如果不存在返回-1，如果存在返回value，并且将这个节点挪到freq2list中访问次数多1对应的列表。
put函数新增元素，把新创建的节点从头塞入freq2list[1]，这个列表存储只访问了1次的节点，然后如果容量满了需要删除，就把freq2list中最小的freq对应的列表尾部节点删除。
具体有几个细节需要注意：
1. 删除要在插入之前进行，避免把新加入的节点删了。
2. 为了保证整个操作O(1)，需要存储最小的freq的值min_freq，每次新插入元素后min_freq置为1
3. 每次把节点从一个列表删除后，如果整个列表为空，就要把这个列表整个删除。删完对应列表后min_freq加1即可，因为删空这个列表的两种情况，第一种是新加入元素，那么最后会置为1，加1也不影响，第二种是里面的元素被多访问了一次，所以加1就刚好追上了这个变化后的元素。

具体代码如下：
```
struct Node {
    int key, value, frequency;
    Node(int k,int v,int f) {
        key = k;
        value = v;
        frequency = f;
    }
};

class LFUCache {
    int min_freq, capacity;
    unordered_map<int, list<Node>::iterator> key2val;
    unordered_map<int, list<Node>> freq2list;
    
public:
    LFUCache(int cap) {
        min_freq = 1;
        capacity = cap;
    }
    
    int get(int key) {
        auto iter = key2val.find(key);
        if (iter == key2val.end()) {
            return -1;
        }
        auto node = iter -> second;
        int val = node -> value;
        int freq = node -> frequency;
        freq2list[freq].erase(node);
        auto new_node = Node(key, val, freq + 1);
        freq2list[freq + 1].push_front(new_node);
        key2val[key] = freq2list[freq+1].begin();
        
        if (freq2list[freq].size() == 0) {
            freq2list.erase(freq);
            if (min_freq == freq) {
                min_freq++;
            }
        }
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) 
            return;
        auto iter = key2val.find(key);
        if (iter == key2val.end()) {
            if (key2val.size() >= capacity) {
                auto iter_del = freq2list[min_freq].back();
                key2val.erase(iter_del.key);
                freq2list[min_freq].pop_back();
                if (freq2list[min_freq].size() == 0) {
                    freq2list.erase(min_freq);
                }
            }
            freq2list[1].push_front(Node(key, value, 1));
            key2val[key] = freq2list[1].begin();
            min_freq = 1;
            return;
        }
        auto node = iter -> second;
        int freq = node -> frequency;
        freq2list[freq].erase(node);
        if (freq2list[freq].size() == 0) {
            freq2list.erase(freq);
            if (min_freq == freq) {
                min_freq++;
            }
        }
        auto new_node = Node(key, value, freq + 1);
        freq2list[freq + 1].push_front(new_node);
        key2val[key] = freq2list[freq + 1].begin();
    }
};
```