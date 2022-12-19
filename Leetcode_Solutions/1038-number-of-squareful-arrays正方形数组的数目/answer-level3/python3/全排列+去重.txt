```
class Solution:
    def numSquarefulPerms(self, A: List[int]) -> int:
        # 要完成的功能
        # 1.判断两数相加是否一个完全平方数, 用int(a**.5) == a**.5完成
        # 2.数组排序
        # 3.建图
        # 4.遍历dfs，注意去重， 参考47题

        # 用Hash去记录可能的完全平方数的组合吧，应该要比每次计算快点
        # 建图
        if len(A) == 1: return 0
        Hash = {}
        A = sorted(A)
        n = len(A)
        count = 0
        visited = [0]*len(A)
        for i in range(n):
            if i == 0 or A[i] != A[i-1]:
                if A[i] not in Hash:
                    Hash[A[i]] = {}
                for j in range(i+1, n):
                    if A[j] not in Hash[A[i]] and int((A[i] + A[j])**.5) == (A[i] + A[j])**.5:
                        Hash[A[i]][A[j]] = []
                        if A[j] not in Hash:
                            Hash[A[j]] = {}
                        Hash[A[j]][A[i]] = []

        def dfs(pos, length, n):
            nonlocal count
            tmp = pos
            if length == n:
                count += 1
                return
            for i in range(n):
                if (i > 0 and (visited[i-1] == 0 and A[i] == A[i-1])): #去重
                    continue
                if visited[i]:   # 如果已经visit过了
                    continue
                if A[i] not in Hash[A[pos]]: # 如果不能构成完全平方数
                    continue
                visited[i] = 1
                length += 1
                pos = i
                dfs(pos, length, n)
                pos = tmp
                length -= 1
                visited[i] = 0

        for i in range(n):
            if (i > 0 and A[i] == A[i-1]):   # 去重
                continue
            visited[i] = 1
            dfs(i, 1, n)
            visited[i] = 0
        return count


        
```
