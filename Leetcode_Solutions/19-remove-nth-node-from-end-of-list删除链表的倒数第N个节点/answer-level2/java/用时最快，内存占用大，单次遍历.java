### 解题思路
此处撰写解题思路
第一次做题用时能破榜，太感动了。！！！！！！！
纯粹的内存换时间！！！

下面是我的解题思路
因为题目里要删除倒数第N个节点，所以我的思路就是把后面的N+1个节点用数组存起来，然后找到倒数第N+1个节点，之后做个节点删除就行

```
int base = n+1
ListNode[] tmpNodes = new ListNode[base];
```
构建的tmpNodes数组就是存节点的数组，然后第i个节点存储的位置就是 i%base,得到的就是其在数组中的位置
```java
int index = 0;
while(head != null){
    tmpNodes[index%base] = head;
    head = head.next;
    index++;
}
```
遍历一遍队列，并对数组上的每个数据附上值

```java
if(index<2){
    return null;
} else if (index==n){
    return tmpHead.next;
}
else{
    tmpNodes[(index)%base].next = tmpNodes[(index+1)%base].next;
    return tmpHead;
}
```
对于删除头节点和单个节点的删除拿出处理，对普遍删除用链表删除

谢谢参考！

### 下面是完整代码，刚开始学，比较拙劣，请见谅

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int base = n+1;
        ListNode[] tmpNodes = new ListNode[base];
        ListNode tmpHead = head;
        int index = 0;
        while(head != null){
            tmpNodes[index%base] = head;
            head = head.next;
            index++;
        }
        if(index<2){
            return null;
        } else if (index==n){
            return tmpHead.next;
        }
        else{
            tmpNodes[(index)%base].next = tmpNodes[(index+1)%base].next;
            return tmpHead;
        }
    }
}
```