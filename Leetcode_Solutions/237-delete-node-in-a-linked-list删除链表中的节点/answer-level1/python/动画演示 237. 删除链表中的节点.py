
# 题解
这道题的函数是这样定义的：
```python 
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
```   
题目是给你一个节点，要求你删除这个节点。      
也就是给我们的是5这个节点，注意给我们的不是一个值，而是要求删除这个节   
![img_2608.jpg](https://pic.leetcode-cn.com/15eda715e9429569f6acb8cbbd8a2f88c85c3ad97f5b53b564c44714490785d1-img_2608.jpg)

如果是双链表就很简单了，直接改变前驱和后继的指针就可以了。      
而删除单链表的某个节点，就需要找到这个节点的前驱节点，通过前序节点来删除这个节点。现在没有前驱节点怎么做呢？   
注意题目描述，题目描述中说明了每个节点的值都不一样，而且要删除的节点也不是末尾节点。   
我们可以利用这个关键条件，将5这个节点的下一个节点1的值赋给节点5，然后将节点5指向下下一个节点   
![删除链表中的节点-动态图.gif](https://pic.leetcode-cn.com/995bb80db76ed236c94e8e7373361f637fb793b14041d1669de1090ba65f516a-%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9-%E5%8A%A8%E6%80%81%E5%9B%BE.gif)

因为题目中已经帮我们明确了边界条件，所以我们都不用判断了。   
这道题的代码非常简单，python一行就搞定了   
代码如下：
```java []
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        //将下一个节点值赋给当前节点
        node.val = node.next.val;
        //再将当前节点指向 下下一个节点
        node.next = node.next.next;
    }
}
```
```python []
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        # 将下一个节点值赋给当前节点
        # 再将当前节点指向 下下一个节点
        node.val,node.next = node.next.val,node.next.next
```
(全文完)   

**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)