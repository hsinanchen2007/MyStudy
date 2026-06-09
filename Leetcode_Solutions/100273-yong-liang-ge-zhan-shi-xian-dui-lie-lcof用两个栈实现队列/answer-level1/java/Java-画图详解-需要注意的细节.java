### 解题思路
定义两个栈，`stackPush`专门用来添加数据，`stackPop`专门用来弹出数据。

假如现在有一组数据`1, 2, 3, 4, 5`，则先让这些数据入`stackPush`栈（从`1`开始进），如下所示：
```
    |  5 |
    |  4 |
    |  3 |
    |  2 |
    |  1 |
    |____|
   stackPush
```
再让这些数据依次出栈，从而进入到`stackPop`中，如下所示：
```
        ______________
       |             ↓
    |    |         |  1 |
    |    |         |  2 |
    |    |         |  3 |
    |    |         |  4 |
    |    |         |  5 |
    |____|         |____|
   stackPush       stackPop
```

在将元素放到`stackPop`之前，需要注意的点：

1. **如果`stackPush`决定要把元素往`stackPop`里送的话，则需要一次性全部送完；**
2. **如果`stackPop`里面有元素，则`stackPush`一定不要送元素，而是要等到`stackPop`一股脑全部弹出元素之后再送。**

**首先，解释第`1`点，为什么要全部都送完？**
假如`stackPush`已经往`stackPop`送了元素`4`和`5`，如果此时其它元素（例如`9`）不小心进入了`stackPush`中的话，则顺序就会被其它元素（例如`9`）给打破，则无法按照队列的定义进行出栈。如下所示：
```
        ______？______
       |             ↓
    |    |         |    |
    |  9 |         |    |
    |  3 |         |    |
    |  2 |         |  4 |
    |  1 |         |  5 |
    |____|         |____|
   stackPush       stackPop
```

**其次，解释第`2`点，为什么当`stackPop`里面有元素的时候，`stackPush`一定不要送元素？**
该问题与第`1`点也有关系。也就是说，在`stackPop`里面还有元素的时候，此时如果`stackPush`送元素给`stackPop`的话，同样会出现顺序被打乱的问题。

### 代码

```java
class CQueue {
    Stack<Integer> stackPush;
    Stack<Integer> stackPop;
    
    public CQueue() {
        stackPush = new Stack<>();
        stackPop = new Stack<>();
    }
    // 添加元素（入队），那你就尽管添加就好了，来者不拒
    public void appendTail(int value) {
        stackPush.push(value);
    }
    // 删除元素（出队）
    public int deleteHead() {
        // 我现在两只手都是干干净净的，没有东西要给你
        if (stackPush.isEmpty() && stackPop.isEmpty()) {
            return -1;
         // 能够走到这里说明：其中一只手里面有东西了
         // 但前提条件是，stackPop 不为空才可以删除元素
        } else if (stackPop.isEmpty()) {
            // 如果 stackPop 为空的话，我就让 stackPush 给 stackPop 送元素
            while (!stackPush.isEmpty()) {
                stackPop.push(stackPush.pop());
            }
        }
        return stackPop.pop();
    }
}
```

### 全部题解
《剑指Offer》的全部题解与 LeetCode 的部分题解在此下方，其中还包含**基础算法**与**进阶算法**，欢迎查看~
[LeetCode、SwordToOffer and other algorithms in Java.](https://github.com/dyfloveslife/LeetCodeAndSwordToOffer)