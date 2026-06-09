### 解题思路
此处撰写解题思路
直接利用C语言的结构体模拟栈操作，结构体内的top变量代表栈定元素的下一个下标。当top=0的时候栈空
### c代码

```c
typedef struct {
    int data[1001];
    int top;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *stack=(MyStack*)malloc(sizeof(MyStack));
    stack->top=0;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->data[obj->top++]=x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    return obj->data[--obj->top];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->data[obj->top-1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->top) return false;
    else return true;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
```
### python代码
```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack=[];

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.stack.append(x);

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        res = self.stack[-1];
        del self.stack[-1];
        return res

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.stack[-1];

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if len(self.stack)==0: return True
        else: return False

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```


