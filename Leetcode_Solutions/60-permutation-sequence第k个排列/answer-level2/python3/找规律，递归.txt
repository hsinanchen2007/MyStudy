
```python []
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        self.res_index = [0]*n
        self.choice = [x for x in range(1,n+1)]
        if k == 1:
            return ''.join([str(x) for x in self.choice])
        k-=1
        
        self.solve(2,1,k)
        res = ''
        for i in self.res_index:
            res += str(self.choice[i])
            self.choice = self.choice[:i] + self.choice[i+1:]
        return res
        
        
    def solve(self,i,last,k):
        current_number = self.choice[i-1]
        if current_number*last<=k:
            k = self.solve(i+1,last*current_number,k)
        res = 0
        for x in range(1,current_number+1):
            if x*last > k:
                break
            res += 1
            
        self.res_index[-i] = res
        return k-res*last
            
```

