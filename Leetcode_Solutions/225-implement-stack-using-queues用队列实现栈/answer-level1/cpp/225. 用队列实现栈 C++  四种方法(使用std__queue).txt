队列：先进先出      栈：后进先出

思想：入队后就将队列内部元素逆序，从队首出队 或者 出队的时候将队尾元素出队    

四种解法：  

方法1、 一个队列的实现，只需要在插入时重新调整元素顺序即可
每次入队都把队尾之前的元素重新移到后边，造成队内顺序永远是实际入队顺序的逆序：
插入1  1
插入2  2-1；
插入3  3-2-1，
顺序入队，逆序存储，达到后进先出的效果。

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {

        m_queue.push(x); //入队

        //将之前的元素出队并插入队尾
        for (int i = 0; i < m_queue.size() - 1; ++i)
        {
            m_queue.push(m_queue.front());
            m_queue.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int front = m_queue.front();
        m_queue.pop();
        return front;
    }

    /** Get the top element. */
    int top() {
        return m_queue.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return m_queue.empty();
    }

private:
    std::queue<int> m_queue;
};



方法2、两个队列的实现
借助一个临时队列，仅在插入的时候做处理（与方法1类似，但多用了一个队列 顺序入队，逆序存储）
1、插入之前 先将队列中所有元素搬到临时队列
2、将新元素插入队列
3、再将临时队列中元素搬回队列
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        //插入之前 先将队列中所有元素搬到临时队列
        while (!m_queue.empty())
        {
            m_queue_temp.push(m_queue.front());
            m_queue.pop();
        }

        m_queue.push(x);//入队

        //再将临时队列中元素搬回队列
        while (!m_queue_temp.empty())
        {
            m_queue.push(m_queue_temp.front());
            m_queue_temp.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int front = m_queue.front();
        m_queue.pop();
        return front;
    }

    /** Get the top element. */
    int top() {
        return m_queue.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return m_queue.empty();
    }


private:
    std::queue<int> m_queue;
    std::queue<int> m_queue_temp;
};


方法3、两个队列的实现  在pop、top时处理
    入栈：正常入队列
    出栈：将前n-1个元素移到临时队列， 再出栈最后一个元素, 再将临时队列中的元素全部移回来
    获取栈顶元素：找非空队列，将前n-1个元素移到临时队列，再获取最后一个元素，再将最后一个元素也移到临时队列, 再将临时队列中的元素全部移回来

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        m_queue.push(x);//入队
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        //将前size-1个元素移至临时队列
        while (m_queue.size() > 1)
        {
            m_queue_temp.push(m_queue.front());
            m_queue.pop();
        }

        int front = m_queue.front();
        m_queue.pop();

        //再将临时队列中的所有元素移回队列
        while (!m_queue_temp.empty())
        {
            m_queue.push(m_queue_temp.front());
            m_queue_temp.pop();
        }

        return front;
    }

    /** Get the top element. */
    int top() {
        //将前size-1个元素移至临时队列
        while(m_queue.size() > 1)
        {
            m_queue_temp.push(m_queue.front());
            m_queue.pop();
        }

        int front = m_queue.front();

        //将最后一个元素也移至临时队列
        m_queue_temp.push(m_queue.front());
        m_queue.pop();

        //再将临时队列中的所有元素移回队列
        while (!m_queue_temp.empty())
        {
            m_queue.push(m_queue_temp.front());
            m_queue_temp.pop();
        }

        return front;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return m_queue.empty();
    }


private:
    std::queue<int> m_queue;
    std::queue<int> m_queue_temp;
};


方法4：方法3的改进  使用两个作用等同的队列，减少数据移动  保证操作前后 两个队列要么都为空，要么有一个队列为空
    入栈：找非空队列插入，如果两个队列都为空，则插入第一个队列
    出栈：找非空队列，将前n-1个元素移到另一个队列， 再出栈最后一个元素 （注意：不用再移回来，两个队列作用等同）
    获取栈顶元素：找非空队列，将前n-1个元素移到另一个队列，再获取最后一个元素，再将最后一个元素也移到到另一个队列 （注意：不用再移回来，两个队列作用等同）

class QueueStack
{
public:
    /** Initialize your data structure here. */
    QueueStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {

        if (m_queue_1.empty() && m_queue_2.empty())
        {
            m_queue_1.push(x);//插入队列1
        }
        else if (!m_queue_1.empty())
        {
            m_queue_1.push(x);//插入队列1
        }
        else if (!m_queue_2.empty())
        {
            m_queue_2.push(x);//插入队列2
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {

        int front = 0;

        //将有元素的队列前size-1个元素移至另一个队列
        if (!m_queue_1.empty())
        {
            while (m_queue_1.size() > 1)
            {
                m_queue_2.push(m_queue_1.front());
                m_queue_1.pop();
            }

            front = m_queue_1.front();
            m_queue_1.pop();
        }
        else if (!m_queue_2.empty())
        {
            while (m_queue_2.size() > 1)
            {
                m_queue_1.push(m_queue_2.front());
                m_queue_2.pop();
            }
            front = m_queue_2.front();
            m_queue_2.pop();
        }

        return front;
    }

    /** Get the top element. */
    int top() {
        int front = 0;

        //将有元素的队列的前size-1个元素移至另一个队列
        if (!m_queue_1.empty())
        {
            while (m_queue_1.size() > 1)
            {
                m_queue_2.push(m_queue_1.front());
                m_queue_1.pop();
            }

            front = m_queue_1.front();

            //最后一个也移至另一个队列
            m_queue_2.push(m_queue_1.front());
            m_queue_1.pop();
        }
        else if (!m_queue_2.empty())
        {
            while (m_queue_2.size() > 1)
            {
                m_queue_1.push(m_queue_2.front());
                m_queue_2.pop();
            }
            front = m_queue_2.front();

            //最后一个也移至另一个队列
            m_queue_1.push(m_queue_2.front());
            m_queue_2.pop();
        }

        return front;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return m_queue_1.empty() && m_queue_2.empty();
    }


private:
    std::queue<int> m_queue_1;
    std::queue<int> m_queue_2;
};