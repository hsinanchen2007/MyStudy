### 解题思路
此处撰写解题思路

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
			ArrayList<Integer> list = new ArrayList();
            if (head == null) {
				return new int[]{};
			}
			list.add(head.val);
			while (head.next!=null){
				list.add(head.next.val);
				head.next = head.next.next;
			}
			ArrayList<Integer> newList = new ArrayList();
			int[] temp = new int[list.size()];
			for (int i = list.size()-1; i >=0 ; i--) {
				newList.add(list.get(i));
			}
			for (int i = 0; i < newList.size(); i++) {
				temp[i] = newList.get(i);
			}
			return temp;
    }
}
```