解法一：双指针
```
function plusOne($head) {
    $slow = new ListNode(0);
    $slow->next = $head;
    $fast = $head;
    while($fast != null){
        if($fast->val != 9) $slow = $fast;
        $fast = $fast->next;
    }
    $slow->val++;
    $cur = $slow->next;
    while($cur != null){
        $cur->val = 0;
        $cur = $cur->next;
    }
    return $slow->next==$head?$slow:$head;
}
```
解法二：先翻转再计算再翻转（略）
