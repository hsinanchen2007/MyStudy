### 解题思路
寻找关键的节点：
1.逆置段头节点的前驱
2.逆置前头节点(逆置后尾节点)
3.逆置前尾节点(逆置后头节点)
4.逆置段尾节点的后继
![image.png](https://pic.leetcode-cn.com/955617b95cb79ecb566c4f8780f455c8d60f4caae2b51e083475d3f57f36a340-image.png)
![image.png](https://pic.leetcode-cn.com/c9154a574b0e6980cb6e2288973e632a738b3af7f3c5406768c4c1b0952a8633-image.png)


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
 * @param {number} m
 * @param {number} n
 * @return {ListNode}
 */
var reverseBetween = function(head, m, n) {
    // 计算需要逆置的节点个数
    let change_len = n - m + 1;
    // 初始化开始逆置的节点的前驱
    let pre_head = null;
    // 最终转换后的链表头节点,非特殊情况即为head
    let result = head;
    // 将head向前移动m-1个位置
    while(head && --m){
        // 记录head的前驱
        pre_head = head;
        head = head.next;
    }
    // 将modify_list_tail指向当前的head,即逆置后的链表尾
    let modify_list_tail = head;
    let new_head = null;
    // 逆置change_len个节点
    while(head && change_len){
        let next = head.next;
        head.next = new_head;
        new_head = head;
        head = next;
        // 每完成一个节点逆置,change_len--
        change_len--;
    }
    // 连接逆置后的链表尾与逆置段的后一个节点
    modify_list_tail.next = head;
    // 如果pre_head不空，说明不是从第一个节点开始逆置的m>1
    if(pre_head){
        // 将逆置链表开始的节点前驱与逆置后的头节点链接
        pre_head.next = new_head;
    }else{
        // 如果pre_head为空，说明m=1从第一个节点开始逆置，结果即为逆置后的头节点
        result = new_head;
    }
    return result;
};
```