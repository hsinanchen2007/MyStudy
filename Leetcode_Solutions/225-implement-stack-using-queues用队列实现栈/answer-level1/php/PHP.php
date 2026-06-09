```php
class MyStack {
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->queue = [];
    }

    /**
     * Push element x onto stack.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        $queue[] = $x;
        foreach ($this->queue as $value) {
            $queue[] = $value;
        }
        $this->queue = $queue;
    }

    /**
     * Removes the element on top of the stack and returns that element.
     * @return Integer
     */
    function pop() {
        $pop = $this->queue[0];
        unset($this->queue[0]);
        $queue = [];
        foreach ($this->queue as $value) {
            $queue[] = $value;
        }
        $this->queue = $queue;
        return $pop;
    }

    /**
     * Get the top element.
     * @return Integer
     */
    function top() {
        foreach ($this->queue as $value) {
            return $value;
        }
    }

    /**
     * Returns whether the stack is empty.
     * @return Boolean
     */
    function empty() {
        return empty($this->queue);
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