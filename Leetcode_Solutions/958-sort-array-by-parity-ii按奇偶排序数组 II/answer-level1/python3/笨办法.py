```
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        new_arry = []
        Ou_num = [A[i] for i in range(len(A)) if A[i] % 2 == 0]
        Ji_num = [A[i] for i in range(len(A)) if A[i] % 2 != 0]
        for i in range(len(A)):
            if i % 2 == 0:
                new_arry.append(Ou_num.pop())  #注意这里不能用new_arry[i] = Ou_num.pop()
            elif i % 2 != 0:
                new_arry.append(Ji_num.pop())  # #注意这里不能用new_arry[i] = Ou_num.pop()
        return new_arry
```