我直接看了一眼感觉是规律题, 然而又看了一眼大家的解答, 瞬间黑人问号, 这跟栈真的有任何关系吗?
主要都是节点数对或不对的问题啊, 
由于他不会出现一个空树, 所以我就没有在最开始判断, （其实是忘了, 不过过了, 那就懒得改了）
重点就是数数, 第一层当然只有一个节点, 那列表里应该有一个数给我数, 我数了一下, 哟还不是'#', 那说明这是一个有效节点,记个1
第二层有两个有效节点(假设), 那第三层应该有4个数给我数, 
没给够, 滚
给够了我继续数, 如果有一层我一个有效节点都没数到, 那说明他应该是最后一层了, 如果列表里面还有数想给我数, 滚
那什么时候是ok的呢, 我数完一层, 发现有8个有效节点, 你下一层应该给我16个数给我数一下, 结果刚好16个, 完美
我写解都是重在思路, 所以我的解可能还有改进的空间, 不过我不在意
```
class Solution:
    def isValidSerialization(self, preorder):
        lst = preorder.split(',')
        total = 1
        while True:
            rec = 0
            for i in range(total):
                if lst[0] != '#':
                    rec += 1
                lst.pop(0)
            total = rec * 2
            if total == 0 and len(lst) > 0:
                return False
            if total > len(lst):
                return False
            elif total == len(lst):
                return True
```
