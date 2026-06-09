### 解题思路

直接上代码

### 代码

```php
class CQueue {
    protected $stackPush;
    protected $stackPop;
    /**
     */
    function __construct() {
        $this->stackPush = new SplStack();
        $this->stackPop = new SplStack();
    }

    /**
     * @param Integer $value
     * @return NULL
     */
    function appendTail($value) {
        $this->stackPush->push($value);
    }

    /**
     * @return Integer
     */
    function deleteHead() {
        if ($this->stackPop->isEmpty()) {
            $this->shift();
        }

        if ($this->stackPop->isEmpty()) return -1;
        return $this->stackPop->pop();
    }

    private function shift()
    {
        while (!$this->stackPush->isEmpty()) {
            $this->stackPop->push($this->stackPush->pop());
        }
    }
}
```