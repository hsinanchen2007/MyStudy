boarder是左边的边界， max_value是左边的最大值。所以每次从右往左找第一个比max_value小的值，有的话，就从找到的位置往boarder遍历，对max_value和boarder进行更新。
所以实际上，最好的情况下，遍历一次就会发现，没有一个值小于max_value就是O(N)
但是一般情况下，找到了第一个比max_value小的值的时候就走了遍历了n步，找到以后，为了走到boarder需要走 len(A) - 2 - n 步，所以第一轮while循环就是O(N)
第二轮的while循环，就是最坏是走 n 步。
（这时间复杂度怎么分析啊。）
最坏的情况应该是，每一轮的while循环都出现了一个比max_value更大的值。
5 , 10 , 4 , 12 , 8 , 20
-5-------10-------12
这应该就是最坏的情况了，每次更新都会更新一个新的max_value....这样的话，第一次找到4 然后从4走到10.第二次找到8 从 8 走到 12。
时间复杂度应该是 (n-2) + (n-4) + (n-6) ... = (n-2) * n / 2 / 2 等差数列求和？ = O(n^2)
好像时间复杂度有点高啊。但是是100%啊。是不是提交的人比较少啊。。。
```python
class Solution(object):
    def partitionDisjoint(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        max_value = A[0]
        boarder = 1
        while True:
            flag = False
            for point in range(len(A) - 2, boarder-1, -1):
                if A[point] < max_value:
                    flag = True
                    break
            if not flag:
                break
            tmp_boarder = point + 1 
            while point >= boarder:
                max_value = max(max_value, A[point])
                point -= 1
            boarder = tmp_boarder
        return boarder
            
        
```