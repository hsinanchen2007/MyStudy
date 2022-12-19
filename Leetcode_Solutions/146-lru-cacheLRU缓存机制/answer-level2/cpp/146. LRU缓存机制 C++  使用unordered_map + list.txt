内部数据结构：
1、unordered_map  哈希表
密钥 (key) 作为哈希表的key， 链表节点迭代器和密钥的值共同作为哈希表的value

2、链表 
链表中必须要存密钥，缓存淘汰时需要根据最近最少访问的节点找到密钥

密钥的值可以选择存在哈希表里，也可以选择存在链表里，这里我选择存在哈希表中


put操作：O(1)时间复杂度
1、先判断key是否存在，如果key存在，直接修改值，注意：需要将该节点移动到链表头（这也是一种访问）  移动链表某个节点到链表某个位置，可以使用list.splice()
2、如果key不存在，则需要判断缓存是否满
如果缓存满了，则需要进行缓存淘汰，找到最近最少访问的节点对应的key，并在哈希表中删除该键值对，链表中删除该最近最少访问的节点，再在链表头插入节点，并在哈希表插入键值对
如果缓存没满，则直接在链表头插入节点，并在哈希表插入键值对

get操作：O(1)时间复杂度
1、如果key存在，则要将该key设置为最近访问的节点
需要将该节点移动到链表头（O(1)时间复杂度 则不能从头遍历链表，故需要在hash表中存储链表该节点的迭代器）  
访问过后的节点会重新调度到链表的头部,所以没有被访问的节点就会逐渐的移动的链表的尾部，最近最少访问的节点会自动排在链表尾

2、key不存在，则返回-1


    struct Value 
    {
        int value;
        list<int>::iterator iter;

        Value(int v, list<int>::iterator it): value(v), iter(it) {}
    };

    class LRUCache {
    public:
        LRUCache(int capacity) {
            m_capacity = capacity;
            m_hash.reserve(capacity * 2); //减少rehash
        }

        int get(int key) {
            std::unordered_map<int, Value>::iterator iter = m_hash.find(key);
            if (iter != m_hash.end()) //找到了
            {
                //将该链表节点移动到链表头节点
                m_list.splice(m_list.begin(), m_list, iter->second.iter);

                return iter->second.value;
            }
            else
            {
                return -1;
            }
        }

        void put(int key, int value) {

            std::unordered_map<int, Value>::iterator iter = m_hash.find(key);
            if (iter != m_hash.end()) //找到了
            {
                //将该链表节点移动到链表头节点
                m_list.splice(m_list.begin(), m_list, iter->second.iter);

                iter->second.value = value;
            }
            else //没找到
            {
                if (m_hash.size() == m_capacity) //缓存满了
                {
                    //缓存淘汰           
                    m_hash.erase(m_list.back()); //hash删除该尾结点的键值对
                    m_list.pop_back(); //删除尾结点
                }
                m_list.push_front(key); //在链表头插入新节点
                Value v(value, m_list.begin());
                m_hash.insert(pair<int, Value>(key, v)); //hash插入
            }
        }


    private:
        unordered_map<int, Value> m_hash;
        list<int> m_list; //存key
        int m_capacity;
    };