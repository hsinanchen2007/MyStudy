### 使用数组来实现
1. 使用一个数组来存储队列的元素，数组的容量为队列容量 + 1，这里有意浪费一个位置
2. 使用一个变量标记队列头，一个变量标记队列尾的下一个位置
3. 重点是其中的几个取模运算

```php
class MyCircularDeque
{
    protected $queue;
    protected $capacity;
    protected $head;
    protected $tail;
    /**
     * Initialize your data structure here. Set the size of the deque to be k.
     * @param Integer $k
     */
    function __construct($k)
    {
        $this->capacity = $k + 1;
        $this->queue = array_fill(0, $this->capacity, null);
        $this->head = 0;
        // tail 指下一个插入元素的位置
        $this->tail = 0;
    }

    /**
     * Adds an item at the front of Deque. Return true if the operation is successful.
     * @param Integer $value
     * @return Boolean
     */
    function insertFront($value)
    {
        if ($this->isFull()) {
            return false;
        }

        $this->head = ($this->head - 1 + $this->capacity) % $this->capacity;
        $this->queue[$this->head] = $value;
        return true;
    }

    /**
     * Adds an item at the rear of Deque. Return true if the operation is successful.
     * @param Integer $value
     * @return Boolean
     */
    function insertLast($value)
    {
        if ($this->isFull()) {
            return false;
        }

        $this->queue[$this->tail] = $value;
        $this->tail = ($this->tail + 1) % $this->capacity;
        return true;
    }

    /**
     * Deletes an item from the front of Deque. Return true if the operation is successful.
     * @return Boolean
     */
    function deleteFront()
    {
        if ($this->isEmpty()) {
            return false;
        }

        $this->head = ($this->head + 1) % $this->capacity;
        return true;
    }

    /**
     * Deletes an item from the rear of Deque. Return true if the operation is successful.
     * @return Boolean
     */
    function deleteLast()
    {
        if ($this->isEmpty()) {
            return false;
        }

        $this->tail = ($this->tail - 1 + $this->capacity) % $this->capacity;
        return true;
    }

    /**
     * Get the front item from the deque.
     * @return Integer
     */
    function getFront()
    {
        if ($this->isEmpty()) {
            return -1;
        }

        return $this->queue[$this->head];
    }

    /**
     * Get the last item from the deque.
     * @return Integer
     */
    function getRear()
    {
        if ($this->isEmpty()) {
            return -1;
        }

        return $this->queue[($this->tail - 1 + $this->capacity) % $this->capacity];
    }

    /**
     * Checks whether the circular deque is empty or not.
     * @return Boolean
     */
    function isEmpty()
    {
        return $this->head == $this->tail;
    }

    /**
     * Checks whether the circular deque is full or not.
     * @return Boolean
     */
    function isFull()
    {
        return ($this->tail + 1 + $this->capacity) % $this->capacity == $this->head;
    }

    public function dump()
    {
        if ($this->isEmpty()) {
            return '';
        }

        echo 'head: ' . $this->head . PHP_EOL;
        echo 'tail: ' . $this->tail . PHP_EOL;
        echo implode(',', $this->queue) . PHP_EOL;
        $return = 'head';
        $i = $this->head;
        while (true) {
            $return .= '->' . $this->queue[$i];
            $i = ($i + 1) % $this->capacity;
            if ($i == $this->head) {
                break;
            }
        }
        $return .= '->tail------------------------------------';
        return $return;
    }
}
```
