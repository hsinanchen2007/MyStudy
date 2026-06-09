顺着提示想，为了用一次SWAP让这个数变小，那么我们肯定要把： 1个在较靠后的小数字， 和1个在较靠前的大数字交换。 因为在靠前的数字有更大的weight。 然后这里 贪心策略贪心在，你是为了找到“最大的”一种swap使得swap后比原来小，那么你希望被交换的尽可能靠后，因为如果交换发生在较靠前就会对整个数字的大小产生很大的影响。 那么我们就可以从数组A的末尾开始，对于位置j，寻找在A[j+1:]中所有比A[j]小的数字里最大的一个和他交换。




```
class Solution(object):
    def prevPermOpt1(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        if len(A)==1 : return A
        for i in range(len(A)-2,-1,-1):
            max_min = None
            index = None
            for j in range(i+1,len(A)):
                if A[j] < A[i]:
                    if max_min ==None:
                        max_min = A[j]
                        index =j 
                    else:
                        if A[j]>max_min:
                            max_min = A[j]
                            index = j
            if index != None:
                A[i], A[index] = A[index], A[i]
                break
        return A
                
                

```
