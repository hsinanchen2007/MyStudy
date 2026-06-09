### 解题思路
![微信图片_20191204211303.png](https://pic.leetcode-cn.com/21be37a351c856207d47ec64346dbc4b4cdba6cf4230be72bca8bac7fb54cbda-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191204211303.png)

为什么分治的时间复杂度低？
什么时候用分治思想：如果输入子集的解决方案和全集是一样的，则可以考虑分治
对于一个算法时间复杂度是T(n),输入一半的时间复杂度是T(n/2)，那么
T(n)=2*T(n/2)+O(n)  O(n)是将两个子问题合并的时间复杂度
T(n)=4*T(n/4)+2*O(n/2)+O(n)
...
T(n)=O(n)+2*O(n/2)+...+logn*O(1)
T(n)=O(nlogn)

### 代码

```java
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length==0||lists==null) return null;
        if(lists.length==1) return lists[0];
        return div(lists,0,lists.length-1);
    }
    private ListNode div(ListNode[] lists,int start,int end)
    {
        if(start==end) return lists[start];
        if(start+1==end) return mergeTwoLists(lists[start],lists[end]);
        int mid=(start+end)/2;
        ListNode list1=div(lists,start,mid);
        ListNode list2=div(lists,mid+1,end);
        return mergeTwoLists(list1,list2);
    }
    private ListNode mergeTwoLists(ListNode l1,ListNode l2)
    {
        ListNode prehead = new ListNode(-1);
        ListNode prev = prehead;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                prev.next = l1;
                l1 = l1.next;
            } else {
                prev.next = l2;
                l2 = l2.next;
            }
            prev = prev.next;
        }
        prev.next = l1 == null ? l2 : l1;
        return prehead.next;
    }
}

```