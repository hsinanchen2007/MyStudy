### 解题思路

整体思路就是使用一个辅助栈来记录当前栈的最小值信息，可以使用等长和不等长两种辅助栈方式。

### 代码

```php
class MinStack
{
    protected $data;
    // 使用不等长的辅助栈
    protected $helper;
    /**
     * initialize your data structure here.
     */
    function __construct()
    {
        $this->data = new SplStack();
        $this->helper = new SplStack();
    }

    /**
     * @param Integer $x
     * @return NULL
     */
    function push($x)
    {
        $this->data->push($x);
        // 入栈时，值小于等于辅助栈栈顶元素时才入栈
        if ($this->helper->count() == 0 || $x <= $this->helper->top()) {
            $this->helper->push($x);
        }
    }

    /**
     * @return NULL
     */
    function pop()
    {
        $x = null;
        if ($this->data->count()) {
            $x = $this->data->pop();
        }
        // 出栈时，出栈元素等于辅助栈栈顶元素才出栈
        if (isset($x) && $this->helper->count() && $this->helper->top() == $x) {
            $this->helper->pop();
        }
    }

    /**
     * @return Integer
     */
    function top()
    {
        if ($this->data->count() == 0) {
            return null;
        }
        return $this->data->top();
    }

    /**
     * @return Integer
     */
    function getMin()
    {
        if ($this->helper->count() == 0) {
            return null;
        }
        return $this->helper->top();
    }
}
```