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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        //1 把所有数据放入list
        List<Integer> ee = new ArrayList<>();
        ListNode one = l1;
        ListNode two = l2;
        while(true){
            if(one != null){
               ee.add(one.val);
               one = one.next;
            }
            if(two != null){
               ee.add(two.val);
               two = two.next;
            }
            if(two == null && one == null){
               break;
            }
        }
        //2 排序
        Collections.sort(ee);
        ListNode tempListNode = null;
        ListNode firstNode = null;
        //3 构建新的ListNode
        for(int x : ee){
            ListNode node = new ListNode(x);
            if(tempListNode != null){
                tempListNode.next = node;
            }else{
                firstNode = node;
            }
            tempListNode = node;
        }

        return firstNode;
        
    }
}
```