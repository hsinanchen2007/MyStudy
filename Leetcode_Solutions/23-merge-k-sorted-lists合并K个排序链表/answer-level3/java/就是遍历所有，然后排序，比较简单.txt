### 解题思路
就是遍历所有，然后排序，比较简单

### 代码

```java
/*
 * Author: xiaoweixiang
 */
import java.util.ArrayList;
import java.util.Arrays;

public class Solution {

    public ListNode mergeKLists(ListNode[] lists) {
        /**
         * 理解错误，这个很简单啊，先把所有的取出来，然后排序就好了
         */
        ArrayList<Integer> list = new ArrayList<Integer>();
        mergeKLists(lists, list);
        Integer[] array = new Integer[list.size()];
        array = list.toArray(array);
        Arrays.sort(array);
        ListNode head = null;
        ListNode node = null;
        boolean f = true;
        for (int i = 0; i < array.length; i++) {
            if (node == null) {
                node = new ListNode(array[i]);
                if (f) {
                    head = node;
                    f = false;
                }
            } else {
                node.val = array[i];
            }
            if (i != array.length - 1) {
                node.next = new ListNode(0);
                node = node.next;
            }
        }

        return head;
    }

    private void mergeKLists(ListNode[] lists, ArrayList<Integer> list) {
        for (ListNode listNode : lists) {
            while (listNode != null) {
                list.add(listNode.val);
                listNode = listNode.next;
            }
        }
    }
}
```