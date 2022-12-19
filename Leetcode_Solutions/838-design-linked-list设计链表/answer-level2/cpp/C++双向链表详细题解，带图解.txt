本题分为以下几个点
- 初始化链表
- 获得第index个节点的值
- 添加头节点
- 添加尾节点
- 添加第index个节点
- 删除第index个节点

这里使用双向链表来做。节省运行时间，但比较占用内存。 

代码基本都有注释，相对详细。

__代码后面有图解解释关键步骤__

```cpp
struct Node{ //构造链表Node结构
    int val; 
    Node *prev, *next;
    Node(int val): val(val), prev(nullptr), next(nullptr) {} //初始化
};
class MyLinkedList {
public:
    MyLinkedList(): head(nullptr), tail(nullptr),size(0){} //初始化链表
    
    
    int get(int index) { //通过getNode函数返回第index个节点的地址，return 该节点的值
        if(getNode(index))
            return getNode(index) -> val;
        return -1;
    }
    
    void addAtHead(int val) { //在head添加节点
        auto node = new Node(val); //创建一个Node实例，下同
        ++ size; //链表长度加一，下同
        if(head == nullptr) //如果链表为空，新加的node既是head也是tail，下同
        {
            head = node;
            tail = node;
        }
        else
        {
            node -> next = head; //常规的添加头节点步骤，参照代码后的图解
            head -> prev = node;
            head = node;
        }
    }
    
    void addAtTail(int val) { //在tail添加节点
        auto node = new Node(val);
        ++ size;
        if(tail == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            node -> prev = tail; //常规的添加尾节点步骤，参照代码后的图解
            tail -> next = node;
            tail = node;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index > size)    return; //如果索引大于链表长度，无效索引
        if(index == size) //若索引等于链表长度，相当于添加尾节点，直接调用先前定义好的函数
        {
            addAtTail(val);
            return;
        }
        if(index <= 0) //若索引小于链表长度，本题题目的bug，我们需要将它看成添加头节点，直接调用先前定义好的函数
        {
            addAtHead(val);
            return;
        }
        auto node = new Node(val); //添加在非head非tail的位置的情况
        auto nextNode = getNode(index); //过程参照代码后的图解
        nextNode -> prev -> next = node;
        node -> prev = nextNode -> prev;
        node -> next = nextNode;
        nextNode-> prev = node;
        ++ size;
    }
    
    void deleteAtIndex(int index) { //删除节点
        if(auto node = getNode(index)) //若该节点不为nullptr，进行以下步骤
        {
            if(node == head) //若该节点为head，指针head更新为原来head的下一个点的位置
            {
                head = head -> next;
                if(head != nullptr) head -> prev = nullptr; //若新head不为nullptr，将head的prev指针设为空，删除的节点的next指针设为空，即两者断开。
                node -> next = nullptr;
            }
            if(node == tail) //若该节点为tail，与上一步类似
            {
                tail = tail -> prev;
                if(tail != nullptr) tail -> next = nullptr;
                node -> prev = nullptr;
            }
             //若目标节点上或下的指针还不为nullptr，说明指针还未独立出来，需要做以下操作
            if(node -> next != nullptr) node -> next -> prev = node -> prev;
            if(node -> prev != nullptr) node -> prev -> next = node -> next;
            delete node;
            -- size;
        }
    }
private:
    Node* getNode(int index) //获得目标节点位置，因为是双向链表，通过判断目标点位置在前半段还是后半段来决定从head开始搜索还是从tail搜索
    {
        if(index >= size || index < 0)  return nullptr;
        Node* node;
        int i;
        if(size/2 >= index)
        {
            i = index;
            node = head;
            while(i -- > 0)
            {
                node = node -> next;
            }
        }
        else
        {
            i = size - index - 1;
            node = tail;
            while(i -- > 0)
                node = node -> prev;
        }
        return node;
    }
    
private:
    Node* head;
    Node* tail;
    int size;
};
```

以下是关于单链表的图解，至于双链表，就比单链表每个节点多一个指针，需要注意更新相应的指针

__添加head的图解，添加tail类似__

![添加节点.png](https://pic.leetcode-cn.com/3ade6a162afc613a69cef86d1886bbaa136f9343cb63290e54e4847ad046ea82-%E6%B7%BB%E5%8A%A0%E8%8A%82%E7%82%B9.png)

__在指定位置插入节点__

![在指定位置插入节点.png](https://pic.leetcode-cn.com/3e5ecef5864da58714200ac6d1cd7a83260286dfd0c1d7d525959bb29f42e49a-%E5%9C%A8%E6%8C%87%E5%AE%9A%E4%BD%8D%E7%BD%AE%E6%8F%92%E5%85%A5%E8%8A%82%E7%82%B9.png)

__删除节点图解__

![删除节点.png](https://pic.leetcode-cn.com/119decedf50955c481bb01ae643c09aa8cb1c3127dfacfbd546f7e7411527723-%E5%88%A0%E9%99%A4%E8%8A%82%E7%82%B9.png)

__搜索节点__

![搜索1.png](https://pic.leetcode-cn.com/3b06bbf9f7c5bc628569763f47354b9404adf6251e0ec9e1cac1b02eecc6aa23-%E6%90%9C%E7%B4%A21.png)

![搜索2.png](https://pic.leetcode-cn.com/6c7d860280212facbfa40b849ae16682c1f85758055c652896ace4d634ff5566-%E6%90%9C%E7%B4%A22.png)
