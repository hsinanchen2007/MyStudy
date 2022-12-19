参考题解中的高票解答

```php
class MyQueue {
    protected $stackPush;
    protected $stackPop;
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->stackPush = new SplStack();
        $this->stackPop = new SplStack();
    }

    /**
     * Push element x to the back of queue.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        $this->stackPush->push($x);
    }

    /**
     * Removes the element from in front of queue and returns that element.
     * @return Integer
     */
    function pop() {
        if ($this->stackPop->isEmpty()) {
            $this->shift();
        }

        return $this->stackPop->pop();
    }

    /**
     * Get the front element.
     * @return Integer
     */
    function peek() {
        if ($this->stackPop->isEmpty()) {
            $this->shift();
        }

        return $this->stackPop->top();
    }

    private function shift()
    {
        while (!$this->stackPush->isEmpty()) {
            $this->stackPop->push($this->stackPush->pop());
        }
    }

    /**
     * Returns whether the queue is empty.
     * @return Boolean
     */
    function empty() {
        return $this->stackPush->isEmpty() && $this->stackPop->isEmpty();
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