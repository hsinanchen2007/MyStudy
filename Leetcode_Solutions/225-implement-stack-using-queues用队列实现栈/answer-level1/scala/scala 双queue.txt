```
import scala.collection.mutable
import scala.util.control.Breaks._

class MyStack() {

    /** Initialize your data structure here. */
    var que = new mutable.Queue[Int]()
    var help = new mutable.Queue[Int]()

    /** Push element x onto stack. */
    def push(x: Int) {
        que.enqueue(x)
    }

    /** Removes the element on top of the stack and returns that element. */
    def pop(): Int = {
        if (empty()) { //空则抛出异常
            throw new Exception("stack is empty !")
        } else {
            var item = 0
            breakable {
                while (true) {
                    item = que.dequeue()
                    if (!empty()) {
                        help.enqueue(item)
                    } else {
                        break()
                    }
                }
            }

            val queueItem = help;
            help = que;
            que = queueItem
            item
        }

    }

    /** Get the top element. */
    def top(): Int = {
        if (empty()) {
            throw new Exception("stack is empty !")
        } else {
            que.last
        }
    }

    /** Returns whether the stack is empty. */
    def empty(): Boolean = {
        que.isEmpty
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
