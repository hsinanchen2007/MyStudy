### 解题思路
利用红黑树组织k个排序序列的第一个节点的排序，然后每次取第一个，去完再把链表的下一个节点放入红黑树中，依次循环到红黑树为空即可。
应为存在相同的值，value使用了linkedlist。

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
    private void pushNode(TreeMap<Integer, LinkedList<ListNode>> treeMap,ListNode node)
    {
        LinkedList<ListNode> lst;
        if(!treeMap.containsKey(node.val))
            treeMap.put(node.val,new LinkedList<>());
        treeMap.get(node.val).add(node);
    }

    public ListNode mergeKLists(ListNode[] lists) {
        TreeMap<Integer, LinkedList<ListNode>> treeMap = new TreeMap<>();
        for (int i = 0; i < lists.length; i++) {
            if(lists[i]==null) continue;
            pushNode(treeMap,lists[i]);
        }
        ListNode head = new ListNode(0);
        ListNode cur = head;
        while (!treeMap.isEmpty()) {
            LinkedList<ListNode> lst = treeMap.firstEntry().getValue();
            treeMap.remove(treeMap.firstKey());
            while (!lst.isEmpty()){
                cur.next = lst.pop();
                cur = cur.next;
                if(cur.next!=null)
                    pushNode(treeMap,cur.next);
                cur.next=null;
            }
        }
        return head.next;
    }
}
```