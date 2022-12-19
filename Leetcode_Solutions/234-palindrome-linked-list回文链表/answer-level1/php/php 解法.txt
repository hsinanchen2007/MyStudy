将链表看成数字，如1->2->3看成两组数字123和321，如果是回文链表，则两组数字相等。
当然这种解法讨巧了，也有可能数字溢出。
```
function isPalindrome($head) {
    $s1 = $s2 = 0;
    $t = 1;
    while($head != null){
        $s1 = $s1*10 + $head->val;
        $s2 = $s2 + $t*$head->val;
        $t *= 10;
        $head = $head->next;
    }
    return $s1==$s2;
}
```
