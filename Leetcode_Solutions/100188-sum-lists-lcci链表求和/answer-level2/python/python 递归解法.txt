python 递归解法
和445一样
[445] 两数相加 II
https://leetcode-cn.com/problems/add-two-numbers-ii/description/
```python3
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # 循环计算每一位的和
        # cnt是l1-l2的长度差异
        def dfsCarry(l1, l2, cnt):
            if not l1 or not l2:return 0 
            if cnt>0:
                cursum = l1.val + dfsCarry(l1.next, l2, cnt-1)              #l1往后走，cnt==0时就与l2对齐了，可以计算和与进位
                l1.val = cursum % 10
                return cursum//10
            else:
                cursum = l1.val + l2.val + dfsCarry(l1.next, l2.next, 0)    #长度一样时，每一位的和是l1+l2+carry
                l1.val = cursum % 10
                return cursum//10                                           #进位情况
        
        #计算 l1 l2 的长度
        len1 = len2 = 0
        cur = l1
        while cur:
            len1 += 1
            cur = cur.next
        cur = l2
        while cur:
            len2 += 1
            cur = cur.next
        
        #换下位置 l1是较长的，l2是较短的
        if len2 > len1:
            l1, l2 = l2, l1
            len2, len1 = len1, len2
        
        # 最高位是1的情况，需要进位
        leftsum = dfsCarry(l1, l2, len1-len2)
        if leftsum:
            dummy = ListNode(1)        #进位最前面加节点1即可
            dummy.next = l1
            l1 = dummy                 #更新l1
        return l1
```
不过这题python的测试用例有问题，一会正一会反，迷之操作
![WechatIMG13.jpeg](https://pic.leetcode-cn.com/abac5dea3d086f816097e2ebadf24d2ed079f9426b1146a957d3a093d73f3bc5-WechatIMG13.jpeg)
![WechatIMG14.png](https://pic.leetcode-cn.com/c0ead44003efa71bb85af8a3d0b2b0eecf4bd07dab67ced87bc8aeb9be606005-WechatIMG14.png)
