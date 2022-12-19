JS写的有点绕，直接看注释吧

```
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var reverseKGroup = function(head, k) {
    //反转最左侧的一组，返回头节点
    const fn = (head) => {
        //不需要反转的情况，直接返回
        if(k<=1 || head === null || head.next === null)return head;
        //left: 左边第一个节点，把它和后面的连接断开。right：第二个节点及连接的右边剩余节点
        let left = head, right = head.next;
        left.next = null;
        //left2: 反转后左边的链表，right2反转后右边的链表
        let [left2, right2] = fn2(left, right, k - 1);
        //右边的节点不够k了，所以right2是false
        if(right2 === false){
            //left2是剩余不足的那部分，反转后的结果，这里把它再反转一次，就成了原来的顺序，相当于这次没有反转操作
            left2 = fn2(null,left2,k)[0];
        }else{
            //left这时候是当前这组的最右侧一个，把它指向下一组的头节点
            left.next = fn(right2);
        }
        //返回反转后的链表
        return left2;
    }, 
    //fn2: 把right的前k个节点，依次取出，连到left的左边，不足k个的话，处理完为止。返回处理后的left和right
    fn2 = (left, right, k) => {
        if(k === 0) return [left, right]; //处理完了一组
        if(right === null) return [left, false]; //没处理完一组，右边已经没有了
        //r2是右边的第二个，然后把left接到right的右边，生成新的left链表，然后递归，直到k用完
        let r2 = right.next;
        right.next = left;
        return fn2(right, r2, k-1);
    };
    return fn(head);
};
```