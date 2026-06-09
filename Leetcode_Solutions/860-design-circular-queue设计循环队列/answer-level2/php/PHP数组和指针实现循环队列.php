注:
1. 由于需要区分队列头和尾,队尾指针需要向后移动一位存储
2. 循环队列的最大特点是在队尾指针位置为空,顾循环队列里面会多存储一个空位置.队列可用大小为$k+1个
3. 判断队列是否为空很简单,只要头指针==尾指针就可以.但队列满时比较难理解,是($tail+1) % $count == $head;
```
class MyCircularQueue {
    private $count = 0;
    private $head = 0;
    private $tail = 0;
    private $arr = [];
    /**
     * Initialize your data structure here. Set the size of the queue to be k.
     * @param Integer $k
     */
    function __construct($k) {
        $this->count = $k+1;
    }

    /**
     * Insert an element into the circular queue. Return true if the operation is successful.
     * @param Integer $value
     * @return Boolean
     */
    function enQueue($value) {
        if ($this->isFull()) {
            return false;
        }
        $this->tail = ($this->tail + 1) % $this->count;
        $this->arr[$this->tail] = $value;
        return true;
    }

    /**
     * Delete an element from the circular queue. Return true if the operation is successful.
     * @return Boolean
     */
    function deQueue() {
        if ($this->isEmpty()) {
            return false;
        }
        $this->head = ($this->head + 1) % $this->count;
        return true;
    }

    /**
     * Get the front item from the queue.
     * @return Integer
     */
    function Front() {
        if ($this->isEmpty()) {
            return -1;
        } else {
            return $this->arr[$this->head+1];
        }
    }

    /**
     * Get the last item from the queue.
     * @return Integer
     */
    function Rear() {
        if ($this->isEmpty()) {
            return -1;
        } else {
            return $this->arr[$this->tail];
        }
    }

    /**
     * Checks whether the circular queue is empty or not.
     * @return Boolean
     */
    function isEmpty() {
        if ($this->head == $this->tail) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * Checks whether the circular queue is full or not.
     * @return Boolean
     */
    function isFull() {
        if ((($this->tail + 1) % $this->count) == $this->head) {
            return true;
        } else {
            return false;
        }
    }
}
```
