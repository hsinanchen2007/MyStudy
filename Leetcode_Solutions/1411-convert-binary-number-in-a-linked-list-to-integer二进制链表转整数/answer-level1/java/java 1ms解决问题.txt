java 1ms解决问题

```
class Solution {
    public int getDecimalValue(ListNode head) {
        List<Integer> list = new ArrayList<>();
        while (head != null) {
            list.add(head.val);
            head = head.next;
        }

        int sum = 0;
        for (int i=0; i<list.size(); i++) {
            sum += list.get(i) * Math.pow(2, list.size()-i-1);
        }
        return sum;
    }
}
```