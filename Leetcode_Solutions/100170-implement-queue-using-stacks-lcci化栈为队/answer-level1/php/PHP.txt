```php
class MyQueue {
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->queue = [];
    }

    /**
     * Push element x to the back of queue.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        $this->queue[] = $x;
    }

    /**
     * Removes the element from in front of queue and returns that element.
     * @return Integer
     */
    function pop() {
        foreach ($this->queue as $key => $value) {
            $pop = $value;
            unset($this->queue[$key]);
            break;
        }
        return $pop;
    }

    /**
     * Get the front element.
     * @return Integer
     */
    function peek() {
        foreach ($this->queue as $value) {
            return $value;
        }
    }

    /**
     * Returns whether the queue is empty.
     * @return Boolean
     */
    function empty() {
        return empty($this->queue);
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * $obj = MyQueue();
 * $obj->push($x);
 * $ret_2 = $obj->pop();
 * $ret_3 = $obj->peek();
 * $ret_4 = $obj->empty();
 */
```