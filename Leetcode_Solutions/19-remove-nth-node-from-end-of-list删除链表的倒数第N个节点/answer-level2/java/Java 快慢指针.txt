### 解题思路
1. 得到链表总长度len
2. 将len-n得到要删除的元素的顺序位置
#### 得到链表总长度
我们可以一次遍历整个链表得到总长度，但这样效率有点低。我们可以利用快慢指针，此时遍历次数减少到原来的1/2，同时我们设置一个计数器counter，在快慢指针每遍历一次就加一。要注意，当链表长度是偶数时，链表长度是2\*counter，而当链表长度是奇数时，链表长度应是2\*counter+1。
### 代码

```java
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null)return null;
        //判断链表长度是偶数还是奇数
        boolean even=false;
        int counter=0;
        ListNode fast=head;
        while(fast!=null&&fast.next!=null){
            fast=fast.next.next;
            counter++;
            if(fast==null)
                even=true;
            else even=false;
        }
        //得到总长度
        if(even)
            counter*=2;
        else counter=2*counter+1;
        //前驱指针
        ListNode prev=null,node=head;
        //将指针移动到要删除的位置
        for(int i=0;i<=counter-n;i++){
            if(i==counter-n){
                if(prev==null)head=head.next;
                else{
                    prev.next=node.next;
                }
            }
            prev=node;
            node=node.next;
        }
        return head;
    }
}
```
**时间复杂度：O(3N/2)。** 第一次遍历是O(N/2)，第二次最坏情况下是O(N)。
**空间复杂度：O(1)。** 只用了特定数量的变量