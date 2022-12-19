```
class Solution(object):
    def spiralOrder(self, matrix):
        def search(t, b, l, r, ans):
            print(t, b, l, r,)
            ans.extend(matrix[t, l:r])
            print(matrix[t, l:r])
            
            if t!= b: ans.extend(matrix[t:b,r])
            elif t== b: ans.append(matrix[t,r])
            print(matrix[t:b,r])
            
            if b != t: 
                if l == r:
                    ans.append(matrix[b,l])
                else:
                    ans.extend(matrix[b,l+1:r+1][::-1])
            print(matrix[b,l+1:r+1][::-1])
            
            if l!= r: ans.extend(matrix[t+1:b+1,l][::-1])
            print(matrix[t+1:b+1,l][::-1])

        m = len(matrix)
        if m == 0: return []
        n = len(matrix[0])
        if n ==0: return []
        layer = min(m,n) // 2 + min(m,n) %2
        ans = []
        import numpy as np 
        matrix = np.array(matrix)
        print(m,n)
        print(layer)
        for i in range(layer):
            t,b,l,r =i, m-i-1, i, n-i-1
            search(t,b,l,r,ans)
        return ans 
```
