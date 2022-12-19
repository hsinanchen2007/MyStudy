### 解题思路
双队列存储，将data1出队推入data2做临时存储，获取到pop或top的数据后再将data2的数据推回data1中,
如果data2不回推到data1，在入队及出队时需要进行判断

拓展：可以用循环队列，shift之后直接push也可以

### 代码

```php
class MyStack {

    public $data1;
    public $data2;

    /**
     * Initialize your data structure here.
     */
    function __construct() {
        $this->data1 = [];
        $this->data2 = [];
    }

    /**
     * Push element x onto stack.
     * @param Integer $x
     * @return NULL
     */
    function push($x) {
        array_push($this->data1, $x);
    }

    /**
     * Removes the element on top of the stack and returns that element.
     * @return Integer
     */
    function pop() {
    	if (!empty($this->data1)) {
    		$len = count($this->data1);
    		for ($i=0; $i < $len - 1; $i++) { 
    			array_push($this->data1, array_shift($this->data1));
    		}
    		$res = array_shift($this->data1);
    		var_dump($res);
    		while (!empty($this->data2)) {
    			array_push($this->data1, array_shift($this->data2));
    		}
    		return $res;
    	}
    	return null;
    }

    /**
     * Get the top element.
     * @return Integer
     */
    function top() {
    	if (!empty($this->data1)) {
    		$len = count($this->data1);
    		for ($i=0; $i < $len - 1; $i++) { 
    			array_push($this->data1, array_shift($this->data1));
    		}
    		$res = array_shift($this->data1);
    		while (!empty($this->data2)) {
    			array_push($this->data1, array_shift($this->data2));
    		}
    		array_push($this->data1,$res);
    		return $res;
    	}
    	return null;
    	return null;
    }

    /**
     * Returns whether the stack is empty.
     * @return Boolean
     */
    function empty() {
    	return empty($this->data1) ? true : false;
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