```php
class Solution
{
    // 对于一个测试用例，是唯一值
    protected $successor;
    /**
     * @param ListNode $head
     * @param Integer $m
     * @param Integer $n
     * @return ListNode
     */
    function reverseBetween($head, $m, $n)
    {
        if ($m == 1) {
            return $this->reverseN($head, $n);
        }

        $head->next = $this->reverseBetween($head->next, $m - 1, $n - 1);
        return $head;
    }

    // 递归函数的含义：传入一个链表和一个整数，反转链表的前 n 个节点，返回链表头节点
    private function reverseN($head, $n)
    {
        if ($n == 1) {
            $this->successor = $head->next;
            return $head;
        }

        $last = $this->reverseN($head->next, $n - 1);
        $head->next->next = $head;
        $head->next = $this->successor;

        return $last;
    }
}
```


## 测试用例

```php
class ListNode
{
    public $val = 0;
    public $next = null;
    function __construct($val)
    {
        $this->val = $val;
    }
}

$head = new ListNode(1);
$head->next = new ListNode(2);
$head->next->next = new ListNode(3);
$head->next->next->next = new ListNode(4);
$head->next->next->next->next = new ListNode(5);
$m = 2;
$n = 4;

$list = (new Solution())->reverseBetween($head, $m, $n);
while ($list) {
    echo $list->val . PHP_EOL;
    $list = $list->next;
}
```
