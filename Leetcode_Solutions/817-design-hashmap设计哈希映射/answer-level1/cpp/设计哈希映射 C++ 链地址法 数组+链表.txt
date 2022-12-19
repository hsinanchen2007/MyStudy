### 解题思路
此处撰写解题思路

### 代码

```cpp
class Node {
public:
    int key;
    int value;
    Node * next;
public:
    Node(int key_, int value_):key(key_),value(value_),next(nullptr){};
    ~Node();
};

const int len = 100;

class MyHashMap {
public:
    // 使用数组分配一定个数的链表节点类型的指针，数组+链表解决哈希冲突
    vector<Node*> arr;
public:
    /** Initialize your data structure here. */
    // 构造函数，提前用数组分配好内存，分配多了势必造成浪费，分配少了极易出现哈希冲突
    // 所以采用链地址法，着重解决哈希冲突，不用分配过多内存。
    MyHashMap():arr(vector<Node*>(len, nullptr)) {
        for (int i = 0; i < len; i++)
            arr[i] = new Node(-1,0);
    }
    
    /** value will always be non-negative. */
    // 向哈希映射中插入键值对。如果键对应的值已经存在，更新这个值。
    void put(int key, int value) {
        // 哈希映射，计算该键在数组中的索引
        int index = key % len;
        // 获取数组内容
        Node *tmp = arr[index];
        while (tmp) {
            // 该key没有保存数据，保存该键值对
            if (tmp->key == -1) {
                tmp->key = key;
                tmp->value = value;
                return ;
            }
            // 该key已经存在，更新value
            if (tmp->key == key) {
                tmp->value = value;
                return ;
            }
            // 该key是哈希冲突产生的key，沿着链表搜索，插入到表为
            if (tmp->next == nullptr) {
                tmp->next = new Node(key, value);
                return ;
            }
            tmp = tmp->next;
        }
        return ;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    // 返回给定的键所对应的值，如果映射中不包含这个键，返回-1。
    int get(int key) {
        // 哈希映射，计算该键在数组中的索引
        int index = key % len;
        // 获取数组内容
        Node *tmp = arr[index];
        while (tmp) {
            // 该key已经存在，返回value
            if (tmp->key == key)
                return tmp->value;
            // 指向链表下一个节点
            tmp = tmp->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    // 如果映射中存在这个键，删除这个键值对
    void remove(int key) {
        // 哈希映射，计算该键在数组中的索引
        int index = key % len;
        // 获取数组内容
        Node *tmp = arr[index];
        while (tmp) {
            // 该key存在，清除键值，没有实际删除
            if (tmp->key == key) {
                tmp->value = 0;
                tmp->key = -1;
                return ;
            }
            tmp = tmp->next;
        }
        return ;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */



#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int key;
    int value;
    Node * next;
public:
    Node(int key_, int value_):key(key_),value(value_),next(nullptr){};
    ~Node();
};

const int len = 100;

class MyHashMap {
public:
    vector<Node*> arr;
public:
    MyHashMap():arr(vector<Node*>(len, nullptr)) {
        for (int i = 0; i < len; i++)
            arr[i] = new Node(-1,0);
    }
    
    void put(int key, int value) {
        int index = key % len;
        Node *tmp = arr[index];
        while (tmp) {
            if (tmp->key == -1) {
                tmp->key = key;
                tmp->value = value;
                return ;
            }
            if (tmp->key == key) {
                tmp->value = value;
                return ;
            }
            if (tmp->next == nullptr) {
                tmp->next = new Node(key, value);
                return ;
            }
            tmp = tmp->next;
        }
        return ;
    }
    
    int get(int key) {
        int index = key % len;
        Node *tmp = arr[index];
        while (tmp) {
            if (tmp->key == key)
                return tmp->value;
            tmp = tmp->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = key % len;
        Node *tmp = arr[index];
        while (tmp) {
            if (tmp->key == key) {
                tmp->value = 0;
                tmp->key = -1;
                return ;
            }
            tmp = tmp->next;
        }
        return ;
    }
};

int main() {
    MyHashMap *hashMap = new MyHashMap();
    hashMap->put(1, 1);
    hashMap->put(2, 2);
    cout << hashMap->get(1) << endl;
    cout << hashMap->get(3) << endl;
    hashMap->put(2, 1);
    cout << hashMap->get(2) << endl;
    hashMap->remove(2);
    cout << hashMap->get(2) << endl;
}


```