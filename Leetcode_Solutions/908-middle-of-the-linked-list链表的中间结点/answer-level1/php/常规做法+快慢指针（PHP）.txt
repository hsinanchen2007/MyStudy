```
class Solution {

    /**
     * @param ListNode $head
     * @return ListNode
     */
    function middleNode($head) {
        $p = $head;
        $len = 0;
        while ($p != null) {
            $len++;
            $p = $p->next;
        }
        $p = $head;
        for ($i = 0; $i < floor($len / 2); ++$i) {
            $p = $p->next;
        }
        return $p;
    }

    function middleNode1($head) {
        $fast = $head;
        $slow = $head;
        while ($fast != null && $fast->next != null) {
            $fast = $fast->next->next;
            $slow = $slow->next;
        }
        return $slow;
    }
}
```
