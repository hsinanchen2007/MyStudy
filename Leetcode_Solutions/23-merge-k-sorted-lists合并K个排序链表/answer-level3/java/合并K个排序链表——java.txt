### 解题思路
此处撰写解题思路
遍历所有非空链表的表头，
取出其中最小的值，
直到所有链表为空。
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
    ListNode listNode;
    int len;
    boolean b = true;
    ListNode[] list;
    public ListNode mergeKLists(ListNode[] lists) {
        listNode = new ListNode(0);
        ListNode ans = listNode;
        len = lists.length;
        this.list = lists;
        if(len==0){
            return null;
        }else if(len==1) {
            return lists[0];
        }else if(!flag()){
            return null;
        }
        helper();
        return ans;
    }

    public void helper(){
        int value = Integer.MAX_VALUE;
        int value_index = 0;
        for(int i=0;i<len;i++){
            if(list[i]!=null){
                if(list[i].val<value){
                    value = list[i].val;
                    value_index = i;
                }
            }else {
                continue;
            }
        }
        listNode.val = value;
        list[value_index] = list[value_index].next;
        if(flag()){
            listNode.next = new ListNode(0);
            listNode = listNode.next;
            helper();
        }
    }

    public boolean flag(){
        for(ListNode l:list){
            if(l!=null){
                return true;
            }
        }
        b = false;
        return false;
    }
}
```