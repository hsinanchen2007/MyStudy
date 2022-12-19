比较常见的两个队列来完成。一般可以记录下topEle，可以给top方法省些时间。因为题目说不存在异常情况，也就省了相关的操作。
一个队列也能完成这题，思路都是一样的。
```
import scala.collection.mutable._
class MyStack() {

    /** Initialize your data structure here. */
    var queue = Queue[Int]()
    var topEle = 0
    


    /** Push element x onto stack. */
    def push(x: Int) {
        queue.enqueue(x)
        topEle = x
    }

    /** Removes the element on top of the stack and returns that element. */
    def pop(): Int = {
        val tmpQueue = Queue[Int]()
        while(queue.size > 1){
            topEle = queue.dequeue
            tmpQueue.enqueue(topEle)
        }
        val res = queue.dequeue
        queue = tmpQueue
        res
    }

    /** Get the top element. */
    def top(): Int = {
        topEle
    }

    /** Returns whether the stack is empty. */
    def empty(): Boolean ={
        queue.isEmpty
    }

}

/**
 * Your MyStack object will be instantiated and called as such:
 * var obj = new MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */
```