class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        #长度不同直接报错
        if len(A)!= len(B): return False
        for i in range(len(A)):
            #假设我们的样本是亲密字符串
            #则当A,B中出现不同字符的时候，在A中向i后面的位置找到新字符（即B[i]）
            #假设新字符的下标为j
            #在A中交换A[i],A[j]应该能有A==B
            if A[i]!=B[i]:
                #如果在A中i后面的位置找不到新字符，尝试直接失败
                if B[i] not in A[i+1:]:
                    return False
                else:
                    #找到新字符位置
                    j=A.index(B[i],i+1)
                    #因为是字符串，采用节段方式比较
                    return A[:i]+A[j]+A[i+1:j]+A[i]+A[j+1:]==B
        #上述循环完成后，考虑A==B的情况
        #如果A(或者B)中存在重复字符，则可将重复字符互换，完成一次互换的任务
        for c in A:
            if list(A).count(c)>1:
                return True
        #A中字符均不重复，没有办法互换两个字符转换成B
        return False