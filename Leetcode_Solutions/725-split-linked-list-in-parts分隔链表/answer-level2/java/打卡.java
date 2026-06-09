### 解题思路
    用数组保存，难点是计算数组大小

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
            //计算长度
            int N=0;
            ListNode cur=root;
            //计算间隔
            while(cur!=null){
                N++;
                cur=cur.next;
            }

            int mod=N%k;
            int size=N/k;
            //数组
            ListNode[] ret = new ListNode[k];
            //回头
            cur=root;
            //分隔
            for(int i=0;i<k&&cur!=null;i++){
                //赋值
                ret[i]=cur;
                //计算数组大小
                int retsize=size+(mod-->0?1:0);
                for(int j=0;j<retsize-1;j++){
                        cur=cur.next;
                }

                //接着剪断
                ListNode next=cur.next;
                cur.next=null;
                cur=next;



            }
        return ret;

    }
}
```