
```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode node=new ListNode(0);
            addTwoNumbers(l1,l2,false,node);
            return node.next;
    }

    /**
     *
     * @param l1 链表1当前节点
     * @param l2 链表2当前节点
     * @param rose 是否有上一批节点值相加进一位
     * @param node 引用传递节点
     */
    private void addTwoNumbers(ListNode l1, ListNode l2,Boolean rose, ListNode node){

        if (l1!=null||l2!=null||rose){
            int sum=(l1==null?0:l1.val)+(l2==null?0:l2.val);
            if (rose){
                sum+=1;
            }
            if (sum>=10){
                node.next=new ListNode(sum-10);
                rose=true;
            }else {
                node.next=new ListNode(sum);
                rose=false;
            }
            ListNode l1Next=l1==null? null:l1.next;
            ListNode l2Next=l2==null? null:l2.next;
            addTwoNumbers(l1Next,l2Next,rose,node.next);
        }
    }

```