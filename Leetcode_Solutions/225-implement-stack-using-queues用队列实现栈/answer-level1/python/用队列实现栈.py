### 解题思路
用两个队列模拟栈
初始化：创建两个空队列q1, q2
添加元素：若两个队列都为空，则向q1末尾添加元素；否则向不为空的队列中添加元素
弹出栈顶元素：不为空的队列的队头元素依次出队，最后一个出队的为栈顶元素，用另一个队列来存储出队的元素
取栈顶元素：与弹出栈顶元素一致，只是最后出队的元素还需要入队
判断空栈：两个队列都为空则栈为空

### 代码
**python**

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q1 = []
        self.q2 = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        if self.q1==[] and self.q2==[]:
            self.q1.append(x)
        elif self.q1==[]:
            self.q2.append(x)
        elif self.q2==[]:
            self.q1.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if self.q1==[]:
            while(self.q2):
                e = self.q2.pop(0)
                if self.q2==[]:
                    return e
                self.q1.append(e)
        elif self.q2==[]:
            while(self.q1):
                e = self.q1.pop(0)
                if self.q1==[]:
                    return e
                self.q2.append(e)


    def top(self) -> int:
        """
        Get the top element.
        """
        if self.q1==[]:
            while(self.q2):
                e = self.q2.pop(0)
                self.q1.append(e)
                if self.q2==[]:
                    return e            
        elif self.q2==[]:
            while(self.q1):
                e = self.q1.pop(0)
                self.q2.append(e)
                if self.q1==[]:
                    return e
            

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if self.q1==[] and self.q2==[]:
            return True
        else:
            return False





```
**c++**
```
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> A;
    queue<int> B;

    MyStack() {    
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (A.empty() && B.empty())
            A.push(x);
        else if (B.empty())
            A.push(x);
        else if (A.empty())
            B.push(x); 
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top;

        if (B.empty())
        {
            while(A.size()>1)
            {
                int temp = A.front();
                A.pop();
                B.push(temp);
            }
            top = A.front();
            A.pop();
        }

        else if (A.empty())
        {
            while(B.size()>1)
            {
                int temp = B.front();
                B.pop();
                A.push(temp);
            }
            top = B.front();
            B.pop();
        }

        return top;
    }
    
    /** Get the top element. */
    int top() {
        int top;

        if (B.empty())
        {
            int temp;
            while(A.size()>1)
            {
                temp = A.front();
                A.pop();
                B.push(temp);
            }
            top = A.front();
            A.pop();
            B.push(top);
        }

        else if (A.empty())
        {
            int temp;
            while(B.size()>1)
            {
                temp = B.front();
                B.pop();
                A.push(temp);
            }
            top = B.front();
            B.pop();
            A.push(top);
        }

        return top;
        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if (A.empty() && B.empty())
            return true;
        else
            return false;
    }
};
```
