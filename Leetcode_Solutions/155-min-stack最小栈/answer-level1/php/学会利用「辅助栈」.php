**辅助栈**
`辅助栈` 是在 `栈` 数据结构中常常使用的一种算法解决思路，利用 `辅助栈` 与 `主栈` 元素的 `逻辑关系`，运算来求解

**思路**
- 初始化两个空栈，一个 `主栈`，用于 `保存栈中的所有元素`，`辅助栈栈顶永远保存主栈中最小的元素`
- 入栈 push(x): `主栈` 将元素 `入栈`，`辅助栈` 将入栈元素与自身栈顶元素进行 `对比`，若栈顶元素 `小于` 入栈元素，将 `栈顶` 元素再次 `入栈到辅助栈`；若栈顶元素 `大于等于` 入栈元素，则将元素`入栈辅助栈`。两个栈的元素个数分别加一
- 出栈 pop(x): 主栈和辅栈都将栈顶元素删除，元素个数减一
- 获取栈顶元素 top(x): 获取主栈栈顶元素
- getMin(): 返回 `辅栈栈顶` 元素

**注意**
- 保证 `两个栈` 的元素 `个数` 是 `相同` 的
- `辅栈栈顶` 元素永远和主栈中 `最小元素` 相同

**代码**

```php
class MinStack {

    // 主栈
    private $stack;
    
    // 辅助栈
    private $helper;
    
    // 主栈元素个数
    private $len;
    
    // 辅助栈元素个数
    private $h_len;
    
    function __construct()
    {
        $this->stack = [];
        $this->helper = [];
        $this->len = 0;
        $this->h_len = 0;
    }
  
    function push($x)
    {
        $this->stack[] = $x;
        $this->len++;
        if (empty($this->helper) || $this->helper[$this->h_len - 1] >= $x) {
            // 辅助栈为空，或辅助栈的栈顶元素大于等于入栈元素
            $this->helper[] = $x;
            $this->h_len++;
        } else {
            // 辅助栈不为空，入栈元素不小于主栈栈顶元素，将辅栈栈顶元素再次入栈
            $this->helper[] = $this->helper[$this->h_len - 1];
            $this->h_len++;
        }
    }
  
    /**
     * @return NULL
     */
    function pop()
    {
        if ($this->len > 0) {
            array_pop($this->stack);
            array_pop($this->helper);
            $this->len--;
            $this->h_len--;
            return true;
        }
        throw new Exception('栈中元素为空，操作非法');
    }

    function top()
    {
        if ($this->len > 0) {
            return $this->stack[$this->len - 1];
        }
        throw new Exception('栈中元素为空，操作非法');
    }

    /**
     * 时间复杂度 O(1)
     * 空间复杂度 O(1)
     */
    function getMin()
    {
        if ($this->h_len > 0) {
            return $this->helper[$this->h_len - 1];
        }
        throw new Exception('栈中元素为空，操作非法');
    }
}
```