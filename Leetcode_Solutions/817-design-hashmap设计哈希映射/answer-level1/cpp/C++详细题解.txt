这里考察的是HashMap的底层实现，所以完全用数组实现是不合理的，而直接用hashmap的内置函数是更不合理的。

引用我小刀哥的话，"这题要用数组做，但是不能完全用数组做"

本题应该通过其它方式实现hashmap。要有Key，也要有value，还有相应的哈希函数

本题解的实现方法是用一段有限数组作为容器，使用哈希函数（这里为key%len，len为数组的长度）算出该数字该放的位置（键值）。若已有数字在内（即发生冲突），利用链表在已有数据的后面插入新数据，解决冲突。这种方法为`链地址法`

以上是我从与本题类似的题目[设计哈希集合](https://leetcode-cn.com/problems/design-hashset/solution/) 自己的题解上复制来的

与另一题的唯一一个差别在于，本题一个key只能有一个value，所以我们用一个节点同时储存key和value，计算哈希值，然后进行操作

```
struct Node{
    int nkey;
    int nval;
    Node* next;
    Node(int key, int val): nkey(key), nval(val), next(nullptr){}
};
int len = 1000;
class MyHashMap {
public:
    vector <Node*> arr;
    /** Initialize your data structure here. */
    MyHashMap() {
        arr = vector<Node*> (len, new Node(-1,-1));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int temp = key % len;
        Node* h = arr[temp];
        Node* prev;
        while(h){
            if(h -> nkey == key){
                h -> nval = value;
                return;
            }
            prev = h;
            h = h -> next;
        }
        Node* node = new Node(key,value);
        prev -> next = node;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int temp = key % len;
        Node* h = arr[temp];
        while(h){
            if(h -> nkey == key)    return h -> nval;
            h = h -> next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int temp = key % len;
        Node* h = arr[temp];
        while(h){
            if(h -> nkey == key){
                h -> nval = -1;
            }
            h = h -> next;
        }
    }
};
```

