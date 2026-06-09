### 解题思路
同步辅助栈更易理解，只是占用空间大些

```
执行用时 :28 ms, 在所有 PHP 提交中击败了97.46%的用户
内存消耗 :22.5 MB, 在所有 PHP 提交中击败了16.18%的用户
```

### 代码

```php
class MinStack {

	protected $data;
	protected $help;

    /**
     * initialize your data structure here.
     */
    function __construct() {
        $this->data = new SplStack();
        $this->help = new SplStack();
    }
  
    /**
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        $this->data->push($x);
        if($this->help->count() == 0 || $x <= $this->help->top()) {
        	$this->help->push($x);
        } else {
        	$this->help->push($this->help->top());
        }
    }
  
    /**
     * @return NULL
     */
    function pop() {
        $this->data->pop();
        $this->help->pop();
    }
  
    /**
     * @return Integer
     */
    function top() {
        return $this->data->top();
    }
  
    /**
     * @return Integer
     */
    function getMin() {
        return $this->help->top();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * $obj = MinStack();
 * $obj->push($x);
 * $obj->pop();
 * $ret_3 = $obj->top();
 * $ret_4 = $obj->getMin();
 */
```