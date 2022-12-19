/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/8/30]
 *
 * 解题思路: 就 TMD 删除第一个节点嘛
 */
```
 public void deleteNode(ListNode node) {

        node.val = node.next.val;
        node.next = node.next.next;

}
```