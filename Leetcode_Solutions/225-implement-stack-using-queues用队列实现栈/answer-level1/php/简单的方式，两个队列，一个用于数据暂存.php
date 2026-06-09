### 解题思路
此处撰写解题思路
两个队列，一个进行暂存数据

### 代码

```php
class MyStack {
    private $queue1;
    private $queue2;
    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->queue1 = new SplQueue();
        $this->queue2 = new SplQueue();
    }

    /**
     * Push element x onto stack.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        $this->queue1->push($x);
    }

    /**
     * Removes the element on top of the stack and returns that element.
     * @return Integer
     */
    function pop() {
        while ($this->queue1->count() != 1){
            $this->queue2->push($this->queue1->shift());
        }
        $result = $this->queue1->shift();
        while ($this->queue2->count() != 0){
            $this->queue1->push($this->queue2->shift());
        }

        return $result;

    }

    /**
     * Get the top element.
     * @return Integer
     */
    function top() {
        while ($this->queue1->count() != 1){
            $this->queue2->push($this->queue1->shift());
        }
        $result = $this->queue1->shift();
        $this->queue2->push($result);
        while ($this->queue2->count() != 0){
            $this->queue1->push($this->queue2->shift());
        }
        return $result;
    }

    /**
     * Returns whether the stack is empty.
     * @return Boolean
     */
    function empty() {
        if($this->queue1->count() == 0){
            return true;
        }
        return false;

    }
}
```