### 解题思路
此处撰写解题思路

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
     * @return ListNode
     */
    function removeDuplicateNodes($head) {
      
      $cur = $head;
      $arr = [$head->val];
  
      while($cur->next)
      {
          if(in_array($cur->next->val,$arr))
          {
              $cur->next = $cur->next->next;
               
          }else{
              $arr[] = $cur->next->val;
              $cur = $cur->next;
           
          }

      }
      return $head;
        


    }
}
```