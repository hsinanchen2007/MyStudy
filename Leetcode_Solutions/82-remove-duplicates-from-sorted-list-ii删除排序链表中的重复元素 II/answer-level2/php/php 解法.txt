```
function deleteDuplicates($head) {
    if($head==null && $head->next==null) return $head;
    $curr = new ListNode(-1);
    $dummy = $curr;
    while($head!=null){
        $is_dup = false;// 判断是否是重复数字
        while($head->val === $head->next->val){//这里最好用全等号 0->0的情况会报错
            $head = $head->next;
            $is_dup = true;
        }
        if($is_dup==false){
            $curr->next = $head;
            $curr = $curr->next;
        }
        $head = $head->next;
    }
    $curr->next = null;// 例如1->2->2，断开用于断开后面的2->2 
    return $dummy->next;
}
```
