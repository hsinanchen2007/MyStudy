### 解题思路
使用PHP内置的SplMinHeap,PHP的最小堆，没有Size设置项，只能在代码中自己控制Size

### 代码

```php
class KthLargest {
    public $k = 0;
    public $heap = null;

    /**
     * @param Integer $k
     * @param Integer[] $nums
     */
    function __construct($k, $nums)
    {
        $this->k = $k;
        $this->heap = new SplMinHeap();
        foreach ($nums as $num) {
            $this->add($num);
        }
    }

    /**
     * @param Integer $val
     * @return Integer
     */
    function add($val)
    {
        if ($this->heap->isEmpty() || ($this->heap->count() < $this->k)) {
            $this->heap->insert($val);
            return $this->heap->top();
        }

        if ($this->heap->top() < $val) {
            $this->heap->extract();
            $this->heap->insert($val);
        }
        return $this->heap->top();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * $obj = KthLargest($k, $nums);
 * $ret_1 = $obj->add($val);
 */
```