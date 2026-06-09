# 算法如下:
自定义一个结构体，里面存放一个int值以及一个指向包含自身以及已经栈内的最小int值的指针。再创建一个私有成员（栈）。所以每个栈元素都有保存数据变量以及指向栈内最小值的指针。可以看出栈内的元素中指向最小值的指针都是单向的，都是由栈顶指向栈底的方向，不会指向后面压入的栈元素，所以，当目前的最小值被pop后（也就是pop的值就是原栈内最小值）并不会改变pop后栈内的最小值。总的来说，除了栈顶元素自身，其他栈元素的指向最小值的指针不可能指向栈顶元素的值。

# 这里给出两个算法：
1. 算法一：利用STL栈
```
class MinStack {
public:
    /** initialize your data structure here. */
    typedef struct  Node{
        int var;  //存放元素x的值
        int *min;  //指向栈底到本栈节点中最小值所在的栈元素
        Node(int _var,int *_min = nullptr ):var(_var),min(_min){} //构造函数
    }node;

    MinStack(){

    }
    
    void push(int x) {
        if( (stacknode.empty() == true) || ( *(stacknode.top().min)  >= x ) )
        {//如果第一个进栈，或者值为最新最小值，则使栈元素中的min指针指向自身，再压进栈内
            Node tmp = node(x);
            stacknode.push(tmp);
         /*这里一定是压入栈后在设置min，不然min(此时min一定指向自身节点地址，
故要保证min指向的是压入栈后的自身节点地址)指向的是未压入栈是的内存地址，不是栈内的地址。*/
            stacknode.top().min = &(stacknode.top().var);
        }
        else 
        {//使栈元素中的min指针拷贝原栈顶节点的min的值，再压进栈内
         //这里可以压入栈前设置min，因为此时不可能min指向自身节点地址。         
            Node tmp = node(x,stacknode.top().min);
            stacknode.push(tmp); 
       }
    }
    
    void pop() {

            stacknode.pop();
    }
    
    int top() {
       return stacknode.top().var;
    }
    
    int getMin() {
       return  *(stacknode.top().min);
    }

private:
    stack<node> stacknode;  //创建私有成员
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```
![2.png](https://pic.leetcode-cn.com/d8ba9c8995e5706a039acbbacb1f1c194cfd6288e21faeb448f37240777faee2-2.png)


2. 算法2：使用单链表实现
```
class MinStack {
public:
    typedef struct stacknodo
    {
        int var; //当前值
        int *min;    //指向该栈元素以下所有元素中包含最好值所在栈元素
        stacknodo *next;
        stacknodo(int _var,int *_min=nullptr,stacknodo *_next = nullptr)
        :var(_var),min(_min),next(_next){}  //构造函数

    }stackItem;

    /** initialize your data structure here. */
    MinStack(stackItem *_stackTop1=nullptr,stackItem *_stackTop2=nullptr,int _size=0)  //初始化私有成员，放在构造函数的初始化列表是为了优化
    :stackTop1(_stackTop1),stackTop2(_stackTop2),size(_size)
    {
        
    }
    
    void push(int x) {
        if(0 == size) //第一个栈元素进栈时
        {
        ++size;
        stackTop1 = new stackItem(x);
        stackTop1->min = &(stackTop1->var);
        }
        else   //非空栈时
        {
        ++size;
        stackTop2 = stackTop1;
        stackTop1 = new stackItem(x,nullptr,stackTop2);
        stackTop1->min = (x < *(stackTop2->min)) ? &(stackTop1->var) : stackTop2->min;
        } 
    }
    
    void pop() {
        if(0 == size)return;  //空栈时直接退出
        else  
        {
            --size;
            delete stackTop1;
            stackTop1 = stackTop2;
            if( nullptr == stackTop2 )
                return;
            else
            {
                stackTop2 = stackTop1->next;
            }
        }   
    }
    
    int top() {
      return  stackTop1->var;  
    }
    
    int getMin() {
       return *(stackTop1->min);   
    }
    // ~MinStack()  //注释该析构函数而使用系统默认析构函数，可减少执行用时和内存消耗
    // {
    //     if(0 == size )
    //         return;
    //     else
    //     {
    //         while(stackTop1 != nullptr)
    //         {
    //             delete stackTop1;
    //             stackTop1 = stackTop2;
    //             if( nullptr == stackTop2 )
    //                 return;
    //             else
    //                 stackTop2 = stackTop2->next;
    //         }
    //     }

    // }  
 private:
        stackItem *stackTop1;
        stackItem *stackTop2;
        int size;
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```
![1.png](https://pic.leetcode-cn.com/e44ff6629ea88cd61f7b494e8eeade96119006ff93b6b062d6f8b251e12dff9d-1.png)

# 优势：
当本题的数据类型改为string或者更大的数据结构时，将会节省更多的内存空间，优势将会愈来愈大；只需要每个栈元素中放一个数据类型的指针标记最小值的f地址，比如string的指针，而不管是什么类型的指针都是一个字的大小，而不需要用更多的空间备份数据，而数据可能远比一个字还要大。而是用双栈，或者使用一个数据的类型的变量来存储最小值的方法将会使用更多的内存。

最后
算法1借鉴了[@jason-2](/u/jason-2/)同学的算法：
[https://leetcode-cn.com/problems/min-stack/solution/yong-zhan-by-jason-2/]()
算法2借鉴了[@xiaohuntun](/u/xiaohuntun/)同学的算法：
[https://leetcode-cn.com/problems/min-stack/solution/gen-ju-zhan-de-yuan-li-shi-xian-bu-shi-yong-stl-by/]()

