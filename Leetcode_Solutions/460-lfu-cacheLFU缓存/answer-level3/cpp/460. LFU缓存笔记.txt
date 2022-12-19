### 解题思路
1. 在set中每个元素的值都唯一，而且系统能根据元素的值自动进行排序，内部采用的就是一种非常高效的平衡检索二叉树：红黑树
2. 在c++中struct与class的语法除了默认的访问权限，其他没有区别
3. struct的构造函数Node(int _cnt, int _time, int _key, int _value) : cnt(_cnt), time(_time), key(_key), value(_value) {}
4. C++ lhs的全称是 left hand side , rhs的全称是 right hand side
5. [const 修饰函数参数，返回值，函数体](https://blog.csdn.net/lz20120808/article/details/46662569)
6. const 引用传递，用于确保传递进来的引用不被修改；const 成员函数(const的作用：说明其不会修改数据成员)
7. [C++进阶-STL容器，你看我就够了](https://www.jianshu.com/p/497843e403b4)，1. 容器缓存了节点，节点类要确保支持拷贝(否则出现浅拷贝问题，导致崩溃) 2. 容器中的一般节点类，需要提供拷贝构造函数，并重载等号操作符(用来赋值) 3. 容器在插入元素时，会自动进行元素的拷贝。
8. C++中类的拷贝有两种：深拷贝，浅拷贝：当出现类的等号赋值时，即会调用拷贝函数。在未定义显示拷贝构造函数的情况下，系统会调用默认的拷贝函数——即浅拷贝，它能够完成成员的一一复制。当数据成员中没有指针时，浅拷贝是可行的；但当数据成员中有指针时，如果采用简单的浅拷贝，则两类中的两个指针将指向同一个地址，当对象快结束时，会调用两次析构函数，而导致指针悬挂现象，所以，此时，必须采用深拷贝。
9. [C++11 新特性： unordered_map 与 map 的对比](https://www.cnblogs.com/NeilZhang/p/5724996.html)，unordered_map（哈希表）需要定义hash_value函数并且重载operator==，无序；使用时map（二叉搜索树）的key需要定义operator<，有序。
10. [pair和make_pair用法](https://blog.csdn.net/wangkai_123456/article/details/50352859)


### 代码

```cpp
struct Node {
    int cnt, time, key, value;

    Node(int _cnt, int _time, int _key, int _value) : cnt(_cnt), time(_time), key(_key), value(_value) {}

    bool operator < (const Node& rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};

class LFUCache {
public:
    int _capacity, time;
    set<Node> S;
    unordered_map<int, Node> key_table;

    LFUCache(int capacity) {
        _capacity = capacity;
        time = 0;
        S.clear();
        key_table.clear();
    }
    
    int get(int key) {
        if (_capacity == 0) return -1;
        auto iter = key_table.find(key);
        // 如果不存在，则返回-1
        if (iter == key_table.end()) return -1;
        // 存在的话，更新S中的cnt
        Node cache = iter->second;
        S.erase(cache);
        cache.cnt++;
        cache.time = ++time;
        S.insert(cache);
        iter->second = cache;

        return cache.value;
    }
    
    void put(int key, int value) {
        if (_capacity == 0) return;
        // 判断键是否存在
        auto iter = key_table.find(key);
        if (iter == key_table.end()) {
            // 不存在,则先判断是否满容量了
            if (key_table.size() == _capacity) {
                // 容量满了,则先删除一个键，删除的键为S的begin指针指向的键
                int remove_key = S.begin()->key;
                S.erase(S.begin());
                key_table.erase(remove_key);
            }
            // 插入一个键
            Node cache(1, ++time, key, value);
            // 插入S和key_table
            S.insert(cache);
            key_table.insert(make_pair(key, cache));
        } else {
            // 存在，与get函数类似
            Node cache = iter->second;
            S.erase(cache);
            cache.cnt++;
            cache.time = ++time;
            cache.value = value;
            S.insert(cache);
            iter->second = cache;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```