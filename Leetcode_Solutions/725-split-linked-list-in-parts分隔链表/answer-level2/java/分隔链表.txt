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
    public ListNode[] splitListToParts(ListNode root, int k) {
        int n=0;
        ListNode cur=root;
        while(cur!=null)
        {
            n++;
            cur=cur.next;
        }
        int mod=n%k;
        int size=n/k;
        ListNode [] res=new ListNode[k];
        cur=root;
        for(int i=0;i<k&&cur!=null;i++){
            res[i]=cur;
            int cursize=size+(mod-->0? 1:0);
            for(int j=0;j<cursize-1;j++)
                cur=cur.next;
            ListNode next=cur.next;
            cur.next=null;
            cur=next;
        }
        return res;
    }
}
```