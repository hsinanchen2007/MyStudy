### 解题思路
此题撰写时，借鉴了[@youlookdeliciousc](/u/youlookdeliciousc/)
在705设计哈希集合中的解题思路。

此题的测试用例范围非常大，有以下思路：
1. 提前用数组分配好这些内存，但势必造成浪费。
2. 分配内存小，但又会出现哈希冲突。
显然，做好这道题当然是不能采用思路一的。
因此对于思路二，我们需要着重解决哈希冲突。
解决哈希冲突的方法有很多，这里我们采用链地址法。

链表可以随时添加节点，并且长度没有限制，可以合理解决哈希冲突。
因此选择数组+链表即可实现动态存储。
使用数组分配一定个数的链表节点类型的指针。
```
    vector<Node*> arr;
```
代码本身写的并不好，可能格式没那么规整，精简度也不高，欢迎大家指正！

天时地利人和:
![Test.png](https://pic.leetcode-cn.com/a06fde38ad098be88f35b163742ac29bbda57e19c71fb4aabd0643cff169f724-Test.png)

### 代码

```cpp
#include <vector>

class Node
{
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
    /** Initialize your data structure here. */
    MyHashMap():arr(vector<Node*>(len, nullptr)){
        for (int i = 0; i < len; ++i)
            arr[i] = new Node(-1,0);
    }
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key % len;
        Node *tmp = arr[index];
        while (tmp)
        {
             if (tmp->key == -1)
            {
                tmp->key = key;
                tmp->value = value;
                return ;
            }
            if (tmp->key == key)
            {
                tmp->value = value;
                return ;
            }
            if (tmp->next == nullptr)
            {
                tmp->next = new Node(key, value);
                return ;
            }
            tmp = tmp->next;
        }
        return ;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = key % len;
        Node *tmp = arr[index];
        while (tmp)
        {
            if (tmp->key == key)
                return tmp->value;
            tmp = tmp->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = key % len;
        Node *tmp = arr[index];
        while (tmp)
        {
            if (tmp->key == key)
            {
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
```