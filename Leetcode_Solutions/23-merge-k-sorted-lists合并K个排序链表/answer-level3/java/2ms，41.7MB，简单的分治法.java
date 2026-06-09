### 解题思路
思路：分治法，也就是两两比较，然后合并为1个。最终所有链表也会成一个
     * 1.定义一个len，代表当前链表数组的最大长度，如果len>1，说明还需接着合并。mergeTwoLists方法就是合并两个链表，和No21一样
     * 2.第2*i个链表和第2*i+1个链表合并后放在第i的位置上
     * 如：0 1 2 3 4
     * 当i=0，2*i=0，2*i+1=1，0和1合并，结果放到0上
     * 当i=1，2*i=2，2*i+1=3，2和3合并，结果放到1上
     * i最大等于1，也就是5/2=2,i<2.此时len是奇数，所以4当作一个结果放到len/2=2的位置上，记得len++，不然len/=2会把最后一个结果过滤掉
     * len/=2后len=3，正好符合当前的情景，在while循环下，接着刚才的动作。

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
        int len=lists.length;
        if(len==0) return null;
        while (len>1){
            for(int i=0;i<len/2;i++){
                lists[i]=mergeTwoLists(lists[2*i],lists[2*i+1]);
            }
            if(len%2==1) {
                lists[len / 2] = lists[len - 1];
                len++;//如果为奇数，加一是为了后面除以2多1，这样就可以包含这个最后一个listnode
            }
            len/=2;
        }
        return lists[0];
    }
    private ListNode mergeTwoLists(ListNode node1,ListNode node2){
        ListNode newnode=new ListNode(-1);
        ListNode copynode=newnode;
        while (node1!=null&&node2!=null){
            if(node1.val>node2.val){
                newnode.next=node2;
                node2=node2.next;
            }else {
                newnode.next=node1;
                node1=node1.next;
            }
            newnode=newnode.next;
        }
        newnode.next=node1==null?node2:node1;
        return copynode.next;
    }
}
```