### 解题思路

核心在于 push 方法中的 `for ($i = count($this->q1) - 1; $i >= 1; $i--) {}`, 我们每次都只遍历当前数组长度 -1 次，也就是说，我们把刚添加到数组中的元素左边的所有元素都删除重新追加到了其右边。

### 代码

```php
class MyStack {
    public $q1 = [];

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
        $this->q1[] = $x;
        for ($i = count($this->q1) - 1; $i >= 1; $i--) {
            $this->q1[] = array_shift($this->q1);
        }
    }

    /**
     * Removes the element on top of the stack and returns that element.
     * @return Integer
     */
    function pop() {
        return array_shift($this->q1);
    }

    /**
     * Get the top element.
     * @return Integer
     */
    function top() {
        return count($this->q1) > 0 ? $this->q1[0] : null; 
    }

    /**
     * Returns whether the stack is empty.
     * @return Boolean
     */
    function empty() {
        return count($this->q1) <= 0;
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