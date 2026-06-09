数组实现的顺序栈
```
class MinStack {
    private $arr = null;
    private $count = 0;
    /**
     * initialize your data structure here.
     */
    function __construct() {
        $this->arr = [];
    }

    /**
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        $this->arr[] = $x;
        $this->count++;
    }

    /**
     * @return NULL
     */
    function pop() {
        array_pop($this->arr);
        $this->count--;
    }

    /**
     * @return Integer
     */
    function top() {
        return $this->arr[$this->count-1];
    }

    /**
     * @return Integer
     */
    function getMin() {
        return min($this->arr);
    }
}

```
