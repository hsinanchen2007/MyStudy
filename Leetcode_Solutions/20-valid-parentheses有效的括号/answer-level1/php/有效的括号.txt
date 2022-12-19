### 解题思路
有效括号一定是成对的。左括号作为入栈，又括号作为压栈。

### 代码

```php
class Solution
{
    /**
     * 使用栈的方式
     *
     * @param String $s
     * @return Boolean
     */
    function isValid($s)
    {
        $arr = ['(' => ')', '[' => ']', '{' => '}'];
        $stack = new Stack();

        $i = 0;
        while (isset($s[$i])) {

            if (isset($arr[$s[$i]])) {
                $stack->push($s[$i]);
            } else {
                $val = $stack->pop($s[$i]);
                if ($val == null || $arr[$val] != $s[$i]) return false;
            }

            $i++;
        }

        // 如果栈中还有数据，则说明不成立
        if ($stack->pop() != null) return false;

        return true;
    }
}


class Node {

    public $val;
    public $next;

    public function __construct($val = null, $next = null)
    {
        $this->val = $val;
        $this->next = $next;
    }
}

class Stack {

    private $stack;

    public function __construct()
    {
        $this->stack = new Node();
    }

    public function push($val) {
        $node = new Node($val, $this->stack);
        $this->stack = $node;
    }

    public function pop() {
        if ($this->stack->next == null) return null;
        $val = $this->stack->val;
        $this->stack = $this->stack->next;
        return $val;
    }

    public function getStack() {
        return $this->stack;
    }
}

```