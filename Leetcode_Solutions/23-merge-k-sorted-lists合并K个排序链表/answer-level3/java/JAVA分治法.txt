## 解题思路
#### 时间上击败了99.30%
##### 内存击败52.00%
正好在学分治+java，拿这道题练练手

用分治法，思路比较简单，给这个链表序列两两分为一组，如果为奇数，就单独把最后一个作为一组，然后合并，每次待合并的链表都在这个lists的最前端。

每次需要处理的链表数用len记录即可，直到len=1为止，说明我们已经合并成了一个链表。

关于两两合并的代码，之前的题目里有现成的，直接套用即可。

只需要处理好合并前后的映射关系以及退出的边际条件就能成功ak。
## 代码

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
        int len = lists.length;//每次待处理的链表个数
        if(len==0)return null;//处理null

        while(len>1){
            int i;
            //两两合并，注意到这里将位置2i与2i+1的两个链表合并到位置i上。
            //如有不清楚的可以自己画个数组看看
            for( i = 0;i <len/2;i++){
                lists[i]=mergeTwoLists(lists[2*i],lists[2*i+1])   
            }
            //处理奇数的情况。把最后一个链表放到下次待求解数组的末端，顺便解决向上取整的问题
            if((len%2)!=0){
                lists[i]=lists[len-1];
                len++;
            }

            //规模减半
            len/=2;

        }

        return lists[0];
    }

    public  ListNode mergeTwoLists(ListNode l1,ListNode l2){
        ListNode head = new ListNode(-1);
        ListNode prev = head;
        while(l1!=null||l2!=null){
            if(l1==null){
                prev.next = l2;
                return head.next;
            }
            if(l2==null){
                prev.next = l1;
                return head.next;
            }
            if(l1.val<l2.val){
                prev.next = l1;
                l1 = l1.next;
            }
            else{
                prev.next = l2;
                l2 = l2.next;   
            }
                prev = prev.next;
        }
        
        return  head.next;
    }

    
}
```