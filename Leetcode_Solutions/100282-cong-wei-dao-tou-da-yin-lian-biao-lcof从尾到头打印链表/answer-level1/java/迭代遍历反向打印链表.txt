### 解题思路
思路还是非常简单的。
暴力迭代链表，把数据放入 列表中，然后反向遍历链表，把数据放入数组中，
时间复杂度 O(n)
空间复杂度 O(n)

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int[] reversePrint(ListNode head) {
        if (head == null) return new int[0];
        List<Integer> list = new ArrayList<>();
        while (head !=  null){
            list.add(head.val);
            head = head.next;
        }
        //1,2,3,4
        int[] arr = new int[list.size()];
        int j = 0;
        for (int i=list.size()-1; i>=0; i--){
            arr[j++] = list.get(i);
        }
        return arr;
    }
}
```