### 解题思路

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
    public ListNode removeElements(ListNode head, int val) {
        ListNode header = head;  //返回值，头节点记录
        ListNode pre =null;      //当前节点的前一个节点
        ListNode cur = head;     //当前节点，初始节点为头节点
        while(null!=cur){
            if(cur.val == val ){   //节点命中
                if(null == pre){   //pre为null，说明前面没有节点或者前面的节点都被删除了
                    header = cur.next; //头节点重置
                    pre = null;        //pre节点重置
                }else{
                    pre.next=cur.next; //掐掉当前节点
                }
            }else{//节点未命中
                pre = cur;//pre指向当前节点
            }
            cur = cur.next;//指向下一个查找节点位置
        }
        return header;
    }
}
```