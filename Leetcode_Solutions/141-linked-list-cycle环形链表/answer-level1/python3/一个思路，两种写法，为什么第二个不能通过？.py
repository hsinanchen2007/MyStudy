""" 利用set """
#定义一个set，然后不断遍历链表
s = set()
while head:
    #如果某个节点在set中，说明遍历到重复元素了，也就是有环
    if head in s:
        return True
    s.add(head)
    head = head.next
return False


""" 哈希表 """
# 建立哈希表
hash_map = {}
# 特例，head为空
if not head:
    return False
# 只要head没指向None或者没遇到环
while head:
    # 当前结点值在哈希表中
    if head.val in hash_map:
        return True
    hash_map[head.val] = 1
    head = head.next
return False

求各位大佬解答！！