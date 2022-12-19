class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
def addTwoNumbers(l1, l2):
    """
    :type l1: ListNode
    :type l2: ListNode
    :rtype: ListNode
    """
    p = l1
    q = l2
    flag = 0    # 进位标志符 
    result = [] # 用来存放结果，暂时是列表形式
    while p or q:
        temp = p.val + q.val    # 每次扫描算出临时的结果
        if flag == 1:           # 先判断是否需要进位
            temp += 1
            flag = 0            # 记得把flag设为0
        if temp >= 10:          # 若大于10 则需要进位，同时只去个位数，即temp-10
            temp -= 10
            flag = 1
        result.append(temp)     # 判断完将结果加入result列表中
        if p.next and q.next:   # 四种条件判断链表指针是否指向下一个，这一部分有待修改，很冗余
            p = p.next
            q = q.next
        elif p.next and not q.next:
            p = p.next
            q.val = 0
        elif q.next and not p.next:
            q = q.next
            p.val = 0
        else:
            break
    if flag == 1:
        result.append(1)
    print("{}".format(result.pop(0)),end="")    # 为了输出和结果一样的形式
    for i in range(len(result)):
        print('->{}'.format(result.pop(0)),end='')

if __name__ == '__main__':
    a1 = ListNode(1)
    a2 = ListNode(8)
    a3 = ListNode(9)
    a1.next = a2
    a2.next = a3
    a3.next = None
    b1 = ListNode(4)
    b2 = ListNode(3)
    b1.next = b2
    b2.next = None
    addTwoNumbers(a1,b1)

运行结果：5->1->0->1
