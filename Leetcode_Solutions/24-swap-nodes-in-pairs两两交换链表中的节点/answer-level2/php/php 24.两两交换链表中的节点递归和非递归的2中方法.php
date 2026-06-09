### 解题思路
此处撰写解题思路
用了快慢2个指针，然后进行前后2个节点进行交换。注意结束的条件
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
    function swapPairs($head) {
        $shard = new ListNode(0);
        $shard->next = $head;
        $slow = $head;
        $fast = $head->next;

        while ($slow != null && $fast != null) {
            //交换slow 和 fast
            $tmp = $slow->val;
            $slow->val = $fast->val;
            $fast->val = $tmp;

            if ($fast->next == null) {
                $fast = null;
            } elseif ($fast->next->next == null) {
                $fast = null;
            } else {
                $fast = $fast->next->next;
                $slow = $slow->next->next;
            }
        }


        //或者下面，2者思路是一样的
        //while ($head != null && $head->next != null) {
        //    $next = $head->next;
        //    $tmp = $head->val;
        //    $head->val = $next->val;
        //    $next->val = $tmp;
        //    $head = $next->next;
        }

        return $shard->next;
    }
}
```

# 递归的重点
1.结束条件
2.递的方法，入口
3.归的方法，出口 

抓住上面三点就可以完成一个递归
刚开始的时候，需要多思考，总结，可以模拟只有几个点，在纸上画出来代码运行的过程

递归写法
```
    function swapPairs($head)
    {
        if ($head == null || $head->next == null) {
            return $head;
        }

        $next = $head->next;
        $head->next = $this->swapPairs($next->next);
        $next->next= $head;
        return $next;
    }
```



