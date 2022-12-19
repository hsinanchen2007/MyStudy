### 解题思路
每次迭代函数中只处理head和head->next交换问题，并将交换结果返回。
1[2[3[4]]]经过两次迭代完成
思路：
一，不满足交换条件，返回head本身。
二，取head->next（2[3[4]]）为next备用，因为下一步head->next内容会被覆盖。
三，head->next内容被swapPairs(3[4])的返回替换成(4[3]),是第二次迭代做的。
四，next->next = head；(2[3[4]] 中的 3[4] 被替换成 1[head->next])。
五，最终两次迭代拼接成2[1[4[3]]]。
### 代码

```php
class Solution {
    /**
     * @param ListNode $head
     * @return ListNode
     */
    function swapPairs($head) {
        if (null == $head || null == $head->next) return $head;//不正经的代码，不推荐
        $next = $head->next;//next:备份head->next 
        $head->next = $this->swapPairs($next->next);//head->next承接来自下次交换的结果
        $next->next = $head;//当前head后移
        return $next;
    }
}
```