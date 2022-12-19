
栈的特点就是先进后出、后进先出。生活中也可以找到类似的场景：比如说吃完饭要洗盘子，把东西都摞起来端到洗碗池边，然后就很自然地从最上面取下来开始洗；或者说装羽毛球的筒子，放在最上面的先取出来用，如果打完了以后又放回去，下一次取出来还是这一颗。

### 解题思路

Python 列表里带了很多开箱即用的东西，`append(x)` 将元素 `x` 附加到列表尾，`pop()` （默认是移除列表尾）直接就是类似出栈这样的操作。 负数索引可以很方便的从右数元素，所以 `stack[-1]` 就是右边第一个，所谓栈顶。至于判断空，没东西就是空的，有就不是空的，加个 `not` 就可以。果然就是人生苦短，我用 `Python`。

C 语言的实现也很简单，结构体的主要组成成分就是一个数组 `myarray` 加一个栈顶位置标记 `len`，当然说成栈长也未尝不可。如果要加新元素，就要给 `myarray[len]` 的元素赋值，然后再给栈长加 `1`；删除的时候自然是反过来。返回栈顶元素自然就是返回 `myarray[len - 1]`。判断是不是空其实看栈长就可以。

Rust 其实也很舒服，在这里几乎和 Python 实现有一拼。只要知道 `VecDeque` 和里面的方法就没什么好说的，需要可变变量的时候记得加 `mut`，有借用的时候带上 `*`，该 `unwarp()` 也不要省。不得不说，编译器报错真的太人性化了，哪里有问题、怎么改一目了然。

### 代码

```python3 []
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.stack.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.stack.pop()


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.stack[-1]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not self.stack
```

```c []
#define MAX_SIZE 1000
#define NULL -1001

typedef struct {
    int myarray[MAX_SIZE];
    int len;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *stack = malloc(sizeof(MyStack));
    stack -> len = 0;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj -> myarray[obj->len] = x;
    obj -> len += 1;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int top = obj->myarray[obj->len - 1];
    obj -> myarray[obj->len] = NULL;
    obj -> len -= 1;
    return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->myarray[obj->len - 1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return !(obj -> len);
}

void myStackFree(MyStack* obj) {
    free(obj);
}
```

```rust []
use std::collections::VecDeque;

struct MyStack {
    data: VecDeque<i32>
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyStack {

    /** Initialize your data structure here. */
    fn new() -> Self {
        Self {
            data: VecDeque::<i32>::new(),
        }
    }
    
    /** Push element x onto stack. */
    fn push(&mut self, x: i32) {
        self.data.push_back(x)
    }
    
    /** Removes the element on top of the stack and returns that element. */
    fn pop(&mut self) -> i32 {
        self.data.pop_back().unwrap()
    }
    
    /** Get the top element. */
    fn top(&self) -> i32 {
        *self.data.back().unwrap()
    }
    
    /** Returns whether the stack is empty. */
    fn empty(&self) -> bool {
        self.data.is_empty()
    }
}

```