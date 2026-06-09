```
'''
LeetCode 780 到达终点
A move consists of taking a point (x, y) and transforming it to either (x, x+y) or (x+y, y).
Given a starting point (sx, sy) and a target point (tx, ty),
return True if and only if a sequence of moves exists to transform the point (sx, sy) to (tx, ty).
 Otherwise, return False.
Examples:
Input: sx = 1, sy = 1, tx = 3, ty = 5
Output: True
Explanation:
One series of moves that transforms the starting point to the target is:
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)
Input: sx = 1, sy = 1, tx = 2, ty = 2
Output: False
Input: sx = 1, sy = 1, tx = 1, ty = 1
Output: True
Note:
sx, sy, tx, ty will all be integers in the range [1, 10^9].

题目大意：
从点 (x, y) 可以转换到 (x, x+y)  或者 (x+y, y)。
给定一个起点 (sx, sy) 和一个终点 (tx, ty)，如果通过一系列的转换可以从起点到达终点，则返回 True ，否则返回 False。
示例:
输入: sx = 1, sy = 1, tx = 3, ty = 5
输出: True
解释:
可以通过以下一系列转换从起点转换到终点：
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)
输入: sx = 1, sy = 1, tx = 2, ty = 2
输出: False
输入: sx = 1, sy = 1, tx = 1, ty = 1
输出: True
注意:
sx, sy, tx, ty 是范围在 [1, 10^9] 的整数。

解题思路：
这道题看着简单，但是很难，你直到easy和hard的区别在哪里么？
核心就在于easy一步思考到位，hard题需要多步思考，多知识点综合运用
一点一点进行，下面是递进思考的过程
方法1：暴力法
每个点都可以转换成两个子点，递归搜索所有子点。
class Solution(object):
    def reachingPoints(self, sx, sy, tx, ty):
        if sx > tx or sy > ty: return False
        if sx == tx and sy == ty: return True
        return self.reachingPoints(sx+sy, sy, tx, ty) or self.reachingPoints(sx, sx+sy, tx, ty)
指数级别的时间复杂度，面试肯定过不了
方法2：dp算法
为了避免重复计算，使用一个集合 seen 存储方法一中递归搜索到的子点。
class Solution(object):
    def reachingPoints(self, sx, sy, tx, ty):
        seen = set()
        def search(x, y):
            if (x, y) in seen: return
            if x > tx or y > ty: return
            seen.add((x, y))
            search(x+y, y)
            search(x, x+y)

        search(sx, sy)
        return (tx, ty) in seen
平方级别的时间复杂度，同样不可以过的
方法3：辗转相减法
每个父点 (x, y) 都有两个子点 (x, x+y) 和 (x+y, y)。
由于坐标不能为负，每个子点 (x, y) 只能有一个父点，当 x >= y 时父点为 (x-y, y)；当 y > x 时父点为 (x, y-x)。
从终点开始不断向上求解父点，可以判断给定点是否是正确的起点。
例如，当终点是 (19, 12) 时，它的父点是 (7, 12)， (7, 5) 和 (2, 5)。因此 (2, 5) 是 (19, 12) 的起点。
class Solution(object):
    def reachingPoints(self, sx, sy, tx, ty):
        while tx >= sx and ty >= sy:
            if sx == tx and sy == ty: return True
            if tx > ty:
                tx -= ty
            else:
                ty -= tx
        return False
时间复杂度是N级别，面试到这基本稳，但是不够
方法4：终极优化，加速求解父亲节点，因为取余也相当于一种减法
与方法三一样，通过求解父点完成 (x, y) -> (x-y, y) 或 (x, y-x) 的转换，具体使用哪一种转换取决于哪种结果没有负数，
可以使用模运算加速求解父点的过程，具体如下：
当 tx > ty 时，求解父点的运算是 tx - ty，并且它的往上 tx = tx % ty 个父点都是减去 ty。
当同时满足 tx > ty 和 ty <= sy 时，可以一次性执行所有的这些操作，直接令 tx %= ty。
否则，如果满足 tx > ty 和 ty <= sy，那么 ty 不再改变，只能不断从 tx 中减去 ty。因此， (tx - sx) % ty == 0 是结果为 true 的充要条件。
上面的分析是针对 tx > ty 的情况，对于 ty > tx 的情况类似。 当 tx == ty 时，无法再求解父点。
class Solution(object):
    def reachingPoints(self, sx, sy, tx, ty):
        while tx >= sx and ty >= sy:
            if tx == ty: # 相等了不能再进行取余了，直接break看看是不是和初始相等即可
                break
            elif tx > ty: # tx大，减tx
                if ty > sy:
                    tx %= ty
                else:
                    return (tx - sx) % ty == 0 # 此时ty == sy了，到边界了，不可以减了，只需要看tx和边界的差值能不能整除sy了
                    # 对的，你不用问，这个ty可以改成sy的
            else:
                if tx > sx:
                    ty %= tx
                else:
                    return (ty - sy) % tx == 0

        return tx == sx and ty == sy # 上面搞完没return，看看是不是和初始相等即可
时间复杂度根号N级别
'''
class Solution(object):
    def reachingPoints(self, sx, sy, tx, ty):
        while tx >= sx and ty >= sy:
            if tx == ty: # 相等了不能再进行取余了，直接break看看是不是和初始相等即可
                break
            elif tx > ty: # tx大，减tx
                if ty > sy:
                    tx %= ty
                else:
                    return (tx - sx) % ty == 0 # 此时ty == sy了，到边界了，不可以减了，只需要看tx和边界的差值能不能整除sy了
                    # 对的，你不用问，这个ty可以改成sy的
            else:
                if tx > sx:
                    ty %= tx
                else:
                    return (ty - sy) % tx == 0

        return tx == sx and ty == sy # 上面搞完没return，看看是不是和初始相等即可

if __name__ == "__main__":
    sx = 1
    sy = 1
    tx = 3
    ty = 5
    s = Solution()
    print(s.reachingPoints(sx, sy, tx, ty))
```
