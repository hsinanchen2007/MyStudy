### 解题思路
方法一：
该方法比较笨，将链表中的数据存到数组中，然后再将数组中的数据逐步插入到一个新链表中。

### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    var arr=[];
    while(head!=null){
        arr.push(head.val);
        head=head.next;
    }
    let cur=temp=new ListNode(null);//同时创建两个指向同一个节点的指针，cur指针一直指向当前节点，在不断移动，temp一直指向头节点
    while(arr.length){
        p=arr.pop();
        cur.next= new ListNode(p);
        cur=cur.next;
    }
    return temp.next;
};
```
方法二、迭代
创建两个个指针，分别指向前一个节点，当前节点；
在循环过程中，创建一个节点指向下一个节点
```
var reverseList = function(head) {
    if(head==null){
        return null;
    }
    var prev;
    var cur=head;  
    while(cur){
        var nextTemp= cur.next;//创建指向下一个节点的指针
        cur.next=prev;//反转链表方向
        prev=cur;//移动前一个指针到当前指针
        cur=nextTemp;//移动当前指针到下一个指针
    }
    return prev;
};
```
方法三、递归
![屏幕快照 2020-03-02 上午11.51.48.png](https://pic.leetcode-cn.com/2afdde61265dc7d1598464bad5e4902fcc0d4af045e4fd8fe2441f427568554b-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-02%20%E4%B8%8A%E5%8D%8811.51.48.png)

```
var reverseList = function(head) {
    if(!head || !head.next) {
        return head;
    }//递归出口
    var p=reverseList(head.next);
    head.next.next=head;
    head.next=null;
    return p;
};
```

