### 解题思路
由于PHP中没有list类型，所有用数组来充当 list。为了模拟队列的先进先出，我们使用了 array_shift() 函数来弹出元素。

### 压入
在压入元素的时候，直接追加到 q1 后面即可，再将 top 的值复制为刚压入的值。

### 弹出
在弹出的时候，我们需要先将索引为 1 到 n-1 的元素从 q1 中弹出并压入到 q2 中，并将弹出的值设置为 top。然后再将索引为 0 的元素弹出。然后将 q1 和 q2 的值交换，并判断 q1 是否为空，如果 q1 为空，则将 top 也设置为空。

### 代码

```php
class MyStack {
    public $q1 = [];
    public $q2 = [];
    public $top;

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
        $this->top = $x;
    }

    /**
     * Removes the element on top of the stack and returns that element.
     * @return Integer
     */
    function pop() {
        while (count($this->q1) > 1) {
            $this->top = array_shift($this->q1);
            $this->q2[] = $this->top;
        }
        $value = array_shift($this->q1);
        $temp = $this->q1;
        $this->q1 = $this->q2;
        $this->q2 = $temp;
        if (count($this->q1) <= 0) $this->top = null;
        return $value;
    }

    /**
     * Get the top element.
     * @return Integer
     */
    function top() {
        return $this->top;
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