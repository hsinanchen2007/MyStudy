### 解题思路
递归获取所有值存入队列,在按照栈先进后出的策略

### 代码

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

        $data = [];
        $arr = [];

        while(!empty($head ))
        {
            $data[] = $head->val;
      
            $head = $head->next;
        }

        $len = count($data);
        
        for($i = $len - 1; $i >= 0; $i --)
        {
            $arr[] = $data[$i];
           
        }
        
        unset( $head , $len ,$data);
        
        return  $arr; 
    }
}
```