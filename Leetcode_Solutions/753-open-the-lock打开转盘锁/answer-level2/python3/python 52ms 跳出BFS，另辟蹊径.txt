
![image.png](https://pic.leetcode-cn.com/f435ae618b4fd395e9601e90cd9afd0734b56b731993f1eb53d06e8d9ebc8e98-image.png)

代码如下（不过声明这是看别的大神的做法，我个人用的也是BFS，感觉这个做法很巧妙，但又有不明白的地方，在这里发出来算是共同探讨）：
```
class Solution:
    def openLock(self, deadends, target):
        # 定义一个距离函数，计算一个code直接拨需要多少下，比如0003就是3下，0099就是2下。
        def dist(code):
            return sum([min(int(c), 10-int(c)) for c in code])
        
        if "0000" in deadends or target in deadends :
            return -1

        # 由target反推能够到达target的所有前一个节点，放在 new_codes 里返回。
        new_codes = []
        for i in range(4):
            pre, x, sur = target[:i], int(target[i]), target[i+1:]
            new_codes.append(pre + str((x+1)%10) + sur)
            new_codes.append(pre + str((x-1)%10) + sur)
        
        # 利用集合（set）是可以做减法，得出不在deadends里面的new_codes，放在 moves 里。
        # set的减法：例如{'0001','0005','0016'} - {'0005','0007'} = {'0001', '0016'}
        moves = set(new_codes) - set(deadends)
        # 如果moves为空，那就说明没有路径可以到达target，那就返回 -1
        if not moves:
            return -1
        
        result = dist(target)  # 例如 result = dist('0888') ，那么 result就等于6
        # 接下来我就不太明白了....
        for move in moves:
            if dist(move) < result: # <------
                return result       # <------ 尤其这三行，为啥dist(move)比result小时，就返回result
        return result + 2           # <------ 否则就返回 result + 2 ，为啥+2 ？ 
```
---------update-----------
已经搞明白了，看评论

以上！

