> 思路：每两个非'.'之间的处理是独立的，记录下来依次处理即可。
```python
class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        
        def process(dominoes,i,j):
            if dominoes[i] == 'L' and dominoes[j] == 'R':
                return
            if dominoes[i] == 'L' and dominoes[j] == 'L':
                for k in range(i+1,j):
                    dominoes[k] = 'L'
            if dominoes[i] == 'R' and dominoes[j] == 'L':
                k = (j-i-1)//2
                for m in range(1,k+1):
                    dominoes[i+m] = 'R'
                    dominoes[j-m] = 'L'
            if dominoes[i] == 'R' and dominoes[j] == 'R':
                for k in range(i+1,j):
                    dominoes[k] = 'R'
        
        dominoes = 'L'+dominoes+'R'
        i = 0
        tuples = []
        while i < len(dominoes):
            j = i+1
            while j < len(dominoes) and dominoes[j] == '.':
                j += 1
            if j < len(dominoes):
                tuples.append((i,j))
            i = j
        
        dominoes = list(dominoes)
        print(dominoes)
        #print(tuples)
        for i,j in tuples:
            process(dominoes,i,j)
        return ''.join(dominoes)[1:-1]
```