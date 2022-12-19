### 解题思路
小弟不才，写了这么多的内容才实现这个操作。看了大佬的题解才明白，快慢指针才是打开这个提的正确方式~

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
    public ListNode middleNode(ListNode head) {

        if(head==null){
            return head;
        }

        int dept = dfs(head, 1);
        int middle;
        if (dept % 2 == 0) {
            middle = dept / 2+1;
        } else {
            middle = (dept+1) / 2;
        }

        return getMiddleNode(head,middle);
    }

    private static ListNode getMiddleNode(ListNode head, int middle) {
        ListNode  middleNode = head;
        ListNode temp = head;
        for (int i = 1; i < middle; i++) {
            temp = temp.next;
            if(i==middle-1){
                middleNode = temp;
                break;
            }
        }
        return middleNode;
    }

    private static int dfs(ListNode head, int dept) {
        if (head.next == null) {
            return dept;
        }
        return dfs(head.next, ++dept);
    }
    }
```