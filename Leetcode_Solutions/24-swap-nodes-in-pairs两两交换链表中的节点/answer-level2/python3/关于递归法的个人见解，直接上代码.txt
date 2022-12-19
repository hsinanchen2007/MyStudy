class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        # 先判断开头是否为空或者一个元素
        if head == None or head.next == None :
            return head
        nextTemp = head.next                        # 若元素超过两个，就两个一组定义递归。第一个元素是head 第二个是nextTemp
        head.next = self.swapPairs(nextTemp.next)   # 递归（生成每两个元素一组），前面一组的的head指向前面一组next 的 后面一个（后面一个）
        nextTemp.next = head                        # 每一组中的next指向当前组里面的head
        return nextTemp                             # 此时此刻的表头的next