### 解题思路
太久不做题，刚开始浪费了好多时间，后来看过提示（唉），还是做出来了

```php []
class Solution {

    /**
     * @param ListNode $head
     * @return ListNode
     */
    function reverseList($head) {
        $pre = null;
        $cur = $head;
        while($cur!=null){
            $temp = $cur->next;
            $cur->next = $pre;
            $pre = $cur;
            $cur = $temp;
        }
        return $pre;

    }
}
```

