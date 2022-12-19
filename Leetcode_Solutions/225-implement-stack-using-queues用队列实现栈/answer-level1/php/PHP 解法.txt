 是做出来了，但是感觉非常不优雅，难受

```php
class MyStack
{
    protected $queue1;
    protected $queue2;
    /**
     * Initialize your data structure here.
     */
    function __construct()
    {
        $this->queue1 = new SplQueue();
        $this->queue2 = new SplQueue();
    }

    /**
     * Push element x onto stack.
     * @param Integer $x
     * @return NULL
     */
    function push($x)
    {
        $this->queue1->enqueue($x);
    }

    /**
     * Removes the element on top of the stack and returns that element.
     * @return Integer
     */
    function pop()
    {
        while ($this->queue1->count() > 1) {
            $this->queue2->enqueue($this->queue1->dequeue());
        }

        $return = $this->queue1->dequeue();
        while (!$this->queue2->isEmpty()) {
            $this->queue1->enqueue($this->queue2->dequeue());
        }
        return $return;
    }

    /**
     * Get the top element.
     * @return Integer
     */
    function top()
    {
        return $this->queue1->top();
    }

    /**
     * Returns whether the stack is empty.
     * @return Boolean
     */
    function empty()
    {
        return $this->queue1->isEmpty() && $this->queue2->isEmpty();
    }
}
```
