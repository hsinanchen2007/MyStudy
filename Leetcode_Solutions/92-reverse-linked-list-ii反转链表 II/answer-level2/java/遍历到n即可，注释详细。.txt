### 解题思路
从链表头部遍历到n即可。
记录m的Node，以及m前一个node。
m->n之间的遍历，使用头插法。
### 代码

```java
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if(head == null || m == n){
            return head;
        }
        //返回节点
        ListNode ret = new ListNode(0);
        //m对应的节点
        ListNode mNode = null;
        //m对应的前一个节点 ， 若 m = 1 则指向返回的根结点 ret。
        ListNode mPreNode = m == 1 ? ret : null;
        ret.next = head;
        //记录链表的下标
        int num = 0; 
        //遍历到n即可
        while(num <= n){
            num++;
            //记录m的前一个节点
            if(num + 1 == m){
                mPreNode = head;
            }
            //到了m节点
            if(num == m){
                //记录m节点
                mNode = head;
                ListNode temp = head.next;
                head.next = null;
                head = temp;
                continue;
            }
            //m -> n节点之间的遍历。使用头插法，每次mPreNode指向当前节点。
            if(num > m && num < n){
                ListNode temp = head.next;
                head.next = mPreNode.next;
                mPreNode.next = head;
                head = temp;
                continue;
            }
            //到了节点n，mPreNode指向n的下一个节点。结束。
            if(num == n){
                ListNode temp = head.next;
                head.next = mPreNode.next;
                mPreNode.next = head;
                mNode.next = temp;
                break;
            }
            head = head.next ;
        }
        return ret.next;
    }
}
```

![D17D6AFF-9844-47E5-90CE-1DA0C9430F3C.png](https://pic.leetcode-cn.com/0d46d5031498c6384181b7248097e0e48cab1795e4233375131aceacfee6819d-D17D6AFF-9844-47E5-90CE-1DA0C9430F3C.png)
