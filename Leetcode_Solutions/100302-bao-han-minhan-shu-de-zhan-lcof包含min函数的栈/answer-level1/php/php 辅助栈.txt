### 解题思路
此处撰写解题思路
栈的经典解题，对于栈的理解很有帮助，如果是简单的栈，按照push,pop操作即可。本文要求增加了最小查询且为O(1),则需要我们增加辅助栈，辅助栈的目的是创建一个自顶向下递增的栈，即top为最小值。这样，在栈里进行操作时，需要判断当前值与辅助栈里top值比较
### 代码

```php
class MinStack {
    public $arr1 = [];
    public $arr2 = [];
    /**
     * initialize your data structure here.
     */
    function __construct() {
        
    }
  
    /**
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        $this->arr1[] = $x;
        if (empty($this->arr2)) {
            $this->arr2[] = $x;
        } elseif ($this->arr2[count($this->arr2) - 1] >= $x) {
            $this->arr2[] = $x;
        }
    }
  
    /**
     * @return NULL
     */
    function pop() {
        $x = array_pop($this->arr1);
        if ($x == $this->min()) {
            array_pop($this->arr2);
        }
    }
  
    /**
     * @return Integer
     */
    function top() {
        return $this->arr1[count($this->arr1) - 1];
    }
  
    /**
     * @return Integer
     */
    function min() {
        return $this->arr2[count($this->arr2) - 1]; 
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