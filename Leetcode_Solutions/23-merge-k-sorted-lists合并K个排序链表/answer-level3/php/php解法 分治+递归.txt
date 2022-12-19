以下两个方法都用到了21题《合并两个有序链表》的方法
解法一：逐一两两合并链表
这个方法很慢，还没优化好，不推荐
```
class Solution {

    /**
     * @param ListNode[] $lists
     * @return ListNode
     */
    function mergeKLists($lists) {
        if(count($lists)==0) return null;
        if(count($lists)==1) return $lists[0];
        
        $ans = $this->backtrack($ans,$lists);
        return $ans;
    }
    
    function backtrack($ans,&$lists){
        if(empty($lists)){
            return $ans;
        }
        $ans = $this->mergeTwoLists($ans, array_shift($lists));
        return $this->backtrack($ans,$lists);
    }
		
		function mergeTwoLists($l1, $l2) {
        if ($l1 == null) return $l2;
        if ($l2 == null) return $l1;
        if ($l1->val < $l2->val) {
            $l1->next = $this->mergeTwoLists($l1->next, $l2);
            return $l1;
        } else {
            $l2->next = $this->mergeTwoLists($l1,$l2->next);
            return $l2;
        }
    }
}
```

解法二：分治+递归
```
class Solution {

    /**
     * @param ListNode[] $lists
     * @return ListNode
     */
    function mergeKLists($lists) {
        if(count($lists)==0) return null;
        if(count($lists)==1) return $lists[0];
        if(count($lists)==2) return $this->mergeTwoLists($lists[0], $lists[1]);
        
        $mid = floor(count($lists)/2);
        $l1 = [];
        for($i=0;$i<$mid;$i++){
            $l1[$i] = $lists[$i];
        }
        $l2 = [];
        for($i = $mid,$j=0; $i < count($lists); $i++,$j++){
            $l2[$j] = $lists[$i];
        }
        return $this->mergeTwoLists($this->mergeKLists($l1),$this->mergeKLists($l2));
    }
    
    function mergeTwoLists($l1, $l2) {
        if ($l1 == null) return $l2;
        if ($l2 == null) return $l1;
        if ($l1->val < $l2->val) {
            $l1->next = $this->mergeTwoLists($l1->next, $l2);
            return $l1;
        } else {
            $l2->next = $this->mergeTwoLists($l1,$l2->next);
            return $l2;
        }
    }
}
```



