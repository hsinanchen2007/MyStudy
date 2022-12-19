### 解题思路
1.题目的意思就是用两个栈列实现一个队列，那么首先要,明白队列的合栈各自的特点。堆的话先进先出，栈的话先进后出
2.大致思路就是用两个栈存放元素，插入元素直接往items中插入，删除时从itemsTail删除，当itemsTail为空时从items中迁移元素。（我也不知道我说的是啥，大致意思就是这样）

### 代码

```java
class CQueue {
    private Stack<Integer> items;
    private Stack<Integer> itemsTail;
    public CQueue() {
        items = new Stack();
        itemsTail = new Stack();
    }

    public void appendTail(int value) {
        items.push(value);
    }

    public int deleteHead() {
        if(itemsTail.isEmpty()){
            while(!items.isEmpty()){
                itemsTail.push(items.pop());
            }
        }
        if(itemsTail.isEmpty()){
            return -1;
        }
        return itemsTail.pop();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```