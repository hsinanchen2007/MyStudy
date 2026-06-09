### 解题思路
题目需要使得所有小于 x 的节点都在大于或等于 x 的节点之前，并且保留每个节点的初始相对位置。因此我们可以进行一遍遍历，把小于x的节点移动到前面最后一个小于x的节点的后面。要注意并不是所有节点都需要移动，比如连续的小于x的节点。
#### 步骤
1. 我们需要三个辅助节点。一个哑结点；一个保存所有小于x的节点的最后一个节点，用来连接新的小于x的节点；一个保存在遍历时某个节点的前驱节点，用来断开当前找到的小于x的节点；
2. 对链表进行遍历，并判断当前节点的值是否小于x，若小于，再判断是否需要移动，若其前驱节点也是小于x的则不用移动。

### 代码

```java
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode dummy=new ListNode(0),last=dummy,prev=dummy;
        dummy.next=head;
        ListNode node=head;
        while(node!=null){
            if(node.val<x){
                //如果不是连续的节点，则进行交换
                if(last.next!=node){
                    //断开当前节点
                    prev.next=node.next;
                    node.next=last.next;
                    //更新最后一个小于x的节点
                    last.next=node;
                    last=node;
                    //继续往后遍历
                    node=prev.next;
                    continue;
                }else last=node;
                
            }
                prev=node;
                node=node.next;
        }
        return dummy.next;
    }
}
```