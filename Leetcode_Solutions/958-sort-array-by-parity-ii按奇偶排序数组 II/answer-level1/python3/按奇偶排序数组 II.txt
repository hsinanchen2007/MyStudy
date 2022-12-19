一开始想到遍历该数组，用两个变量分别记录当 A[i] 为奇数时，i 是偶数和当 A[i] 为偶数时，i 是奇数的情况，然后交换这两个变量对应的数。
```
class Solution(object):
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        o = -1
        j = -1
        i = 0
        while i < len(A):
           if i%2 ==0 and A[i]%2 ==1:
            j=i
           elif i%2 ==1 and A[i]%2 ==0: 
            o=i
           if j>=0 and o>=0:
            A[o], A[j] = A[j], A[o]
            o=-1
            j=-1
           i += 1
        return A
```
但这样就会存在一个问题，如果奇数位是偶数的情况连续出现两次，然后才出现偶数位是奇数，那第一次出现的奇数位是偶数将不会有机会进行交换，反之也有同样的问题。如：[648,831,560,986,192,424,997,829,897,843]，其中986无法进行交换。后来改用列表存储问题就得到了解决。
```
class Solution(object):
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        o = []
        j = []
        i = 0
        while i < len(A):
           if i%2 ==0 and A[i]%2 ==1:
            j.append(i)
           elif i%2 ==1 and A[i]%2 ==0: 
            o.append(i)
           if len(j)>0 and len(o)>0:
            n1=j.pop()
            n2=o.pop()
            A[n1], A[n2] = A[n2], A[n1]
           i += 1
        return A
```