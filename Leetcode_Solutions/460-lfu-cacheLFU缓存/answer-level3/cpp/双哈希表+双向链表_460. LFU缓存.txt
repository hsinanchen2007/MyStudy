### 解题思路 双哈希表+双向链表 O(1) O(n)
/*
 * 双哈希表 + 双向链表 O(1) O(n)
 *
 * 定义两个哈希表，第一个freq_table以频率freq为索引，每个索引存放一个双向链表，
 * 链表中存放所有使用频率为freq的缓存，缓存存放三个信息——键key，值value，使用频率freq。
 * 第二个key_table以键值key为索引，每个索引存放对应缓存在freq_table中链表里的内存地址，
 * 这样能够利用两个哈希表来使得get和put操作时间复杂度为O(1)。同时需要记录当前缓存最少使用的频率minFreq。
 *
 * get(key)操作，能通过索引key在key_table中找到缓存在freq_table中的链表的内存地址，
 * 如果不存在直接返回-1，否则能获得对应缓存信息，获得缓存的键值和使用频率，直接返回key对应的值即可。
 *
 * get操作后，缓存使用频率加1，需要更新缓存在哈希表freq_table中的位置。已知该缓存的键key，值value,
 * 使用频率freq，则该缓存应放到freq_table中freq+1索引下的链表中。所以在当前链表中O(1)删除该缓存对应节点，
 * 根据情况更新minFreq值，然后将其O(1)插入freq+1索引下的链表头完成更新。
 *
 * put(key, value)操作，先通过索引key在key_table中查看是否有对应的缓存，如果有则将当前缓存的值更新，
 * 再进行get(key)相同的操作。如果没有，相当于加入新的缓存，如果缓存达到容量，
 * 需要先删除最近最少使用的缓存，在进行插入操作。先考虑插入，由于是新插入的，所以缓存的使用频率一定是1，
 * 所以将缓存的信息插入到freq_table中1索引下的列表头即可，同时更新key_table[key]的信息和minFreq=1。
 * 因为实时维护minFreq，知道freq_table中目前最少使用频率的索引，同时保证了链表中从头到尾插入时间有序，
 * 所以freq_table[minFreq]的链表中链表尾节点即为使用频率最小且插入时间最早的节点，删除它同时更新minFreq。
 * */
### 代码

```cpp
private:
    // 双向链表节点
    struct DLinkNode {
        int key, val, freq;

        // 节点构造函数
        DLinkNode(int key, int val, int freq) : key(key), val(val), freq(freq) {}
    };

    // 最小频率，表示最近最少使用的链表
    int minFreq;
    // 缓存的容量
    int capacity;

    // 哈希表：存储(key, 链表节点在链表中的位置)
    std::unordered_map<int, std::list<DLinkNode>::iterator> key_table;
    // 哈希表：存储(key, val, freq)
    std::unordered_map<int, std::list<DLinkNode>> freq_table;

public:

LFUCache(int capacity) {
    this->minFreq = 0;
    this->capacity = capacity;
    key_table.clear();
    freq_table.clear();
}

int get(int key) {
    if (capacity == 0) {
        return -1;
    }

    // key_table中是否存在该key
    auto iter = key_table.find(key);
    // 如果不存在，返回-1
    if (iter == key_table.end()) {
        return -1;
    }

    // 如果存在该key，
    // node为iter指向的节点，即key对应的节点
    auto node = iter->second;
    // 该节点的val和freq值
    int val = node->val;
    int freq = node->freq;
    // 因为get(key)属于操作，所以该节点频率加1
    // 将该节点从哈希表原链表freq_table[freq]中删除
    freq_table[freq].erase(node);

    // 如果删除该节点后，freq_table[freq]链表为空
    if (freq_table[freq].empty()) {
        // 则从freq_table中删除该频率freq对应的双向链表
        freq_table.erase(freq);
        // 如果最小频率minFreq等于freq，因为freq使用后频率加1，
        // 所以minFreq最小频率也要更新为加1
        if (minFreq == freq) {
            minFreq += 1;
        }
    }

    // 头部表示最近使用，尾部表示最近最久未使用
    // 将该节点添加到链表freq_table[freq+1]的头部，并将该节点的频率更新
    freq_table[freq + 1].push_front(DLinkNode(key, val, freq + 1));
    // 同时更新key_table中key所对应节点在新链表freq_table[freq+1]的头部位置
    key_table[key] = freq_table[freq + 1].begin();

    return val;
}

void put(int key, int value) {
    if (capacity == 0) {
        return;
    }

    // key_table中是否存在该key
    auto iter = key_table.find(key);

    // 如果不存在该key对应的节点，就将该节点插入到频率对应的双向链表头部
    if (iter == key_table.end()) {
        // 首先判断当前缓存大小是否达到容量
        if (key_table.size() == capacity) {
            // 如果当前缓存大小已经达到容量，则需要先删除最近最少使用的节点
            // 在哈希表中找到最近最少使用的双向链表freq_table[minFreq]
            // 因为最近加入的节点都在头部，所以最近最少使用的是尾部节点
            auto it = freq_table[minFreq].back();
            // 删除key_table中最近最少使用的节点
            key_table.erase(it.key);
            // 从双向链表freq_table[minFreq]中删除尾节点
            freq_table[minFreq].pop_back();

            // 判断此时频率最小的双向链表是否为空
            if (freq_table[minFreq].empty()) {
                // 如果为空则删除频率最小的双向链表
                freq_table.erase(minFreq);
            }
        }

        // 因为新插入节点的频率为1，所有将其插入到freq_table[1]链表中
        freq_table[1].push_front(DLinkNode(key, value, 1));
        // 同时更新key_table中key所对应的节点在频率链表中相应的位置
        key_table[key] = freq_table[1].begin();
        // 更新最小频率为1
        minFreq = 1;
    } else {
        // 如果存在该key，
        // node为iter指向的节点，即key对应的节点
        auto node = iter->second;
        // 获得该节点的freq值
        int freq = node->freq;
        // 因为该节点因使用后频率加1，所以从原频率链表中删除该节点
        freq_table[freq].erase(node);

        // 判断节点原频率链表是否为空
        if (freq_table[freq].empty()) {
            // 如果为空，则从哈希表中删除该频率链表
            freq_table.erase(freq);
            // 如果最小频率等于节点原频率，则将最小频率更新加1
            if (minFreq == freq) {
                minFreq += 1;
            }
        }

        // 将该节点频率加1后添加到频率加1的双向链表的头部
        freq_table[freq + 1].push_front(DLinkNode(key, value, freq + 1));
        // 同时更新key所对应的节点在相应频率链表中的头部位置
        key_table[key] = freq_table[freq + 1].begin();
    }
}

```