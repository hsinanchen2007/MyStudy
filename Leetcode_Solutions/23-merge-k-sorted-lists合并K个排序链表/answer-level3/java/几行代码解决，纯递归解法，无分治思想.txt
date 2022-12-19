这个题除了暴力解法就是分治法，那么可不可以用纯递归方法来做呢？

可以的，只需每次遍历一遍找到最小节点，然后在最小节点的基础上用 node.next 来引出下一节点。注意用递归之前我们要遵循几个步骤：

1.找到最小val的那个点
2.让 node = 最小val的那个点 
3.让最小val的那个点= 他本节点的下一个点
4.运用递归：node.next = 本方法求出的下一个点
5.返回 node

这个解法的好处是代码量少，但是不如分治法快。

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
     public ListNode mergeKLists(ListNode[] lists) {
        int min = Integer.MAX_VALUE;
      int mark = -1;
      for(int i = 0; i<lists.length; i++){
          if(lists[i] != null && lists[i].val < min){
              min = lists[i].val;
              mark = i;
          }
      }
      if(mark == -1) return null;
      ListNode node = lists[mark];
      lists[mark] = lists[mark].next;
      node.next = mergeKLists(lists);
      return node;
    }
}
```