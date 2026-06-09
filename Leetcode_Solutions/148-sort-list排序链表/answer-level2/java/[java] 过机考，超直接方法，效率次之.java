都是用了归并排序，这点无可厚非，非常清晰和直接；

但是为了通过机考，这块给一个超级简单的方式，当然效率就很次了，但保证通过用例：

```
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null) {
            return null;
        }

       ListNode input = head;
        List<Integer> origin = new ArrayList<>();
        while (input.next != null) {
            origin.add(input.val);
            input = input.next;
        }
        origin.add(input.val);

        Collections.sort(origin);

        ListNode result = head;
        for (Integer integer : origin) {
            ListNode temp = new ListNode(integer);
            result.val = temp.val;
            result = result.next;
        }

        return  head;
    }
```
