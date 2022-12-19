本题其实也是很简单了，我觉得主要有两个难点，只要攻克了就很好解题了。
```
1. 如何构建循环链表
2. 如何通过链表的尾指针检测该链表是否为循环链表
```
第一点没什么好说了，大家直接看我的代码即可。关于第二点，我想到的方法是置空法，简而言之就是做标记。从头开始遍历链表，遍历一个节点就将其val值赋空None，如果将来某次遍历得到节点的val值为None，说明该链表为循环链表；反之则不为空。是不是很easy了，直接看代码吧。

代码如下：
```Python
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head is None:
            return False
        # 采用置空法，遍历一个节点，将当前节点内的值置空做标记
        while head.next and head.val is not None:
            head.val = None
            head = head.next
        if head.next:
            return True
        else:
            return False


# 构建循环链表
def get_listnode(node_list, pos):
    head = ListNode(0)
    head_copy = head
    # 负责记录链表中尾节点指向的节点，从而构建循环链表
    cur_node = None
    for index in range(len(node_list)):
        if index == pos:
            cur_node = ListNode(node_list[index])
            head_copy.next = cur_node
        else:
            head_copy.next = ListNode(node_list[index])
        head_copy = head_copy.next
    # 将尾节点指向指定pos位置的节点
    head_copy.next = cur_node
    return head.next


if __name__ == "__main__":
    node_list = [1, 3, 9, 7, 5]
    node = get_listnode(node_list, 1)
    print(Solution().hasCycle(node))
```
执行效率还算是不错的啦，在90%+！
![image.png](https://pic.leetcode-cn.com/334620258b056b7551bcbc49f31a208f96c8e27a36e0d3f778b890efb461b482-image.png)
