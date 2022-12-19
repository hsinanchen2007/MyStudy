本题在算法上并没有什么难度,主要考虑对数据结构的应用,以及一些细节问题.

根据测试用例,我们可以发现这个所谓的"StackSet"存在几个特点：

1、StackSet可以看做是由多个栈组成的一个“容器”,容器中的每个元素都是一个"Stack"

2、每次压栈总是往最后一个栈压入元素,如果最后一个栈的元素个数超过容量,就新建一个栈再压入

3、每次出栈操作总是弹出最后一个栈的元素,如果容器中连一个栈也没有,返回-1

4、popAt操作是找到索引为index的栈,并将其元素弹出.如果不存在该栈,就返回-1

5、如果某一个栈空了,就将该栈删除.注意,删除了索引为index的栈后,之后所有的栈索引都要-1

**数据结构考量**

首先考虑"栈"用什么实现？方案有很多,因为只涉及pop和push操作,那么无论用链表、数组、双向数组都能实现.这里我选择用vector容器作为一个‘栈’(也可以直接用STL的stack).

要实现存储“栈”的容器,可能最直接能够想到的就是"数组",那么可以实现为类似于vector<STACK>的结构,这种设计的优势在于“特点4”,即对某个索引位置的栈进行出栈操作非常方便.这种方案下,找到索引为INDEX的栈只需要O(1)的时间复杂度.但其也有缺点,即考虑"特点5":如果该索引的栈空了,那么vector<STACK>在index后的所有元素都要全部复制、并向前填充，会带来O(N)的时间复杂度,在栈容量比较小的情况下,栈空的情况非常容易出现,此时用本方案的开销是比较大的.

而另一种实现方案,就是用链表来存放一个个栈.链表的特性我们都知道:增、删的速度非常快,只需要O(1)的时间复杂度,唯一的缺陷是"查",要找到某个索引位置,必须从链表首部开始遍历.因此,对于特性5,即使某个索引的栈空了,将其从链表中删除是一件非常容易的事.而对于特性4,找到某索引位置的时间开销较大(O(N)).

对于上述两种方案,主要的区分点就在于特性4、5上，如果考虑实际应用中每个栈的容量较小,导致空栈的情况较多,应当选择链表法.而如果每个栈的容量较大,且popAt操作频繁,就应当选择序列式容器(数组)法.在本题中,我选择的是链表法.


**设计思路**

既然选择了链表作为基本结构,而链表的类型也存在多种,如:单链表\双向链表\循环链表等等.为了便于操作,我在这里选择了双向(循环)链表.双向链表的好处是,对于增、删操作不需要额外保留前驱和后驱节点,因为二者都可以通过当前元素直接获取.

双链表的每个元素可以表示如下:
```
struct node{
        node():size(0),
               next(nullptr),
               prev(nullptr){
                   
        };
        
        //push操作
        void push(int val){
            data.push_back(val);
            size++;
        };
        
        //pop操作
        int pop(){
            int res = data.back();
            data.pop_back();
            size--;
            return res;
        };
        
        int size;    //size表示元素个数
        node* next;  //next表示下一节点
        node* prev;  //prev表示上一节点
        
    private:
        vector<int> data; //data用于存储实际数据
    };
    
```

我这里将入栈和出栈操作都作为其member function,这样调用起来比较简洁.



而除此之外,对于链表的操作,我们只需要考量增\删:

```
 //链表的插入元素操作,即创建新的"栈"
    void insert_tail(){
        node *cur = new node;
        auto pnode = tail->prev;
        pnode->next = cur;
        cur->next = tail;
        tail->prev = cur;
        cur->prev = pnode;
    }
    
    //链表的删除操作
    void remove(node *cur){
        auto pnode = cur->prev;
        auto nnode = cur->next;
        cur->prev = nullptr;
        cur->next = nullptr;
        pnode->next = nnode;
        nnode->prev = pnode;
    }
```

以上是基本的双链表操作,基本都是类似的模板.

**整体代码**

```
class StackOfPlates {
public:
    //自定义数据类型,用一个双链表来存储"栈"
    struct node{
        node():size(0),
               next(nullptr),
               prev(nullptr){
                   
        };
        
        //push操作
        void push(int val){
            data.push_back(val);
            size++;
        };
        
        //pop操作
        int pop(){
            int res = data.back();
            data.pop_back();
            size--;
            return res;
        };
        
        int size;    //size表示元素个数
        node* next;  //next表示下一节点
        node* prev;  //prev表示上一节点
        
    private:
        vector<int> data; //data用于存储实际数据
    };
    
    
    //构造函数中初始化head和tail两个元素,方便后续的操作
    StackOfPlates(int cap):capacity(cap),
                           head(nullptr),
                           tail(nullptr){
        head = new node{};
        tail = new node{};
        head->next = tail;
        tail->prev = head;
        head->prev = tail;                       
        tail->next = head;                       
    }
    
    //压栈操作,即找到最后一个栈所在链表中的位置,如果不存在就返回-1
    void push(int val) {
        if(capacity <= 0) return;
        
        auto cur = tail->prev;
        
        if(cur == head || cur->size >= capacity) {
            insert_tail();
            cur = tail->prev;
        }
        
        cur->push(val);
        
    }
    
    //出栈操作,也是找到最后一个栈所在链表中的位置,如果不存在就返回-1
    int pop() {
        auto cur = tail->prev;
        
        if(cur == head) return -1;
        
        auto res = cur->pop();
        
        if(cur->size <= 0) remove(cur);
        
        return res;
        
    }
    
    //popAt需要顺序遍历链表找到对应索引的位置,如果不存在就返回-1;
    int popAt(int index) {
        int pos = 0;
        
        auto cur = head->next;
        
        while(pos < index && cur != tail){
            pos++;
            cur = cur->next;
        }
        
        if(cur == tail) return -1;
        
        auto res = cur->pop();
        
        if(cur->size <= 0) remove(cur);
        
        return res;
    }
    
    //链表的插入元素操作,即创建新的"栈"
    void insert_tail(){
        node *cur = new node;
        auto pnode = tail->prev;
        pnode->next = cur;
        cur->next = tail;
        tail->prev = cur;
        cur->prev = pnode;
    }
    
    //链表的删除操作
    void remove(node *cur){
        auto pnode = cur->prev;
        auto nnode = cur->next;
        cur->prev = nullptr;
        cur->next = nullptr;
        pnode->next = nnode;
        nnode->prev = pnode;
    }
    
private:
    int capacity;
    node *head;
    node *tail;
};

```











































































