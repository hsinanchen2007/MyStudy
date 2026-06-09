第一种方法
```python
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0)  # 声明哑结点
        dummy.next = head  # 添加哑结点在head前面
        length  = 0
        first = head
        while first != None:  # 求得链表长度
            length += 1
            first = first.next
        length -= n  # 计算倒数第n个节点在正数的第几个节点
        first = dummy
        while length > 0:
            length -= 1
            first = first.next
        first.next = first.next.next  # 跳过要删除的那个节点即可

        return dummy.next
```

第二种方法
```python
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        first = dummy
        second = dummy
        for i in range(1, n+1):
            first = first.next
        while first.next != None:
            first = first.next
            second = second.next
        second.next = second.next.next
        return dummy.next
```

链表定义、创建、插入、删除、输出、获取长度
```python
class ListNode():
    def __init__(self, value):
        self.value = value
        self.next = None

    def __str__(self):
        return str(self.value)


def createList(value_list: list) -> ListNode:
    """
    Create Linked List based on list
    :param value_list: list
    :return: NodeList
    """
    _len = len(value_list)
    if _len == 0:
        return False
    if _len == 1:
        return ListNode(value_list)
    else:
        root = ListNode(value_list[0])
        tmp = root
        for i in range(1, _len):
            tmp.next = ListNode(value_list[i])  # 声明当前节点，再把当前节点与前面节点联系在一起。
            tmp = tmp.next  # 更新tmp
    return root # 返回根节点


def printList(head: ListNode):
    """
    Print single node one by one in linked list
    :param head: ListNode
    :return: None
    """
    p = head
    while p != None:
        # print()
        print(p)  # 由于有ListNode实现了__str__函数 就不用调用p.value来获取节点值了
        p = p.next


def convert2list(head: ListNode) -> list:
    """
    Convert linked list to normal list
    :param head: ListNonde
    :return: list
    """
    res = []
    p = head
    while p != None:
        # print()
        res.append(p)  # 由于有ListNode实现了__str__函数 就不用调用p.value来获取节点值了
        p = p.next
    return res


def listLength(head: ListNode) -> int:
    """
    Get the length of linked list
    :param head: ListNode
    :return: int
    """
    count = 0
    p = head
    while p != None:
        count += 1
        p = p.next
    return count


def insertList(head: ListNode, local: int) -> ListNode:
    """
    Instert ListNode into certain current linked list
    :param head: ListNode
    :param local: int
    :return: ListNode
    """
    if local < 0 or local > listLength(head):
        return
    insert_value = input("Enter a value: ") 
    if local == 1:  # 插到第一个位置 其他节点自动后移
        tmp_Node = ListNode(insert_value)
        tmp_Node.next = head
        return tmp_Node
    # 否则插入位置大于1
    p = head
    while local != 2: # 循环n次达到n+1 所以这里是local != 2 而不是local != 1 插入的位置
        p = p.next
        local -= 1
    tmp_Node = ListNode(insert_value)
    tmp_Node.next = p.next
    p.next = tmp_Node

    return head


def deleteList(head: ListNode, local: int) -> ListNode:
    """
    Remove the certain ListNode in the linked list
    :param head: ListNode
    :param local: int
    :return ListNode:
    """
    if local < 1 or local > listLength(head):  # 待删除节点不在链表中 直接返回
        return head
    elif local == 1:
        head = head.next
    else:
        p = head
        while local != 2:
            p = p.next
            local -= 1
        tmp_p = p.next
        p.next = tmp_p.next
    return head


def main():
    value_list = [1, 2, 3, 4, 5]
    print("Create a Linklist: ")
    head = createList(value_list)
    print("Length of LinkList: {}".format(listLength(head)))
    printList(head)
    print("-"*50)
  
    n1=input("Enter the index to insert(start form 1): ")
    n1=int(n1)
    head = insertList(head, n1)
    print("Length of LinkList: {}".format(listLength(head)))
    printList(head)
    print("-"*50)
  
    n2=input("Enter the index to delete(start form 1): ")
    n2=int(n2)
    head = deleteList(head, n2)
    printList(head)

if __name__=='__main__':
    main()   # 主函数调用
```