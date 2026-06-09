class Solution:
    def prevPermOpt1(self, A: List[int]) -> List[int]:

        stack=[]
        stack.append(A.pop())#单调栈

        while A and A[-1]<=stack[-1]:
            stack.append(A.pop())       
        if not A:
            return stack[::-1]
        
        idx1=len(A)-1

        while stack and stack[-1]<A[idx1]:#找比自己小的里面找最大的
            A.append(stack.pop())
        idx2=len(A)-1
        while A[idx2]==A[idx2-1]:#而且是最近的
                idx2-=1
            
        A[idx1],A[idx2]=A[idx2],A[idx1]#交换
        while stack:
            A.append(stack.pop())
        return A