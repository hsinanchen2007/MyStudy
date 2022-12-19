- 要先把题目读懂，代码写出来之后再读一遍题目
```
class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        # 1. brute force O(n*n)
        # ans = []
        # for i in range(len(A)):
        #     A[queries[i][1]] += queries[i][0]
        #     ans.append(sum([v for v in A if v % 2 == 0]))  # 这里因为重复相加，导致时间复杂度变成了O(n*n)
        # return ans
    
        #  2. 分4种不同的情况，原来是奇数，相加后还是奇数的忽略 O(n)
        # ans = []
        # s = sum([v for v in A if v % 2 == 0])  # 这样的好处是后面不需要重复相加
        # for i in range(len(A)):
        #     index, value = queries[i][1], queries[i][0]
        #     tmp = A[index]
        #     A[index] += value
        #     if tmp % 2 == 1 and A[index] % 2 == 0:
        #         s += A[index]
        #     elif tmp % 2 == 0 and A[index] % 2 == 0:
        #         s += value
        #     elif tmp % 2 == 0 and A[index] % 2 == 1:
        #         s -= tmp
        #     ans.append(s)
        # return ans
        
        # 3. more graceful code with O(n)
        S = sum(x for x in A if x % 2 == 0)
        ans = []

        for x, k in queries:
            if A[k] % 2 == 0:  # 关键在这里，要换一个思维角度，不要像方法二一样分类，只要是偶数先减掉再说
                S -= A[k]
                
            A[k] += x
            
            if A[k] % 2 == 0:  # 只要是偶数就加上
                S += A[k]
            
            ans.append(S)
        return ans
```
