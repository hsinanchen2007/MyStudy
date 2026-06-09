### 1、递归
递归法，思路比较简单，如下。

```php
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val) { $this->val = $val; }
 * }
 */
class Solution {

    /**
     * @param ListNode $head
     * @return Integer[]
     */
    function reversePrint($head) {
        $return = [];
        $this->helper($head,$return);
        return $return;
    }

    function helper($head,&$return){
        if(!$head) return;
        $this->helper($head->next,$return);
        array_push($return,$head->val);
    }
}
```
### 2、辅助栈
遍历链表，将链表中元素push到栈中，利用栈先进后出的方式，实现链表的反转。
```php
class Solution {

    /**
     * @param ListNode $head
     * @return Integer[]
     */
    function reversePrint($head) {
        $stack = new SplStack();
        $return = [];
        while($head){
            $stack->push($head->val);
            $head = $head->next;
        }

        while(!$stack->isEmpty()){
            array_push($return,$stack->pop());
        }
        return $return;
    }
}
```