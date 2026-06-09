![image.png](https://pic.leetcode-cn.com/b78a4d81a8a7b887ae1dd060ee896dfb489ed4b2c0390783401ea52440b6d751-image.png)

### 解题思路
详见代码及注释

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
    public final ListNode rotateRight(ListNode head, int k) {
        //防止空指针
        if(head==null){return head;}
        //不转直接返回
        if(k==0){return head;}
        int length=0;
        ListNode temp=head;
        //链表长度，不是做题的话应首先判断是否有环
        while(temp!=null){
            temp=temp.next;
            length++;
        }
        //去除转过的整圈
        if(k>=length){k%=length;}
        //与上面重复，但必须写两次，防止除零异常
        if(k==0){return head;}
        temp=head;
        //断开处节点索引
        k=length-k;
        //将来的尾节点
        ListNode beforeK=null;
        //现在的尾节点
        ListNode end=null;
        //将来的头结点
        ListNode newHead=null;
        //找到上述三个节点
        for(int i=0;i<length;i++){
            if(i==k-1){beforeK=temp;}
            if(i==length-1){end=temp;}
            if(i==k){newHead=temp;}
            temp=temp.next;
        }
        //经过上面边界条件的过滤，此时k一定小于length，剩下的极端情况为只有两个节点的链表（因为我们定义了三个节点，在定义这三个节点时我们默认它们是不同的，而只有两个节点打破了这一设定），经推演不许特殊处理
        beforeK.next=null;
        end.next=head;
        return newHead;
    }

}
```