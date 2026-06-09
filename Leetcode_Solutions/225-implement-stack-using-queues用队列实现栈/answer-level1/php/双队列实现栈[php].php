### 解题思路
见代码

### 代码

```php
class MyStack {
    private $push_queue;
    private $pop_queue;
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->push_queue = new SplQueue();
        $this->pop_queue = new SplQueue();
    }

    /**
     * Push element x onto stack.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        $this->push_queue->enqueue($x);
        while(!$this->pop_queue->isEmpty()){
            $this->push_queue->enqueue($this->pop_queue->dequeue());
        }
        list($this->push_queue,$this->pop_queue) = [$this->pop_queue,$this->push_queue];
    }

    /**
     * Removes the element on top of the stack and returns that element.
     * @return Integer
     */
    function pop() {
        return $this->pop_queue->dequeue();
    }

    /**
     * Get the top element.
     * @return Integer
     */
    function top() {
        return $this->pop_queue->bottom();
    }

    /**
     * Returns whether the stack is empty.
     * @return Boolean
     */
    function empty() {
        return $this->pop_queue->isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * $obj = MyStack();
 * $obj->push($x);
 * $ret_2 = $obj->pop();
 * $ret_3 = $obj->top();
 * $ret_4 = $obj->empty();
 */
```