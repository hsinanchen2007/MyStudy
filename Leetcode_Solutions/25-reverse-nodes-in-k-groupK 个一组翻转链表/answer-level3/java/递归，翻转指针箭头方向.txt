### 解题思路
代码中有些注释，希望有帮助
![ans2.png](https://pic.leetcode-cn.com/90e9ceb0cd25da11c830608af6481fd36a4b84f7aab4714a9746c174e158a250-ans2.png)
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
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null || k == 1){
            return head;
        }
        ListNode head1 = head,head2 = null,head3 = null,headk_1 = null;
        //找出最后一个节点，同时判断是否需要翻转
        for(int i = 0;i < k;i++){
            if(head == null){
                return head1;
            }
            if(i+1==k){
                break;
            }
            head = head.next;
        }
        //记录下一组的第一个节点
        headk_1 = head.next;
        //head指针复位
        head = head1;
        //k个节点有k条指向子节点的链接（可能是空的，不过没关系）
        for(int j = 0;j < k/2;j++){
            //定位第二个节点
            head2 = head1.next;
            //定位第三个节点
            head3 = head2.next;
            //第二个节点翻转指向第一个节点
            head2.next = head1;
            //第一个节点翻转指向 上次循环翻转后的 第一个节点
            head1.next = headk_1;
            /**
             * 以下两行是为了为下次循环做准备
             */
            //存储翻转后的第一个节点（就是上面注解说的： 上次翻转后的 第一个节点）
            headk_1 = head2;
            //重新定位第一个节点
            head1 = head3;
        }
        //如果k为单数个，则上边循环后会剩余一个节点未翻转，需要手动翻转
        if(k%2 != 0){
            head1.next = headk_1;
        //如果k为双数个，则上边循环后会将head1定位到下一次递归操作的第一个节点，
        //需要手动将他定位到向当前翻转结束后的 第一个节点
        }else{
            head1 = headk_1;
        }
        //由于翻转后head会变为当前分组的最后一个节点，因此需要用它承接下一组翻转
        head.next = reverseKGroup(head.next,k);
        return head1;
    }

}
```