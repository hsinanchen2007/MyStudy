### 解题思路
![image.png](https://pic.leetcode-cn.com/6617fc9b3a7ab26892adbc43d96d41295affa156cf6ac4e1ee947a924d202b45-image.png)

遍历存入一个ArrayList，直接利用下标
看了双指针的算法，确实牛逼！

特意拿双指针跑了一下 0ms 40MB ；对比我的1ms，40MB，好奇为啥没多空间，反而是多了用时，不科学啊
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode ptr = head;
        ArrayList<ListNode> listNodes = new ArrayList<>();
        while (ptr != null) {
            listNodes.add(ptr);
            ptr = ptr.next;
        }
        // 第N个节点的前一个 N是 第一个时，取它前一个还是它
        int last = Math.max((listNodes.size() - n - 1), 0);
        // 待删除节点
        int current = listNodes.size() - n;
        // 删除第一个节点 头结点 需要把头结点指针后移
        if(current == 0){
            head = head.next;
            return head;
        }

        listNodes.get(last).next = listNodes.get(current).next;
        return head;
    }
}
```