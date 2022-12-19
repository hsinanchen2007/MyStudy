### 解题思路
主要思路就是折半合并
空间复杂度O(1)，就在原数组上操作，仅仅是换掉脚标

时间复杂度是O(log N)，每次都折半合并

具体做法就是按照脚标不停的除以2，然后更换数组的开头脚标和结尾脚标

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
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0){
            return null;
        }
        if(lists.length == 1){
            return lists[0];
        }
        return partMerge(lists,0,lists.length-1);
    }

    private ListNode partMerge(ListNode[] lists, int begin, int end){

        if(end == (begin+1)){
            return merge2Lists(lists[begin],lists[end]);
        }
        if(end <= begin){
            return lists[begin];
        }
        int left_tail = (end+begin) / 2;
        int right_head = left_tail + 1;
        ListNode leftNode = partMerge(lists,begin,left_tail);
        ListNode rightNode = partMerge(lists,right_head,end);
        return merge2Lists(leftNode,rightNode);
    }

    private ListNode merge2Lists(ListNode node1, ListNode node2){
        ListNode root = new ListNode(0);
        ListNode nextNode = root;
        while(node1 !=null  || node2 != null){
            if(node1 == null){
                nextNode.next = node2;
                break;
            }
            if(node2 == null){
                nextNode.next = node1;
                break;
            }
            int a = node1.val;
            int b = node2.val;
            if(a < b){
                nextNode.next = node1;
                node1 = node1.next;
            }else{
                nextNode.next = node2;
                node2 = node2.next;
            }
            nextNode = nextNode.next;
        }
        return root.next;
    }
}
```