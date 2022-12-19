![image.png](https://pic.leetcode-cn.com/7bf8a596a4749a94800709e21965d345994a8346c8b6464f3f603dba99eaaf89-image.png)

遍历一把直接返回：
class Solution(object):
    def canThreePartsEqualSum(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        if sum(A)% 3:
            return False
        average = sum(A)/ 3
        tmp,cnt = 0,0
        for i in A:
            tmp += i
            if tmp == average:
                tmp,cnt = 0,cnt + 1
        return  cnt == 3