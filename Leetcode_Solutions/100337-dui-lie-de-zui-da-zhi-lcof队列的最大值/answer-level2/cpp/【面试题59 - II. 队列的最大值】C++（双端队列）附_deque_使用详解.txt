### 解题思路
1. 递减的双端队列`Q_MAX`维护当前最大值：当插入一个`value`时，`pop_back()`前面比`value`小的元素；
2. 队列`Q`记录所有插入元素

**具体操作**
- `max_value()`：只需返回`Q_MAX`的队头`Q_MAX.front()`；

- `push_back(int value)`：首先，将`value`插入`Q`，再对`Q_MAX`进行处理并插入`value`（处理即`pop_back()`比`value`小的元素）；

- `pop_front()`：首先，记录当前`res = Q.front()`；将`res`与`Q_MAX.front()`元素比较，若相等则`Q_MAX.pop_front()`；最后`Q.pop()`并返回`res`即可。

**注：本题涉及队列`queue`和双端队列`deque`**

**`STL deque`#include <deque>使用详解：** 
>参考:[[C++ STL] deque使用详解] https://www.cnblogs.com/linuxAndMcu/p/10260124.html

>deque（双端队列）是由一段一段的定量连续空间构成，可以向两端发展，因此不论在尾部或头部安插元素都十分迅速。 在中间部分安插元素则比较费时，因为必须移动其它元素。
>
**初始化**
`deque<int> a;` // 定义一个int类型的双端队列a
`deque<int> a(10);` // 定义一个int类型的双端队列a，并设置初始大小为10
`deque<int> a(10, 1);` // 定义一个int类型的双端队列a，并设置初始大小为10且初始值都为1
`deque<int> b(a);` // 定义并用双端队列a初始化双端队列b
`deque<int> b(a.begin(), a.begin()+3);` // 将双端队列a中从第0个到第2个(共3个)作为双端队列b的初始值
**基本操作**
***1. 容量函数***
**容器大小：`deq.size();`**
容器最大容量：`deq.max_size();`
更改容器大小：`deq.resize();`
**容器判空：`deq.empty();`**
***2. 插入函数***
**头部添加元素：`deq.push_front(const T& x);`
末尾添加元素：`deq.push_back(const T& x);`**
任意位置插入一个元素：`deq.insert(iterator it, const T& x);`
任意位置插入 n 个相同元素：`deq.insert(iterator it, int n, const T& x);`
插入另一个向量的 [forst,last] 间的数据：`deq.insert(iterator it, iterator first, iterator last);`
***3. 删除函数***
**头部删除元素：`deq.pop_front();`
末尾删除元素：`deq.pop_back();`**
任意位置删除一个元素：`deq.erase(iterator it);`
删除 [first,last] 之间的元素：`deq.erase(iterator first, iterator last);`
**清空所有元素：`deq.clear();`**
***4. 访问函数***
下标访问：`deq[1];` // 并不会检查是否越界
at 方法访问：`deq.at(1); `// 以上两者的区别就是 at 会检查是否越界，是则抛出 out of range 异常
**访问第一个元素：`deq.front();`
访问最后一个元素：`deq.back();`**


### 代码

```cpp
class MaxQueue {
    //双端队列
private:
    queue<int> Q;
    deque<int> Q_MAX;
public:
    MaxQueue() {

    }
    int max_value() {
        if(Q.empty())
            return -1;
        return Q_MAX.front();
    }
    
    void push_back(int value) {
        Q.push(value);
        while((!Q_MAX.empty()) && (value>Q_MAX.back())){
            Q_MAX.pop_back();
        }
        Q_MAX.push_back(value);
    }
    
    int pop_front() {
        if(Q.empty())
            return -1;
        int res = Q.front();
        if(res == Q_MAX.front()){
            Q_MAX.pop_front();
        }
        Q.pop();
        return res;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```