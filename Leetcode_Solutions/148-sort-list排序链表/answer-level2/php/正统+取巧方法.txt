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
    function sortList($head) {
        if($head==null){return $head;}
        return $this->mergeSort($head);
    }

    public function mergeSort($head) {
                //回归条件
        if ($head->next == null) {
            return $head;
        }
        //快指针,考虑到链表为2时的情况，fast比slow早一格
        $fast = $head->next;
        //慢指针
        $slow = $head;

        //快慢指针开跑
        while ($fast != null && $fast->next != null) {
            $fast = $fast->next->next;
            $slow = $slow->next;
        }
        
        //找到右子链表头元素
        $tail = $slow->next;
        //将中点后续置空，切割为两个子链表
        $slow->next=null;
        //递归分解左子链表,得到新链表起点
        $head=$this->mergeSort($head);
        //递归分解右子链表,得到新链表起点
        $tail=$this->mergeSort($tail);
        
        //并归两个子链表
        return $this->merge($head, $tail);
    }
    
    private function merge($l1, $l2) {
        $sentry = new ListNode(-1);
        $curr = $sentry;

        while ($l1 != null && $l2 != null) {
            if ($l1->val < $l2->val) {
                $curr->next = $l1;
                $l1 = $l1->next;
            } else {
                $curr->next = $l2;
                $l2 = $l2->next;
            }

            $curr = $curr->next;
        }

        $curr->next = $l1 != null ? $l1 : $l2;
        return $sentry->next;
    }

}
```

取巧办法 100% 100%
```php
class Solution {
    function sortList($head) {
        $arr = [];
        $p = $head;
        while ($p) {
            $arr[] = $p->val;
            $p = $p->next;
        }
        sort($arr);//直接把数字排序
        $p = $head; 
        $i = 0;
        while ($p) {//跟着把数字直接替换
            $p->val = $arr[$i++];
            $p = $p->next;
        }
        return $head;
    }
}
```