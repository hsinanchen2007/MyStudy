
![屏幕快照 2020-01-16 下午4.46.53.png](https://pic.leetcode-cn.com/c15f77187ddbcbb747cfa0a3bf2e96fe46138ba83f34e7c943ffd705a14a1865-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-01-16%20%E4%B8%8B%E5%8D%884.46.53.png)


### 解题思路
先求出链表的长度，然后除以 k，得到数组每个元素存放链表的个数。再求出链表长度模k得到余数，即前面数组元素应该多存入的。每次数组元素多存入后，ret需要减一

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


 // 思路：
 
class Solution {
    public static ListNode[] splitListToParts(ListNode root, int k) {
        ListNode[] lists = new ListNode[k];
        // 求出链表的长度
        int len = size(root);
        // 余数
        int ret = len % k;
        // 每组个数
        int count = len / k;
        // 作为下一次 head 起点的标记
        ListNode node = root;
        for (int i = 0; i < k; i++) {
            // 设置标记用来判断链表是否遍历完成
            boolean flag2 = false;
            // 数组的每个元素开始的位置
            ListNode head = node;
            // 数组每个元素往后走的标志
            ListNode tail = head;
            // tail 节点的前一个节点，用来结束对当前段的链表；否则链表连续的不方便放进数组中
            ListNode p = tail;
            // 遍历数组的下标，方便将元素放进数组中
            for (int j = count; j > 0; j--) {
                // p 每次都指向 tail 的前一个元素
                p = tail;
                // 如果 tail 为空说明链表已经遍历完了，如果数组还有空余位置，需要填充 null，并且修改 flag2 标志位
                if (tail == null) {
                    lists[i] = null;
                    flag2 = true;
                    break;
                }
                // 如果 tail 不等于 null，就继续往后面遍历
                if (tail != null) {
                    tail = tail.next;
                } else {
                    // 如果在遍历过程中 tail 为 null，就把当前链表段放入数组中，修改标志位，结束本次循环
                    lists[i] = node;
                    node = tail;
                    flag2 = true;
                    break;
                }
            }
            // 如果标志位发生变化，说明链表遍历完了，结束本次循环
            if (flag2) {
                continue;
            }
            // 有余数，在前面的数组元素中每个添加一个节点，直到余数为 0
            if (ret > 0 && tail != null) {
                p = tail;
                tail = tail.next;
                ret--;
            }
            // 如果 p 不为 null，将 tail 前一个节点即 p.next 修改为 null，
            // 不然链表是连续的，不能拆解放入数组中
            if (p != null) {
                p.next = null;
            }
            // 更新 node，方便下次更新 head 的值
            node = tail;
            // 将当前链表段放入数组中
            lists[i] = head;
        }
        return lists;
    }
    private static int size(ListNode root) {
        int count = 0;
        for (ListNode cur = root; cur != null; cur = cur.next) {
            count++;
        }
        return count;
    }
}
```