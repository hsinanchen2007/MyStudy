### 解题思路
1. 入队的时候，直接入栈
2. 出队的时候，用另一个栈过一遍元素，再输出最后一个
3. 重新将缓存栈中的内容，压入原有栈内保存

### 代码

```php
class CQueue {

    private $stack1;
    private $stack2;

    /**
     */
    function __construct() {
        $this->stack1 = [];
        $this->stack2 = [];
    }

    /**
     * @param Integer $value
     * @return NULL
     */
    function appendTail($value) {
        array_push($this->stack1, $value);
    }

    /**
     * @return Integer
     */
    function deleteHead() {
        $count = count($this->stack1);

        if($count == 0) {
            // 栈为空时输出
            return -1;
        } else {

            // 用中间栈过一遍元素，负负得正
            for($i = 0; $i < $count - 1; $i++) {
                array_push($this->stack2, array_pop($this->stack1));
            }

            // 需要干掉的元素
            $tmp = array_pop($this->stack1);

            // 换源栈
            for($i = 0; $i < $count - 1; $i++) {
                array_push($this->stack1, array_pop($this->stack2));
            }

            return $tmp;
        }

    }
}
```