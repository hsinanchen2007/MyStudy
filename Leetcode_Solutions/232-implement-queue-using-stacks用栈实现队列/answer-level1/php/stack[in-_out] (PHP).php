```
class MyQueue {
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->in = [];
        $this->out = [];
    }
    
    private function transferIfEmpty() {
        if (empty($this->out)) {
            while (!empty($this->in)) {
                array_push($this->out, array_pop($this->in));
            }
        }
    }

    /**
     * Push element x to the back of queue.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        array_push($this->in, $x);
    }
  
    /**
     * Removes the element from in front of queue and returns that element.
     * @return Integer
     */
    function pop() {
        $this->transferIfEmpty();
        return array_pop($this->out);
    }
  
    /**
     * Get the front element.
     * @return Integer
     */
    function peek() {
        $this->transferIfEmpty();
        return end($this->out);
    }
  
    /**
     * Returns whether the queue is empty.
     * @return Boolean
     */
    function empty() {
        return empty($this->in) && empty($this->out);
    }
}
```
