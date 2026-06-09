删除链表中等于给定值 val 的**所有**节点。

示例:
```
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
```

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-linked-list-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

最初的思路：
1、定义两个节点类型的指针，cur用于指向cur.val与给定值val相等的元素，而prev则用于指向cur前一个元素。并不断维护这两个指针
2、将cur.next赋值给prev.next
3、将cur.next的值设为null，使得cur从链表上完全地脱离下来，方便Java内存回收机制对cur指向的节点进行回收。
4、在将cur指向prev.next
![203-1.png](https://pic.leetcode-cn.com/ff9a693cd1ce57d875910754339741faefb481f1950d6b3b1421e0182b9fc459-203-1.png)

然后发现cur一开始就是第二个元素了，第一个元素没有被判断到，应该怎么处理呢？
然后就死循环了，一个对头结点进行特殊判断，移除之后第二个节点就变成第一个节点了，又面临同样的问题！！
所以循环把前面满足条件的全部删掉，到最后就不用再去判断第一个元素了
```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    // 解法一、循环迭代，不引入虚拟头结点
    public ListNode removeElements(ListNode head, int val) {
        //删除头节点之后，下一个节点就变成了新的头结点
        //因此要迭代把所有满足条件的头结点删除
        while(head!=null&&head.val==val){
            ListNode delNode=head;
            head=head.next;
            delNode.next=null;
        }
        //可能链表这种所有节点都是要删除的，最后剩下一个空链表
        if(head==null)
            return head;
        //非空链表且第一个结点的val值不等于给定的val链表的操作
        ListNode cur=head.next;
        ListNode prev=head;
        //这种做法第一个节点没办法判断到
        while(cur!=null){
            if(cur.val==val){
                prev.next=cur.next;
                cur.next=null;
                cur=prev.next;
            }
            else{
                cur=cur.next;
                prev=prev.next;
            }
        }
        return head;
    }
}
```
仔细想想，之前其它题目的时候为什么不用考虑这个？因为其它题目是有虚拟头结点dummyHead的，但是这道题目没有！！！大脑宕机
没有条件创造条件也要上，没有虚拟头结点你不会自己加上去啊！！！
![203-2.png](https://pic.leetcode-cn.com/febce3c42dedf12ff7d39f0712a911748282f8982bc108f3c3f66bda859b62cb-203-2.png)


```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    //循环迭代，引入虚拟头结点
    public ListNode removeElements(ListNode head, int val) {
		    //判断传进来的是不是一个空链表,若是，直接返回head
        if(head==null){
            return head;
        }
        //添加一个虚拟的头结点，虚拟头结点的值取什么？
        ListNode dummyHead=new ListNode(0);
        dummyHead.next=head;
        head=dummyHead;
        
        ListNode cur=head.next;
        ListNode prev=head;
        //这种做法第一个节点没办法判断到
        while(cur!=null){
            if(cur.val==val){
                prev.next=cur.next;
                cur.next=null;
                cur=prev.next;
            }
            else{
                cur=cur.next;
                prev=prev.next;
            }
        }
				//注意这里不能将head返回回去，会包含虚拟头结点。应该返回dummyHead.next
        return dummyHead.next;
    }
}
```
总结：以后遇到链表的头结点比较难处理的情况也可以添加一个虚拟头结点进行尝试。