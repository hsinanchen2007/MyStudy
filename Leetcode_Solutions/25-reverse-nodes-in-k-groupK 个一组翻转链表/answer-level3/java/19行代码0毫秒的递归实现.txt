### 解题思路
最简短代码实现，值考虑k个单元的实现，多余的放入递归中进行处理。
通过循环获取出k个单元放入数组中，并得到长度（可能小于或等于k）
小于k则直接返回下标0,等于k则按照数组进行逆序重新连接,连接后将下标0（新的尾节点）与递归结果相连
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

    public ListNode reverseKGroup(ListNode head, int k) {
        if(k==1){
            return head;
        }
        ListNode []list = new ListNode[k];
        int len = 0;
        for(;len<k && head!=null;len++) {
        	list[len] = head;
        	head = head.next;
        }
        if(len<k) {
        	return list[0];
        }else {
        	for(int i=k-1;i>0;i--) {
        		list[i].next = list[i-1];
        	}
        	list[0].next=reverseKGroup(head,k);
        	return list[k-1];
        }
    }


}
```