### 解题思路
将链表中数复制到数组，然后排序后放入链表

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
        if(lists.length==0) return null;
        int count=0;

        //查询长度
        for(ListNode list : lists){
            while(list!=null){
                list = list.next;
                count++;
            }
        }
        int[] num= new int[count];
        int index = 0;
        //赋值到数组
        for(ListNode list : lists){
            while(list!=null){
                num[index++] = list.val;
                list = list.next;
                
            }
        }
        if(count==0) return null;

        Arrays.sort(num);
        ListNode li = new ListNode(num[0]);
        ListNode p = li;
        for(int i=1;i<num.length;i++){
            ListNode re = new  ListNode(num[i]);
            li.next = re;
            li = li.next;
            
        }
        return p;
    }
}
```