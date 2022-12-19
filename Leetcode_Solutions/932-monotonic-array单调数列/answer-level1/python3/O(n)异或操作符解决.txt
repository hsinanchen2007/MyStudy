速度上看目前打败了99.85%的人，首先分两种情况，一种数组size小于等于2，剩下一种就都是大于2

1. 小于等于2都是单调的
2. 大于2的情况，设置一个flag，官方的题解中用的不是异或操作符，需要多次assign，效率不高，异或的好处在于单调的情况下，要么你都是小于，要么都是大于，对于flag值就是要么都是False，要么都是True，异或后就都是True，不单调异或后都是False，很符合异或操作符的场景

class Solution(object):
    def isMonotonic(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        if len(A) <= 2:
            return True
        
        flag = -1
        for idx, num in enumerate(A[1:], 1):
            if num == A[idx - 1]:
                continue
            if flag == -1:
                flag = num > A[idx - 1]
            else:
                if (num > A[idx - 1]) ^ flag:
                    return False
        return True
                
                
            