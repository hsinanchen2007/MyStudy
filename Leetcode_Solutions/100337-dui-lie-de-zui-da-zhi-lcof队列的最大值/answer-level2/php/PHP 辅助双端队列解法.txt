### 解题思路

添加一个辅助双端队列，PHP 中用数组模拟即可。

入队时，从双端队列队尾弹出所有小于当前值的元素

出队时，如果双端队列队头元素与出队元素值相同，一同出队

### 代码

```php
class MaxQueue
{
    private $queue;
    private $maxQueue;
    /**
     */
    function __construct()
    {
        $this->queue = new SplQueue();
        $this->maxQueue = [];
    }

    /**
     * @return Integer
     */
    function max_value()
    {
        if ($this->queue->isEmpty()) {
            return -1;
        }

        return reset($this->maxQueue);
    }

    /**
     * @param Integer $value
     * @return NULL
     */
    function push_back($value)
    {
        $this->queue->enqueue($value);
        while (!empty($this->maxQueue) && $value > end($this->maxQueue)) {
            array_pop($this->maxQueue);
        }

        array_push($this->maxQueue, $value);
    }

    /**
     * @return Integer
     */
    function pop_front()
    {
        if ($this->queue->isEmpty()) {
            return -1;
        }

        $result = $this->queue->dequeue();
        if (reset($this->maxQueue) == $result) {
            array_shift($this->maxQueue);
        }
        return $result;
    }
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * $obj = MaxQueue();
 * $ret_1 = $obj->max_value();
 * $obj->push_back($value);
 * $ret_3 = $obj->pop_front();
 */
```