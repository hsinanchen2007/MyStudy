### 解题思路

这里是通过PHP数组配合了index来实现了栈的基本功能。效率可能不高，仅代表一种思路。

### 代码

```php
class MyStack {

    public $stack = [];
    protected $topIndex = -1;
    /**
     * Initialize your data structure here.
     */
    function __construct() {

    }

    /**
     * Push element x onto stack.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        $this->topIndex++;
        $this->stack[$this->topIndex] = $x;
    }

    /**
     * Removes the element on top of the stack and returns that element.
     * @return Integer
     */
    function pop() {
        if ($this->empty()) return false;
        $this->topIndex--;
        return $this->stack[$this->topIndex + 1];
    }

    /**
     * Get the top element.
     * @return Integer
     */
    function top() {
        if ($this->empty()) return false;
        return $this->stack[$this->topIndex];
    }

    /**
     * Returns whether the stack is empty.
     * @return Boolean
     */
    function empty() {
        return $this->topIndex === -1;
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