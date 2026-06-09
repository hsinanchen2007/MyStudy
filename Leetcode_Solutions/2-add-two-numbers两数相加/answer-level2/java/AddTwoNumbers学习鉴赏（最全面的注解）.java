### 解题思路
AddTwoNumbers //解决两个数字相加问题，实际上是链表思想
//解决这道题就简单的就是遍历两个链表，相加。需要注意的地方就是进位问题。
//力扣官方的这道题解法真的把最简单的思想表达的淋漓尽致，请欣赏

### 代码

```java
public ListNode addTwoNumbers(ListNode l1,ListNode l2){
ListNode dummyHead = new ListNode(0);
ListNode p = l1, q = l2, curr = dummyHead; //curr是为了操作结果链表dummyHead而设
int carry = 0;  //进位
while(p!=null||q!=null){
    int x=(p!=null)?p.val:0;  //如果p不为空，给x赋值p.val，负责赋值0
    int y=(q!=null)?q.val:0;
    int sum=carry+x+y;
    carry=sum/10; //进位注意是除法
    curr.next=new ListNode(sum%10); //为当前求和的值请求空间，注意是取模
    curr=curr.next; //让curr指向当前结点，注意curr慢我们求和结点一拍
    if(p!=null) p=p.next; //最后判断p是否已经到链表尾了，如果没有就接着下一个继续循环
    if(q!=null) q=q.next;
}
if(carry>0){
    curr.next=new ListNode(carry); //循环完成以后一定要判断进位carry是否大于1，如果是就加curr.next上
}
return dummyHead.next; //返回结点地址
}
```