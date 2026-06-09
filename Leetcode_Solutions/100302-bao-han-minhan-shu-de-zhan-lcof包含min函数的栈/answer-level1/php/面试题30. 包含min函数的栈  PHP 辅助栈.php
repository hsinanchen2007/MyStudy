### 解题思路
1. 栈的实现没有问题，维持栈顶 cur 即可
2. 辅助栈 min 保存到当前元素位置(包含当前元素)的最小值

### 代码

```php
class MinStack {

    private $stack;
    private $cur;
    private $min;

    /**
     * initialize your data structure here.
     */
    function __construct() {
        $this->stack = [];
        $this->cur = 0;
        $this->min = null;
    }

    /**
     * @param Integer $x
     * @return NULL
     */
    function push($x) {

        $this->stack[$this->cur] = $x;

        // 辅助栈 min 保存到当前元素位置(包含当前元素)的最小值
        if($this->cur == 0 || $x < $this->min[$this->cur - 1]) {
            $this->min[$this->cur] = $x;
        } else {
            $this->min[$this->cur] = $this->min[$this->cur - 1];
        }

        $this->cur += 1;
    }

    /**
     * @return NULL
     */
    function pop() {
        unset($this->stack[--$this->cur]);
        unset($this->min[$this->cur]);
    }

    /**
     * @return Integer
     */
    function top() {
        return  $this->stack[$this->cur - 1];
    }

    /**
     * @return Integer
     */
    function min() {
        return $this->min[$this->cur - 1];
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * $obj = MinStack();
 * $obj->push($x);
 * $obj->pop();
 * $ret_3 = $obj->top();
 * $ret_4 = $obj->min();
 */
```