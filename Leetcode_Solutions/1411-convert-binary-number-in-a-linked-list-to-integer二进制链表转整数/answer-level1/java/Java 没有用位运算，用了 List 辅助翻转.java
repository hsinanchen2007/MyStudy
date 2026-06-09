最直观的想法，将链表中的元素放入 List 中，然后每一位乘上 2 的幂，即可
```
class Solution {
    public int getDecimalValue(ListNode head) {
        int res = 0;
        List<Integer> list = new ArrayList<>();
        ListNode curr = head;
        while (curr != null){
            list.add(0,curr.val);
            curr = curr.next;
        }
        int index = 0;
        for (int num : list){
            res += num * Math.pow(2,index);
            index++;
        }
        return res;
    }
}
```
