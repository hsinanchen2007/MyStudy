![image.png](https://pic.leetcode-cn.com/b1608c65675e48ed305d1c62869b9cfada84fa94a753ef3d4e24733e5daf17a8-image.png)


class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A) != len(B):
            return False
        if len(A) == 0:
            return False
        tmp =[]
        for i in range(len(A)):
            if A[i] == B[i]:
                continue
            else:
                tmp.append([A[i],B[i]])
        #存在1个或者多余2个位置不同，那肯定false
        if len(tmp) > 2 or len(tmp) == 1:
            return False
        #存在两个位置不同，判断是否可以进行交换
        elif len(tmp) == 2:
            if tmp[0][0] == tmp[1][1] and tmp[0][1] == tmp[1][0]:
                return True
            else:
                return False
        #每个位置都一样，需要判断是否存在每个字符串内是否存在相同元素来进行交换
        else:
            if len(A) > len(set(A)):
                return True
            else:
                return False
            

        