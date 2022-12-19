```
def canThreePartsEqualSum(self, A: 'List[int]') -> bool:
    sum_A = sum(A)
    mean_A = sum_A / 3
    if mean_A % 1 == 0: 
        S = 0
        C = 0
        for i in range(len(A)-1): # 排除最后一项
            S += A[i]
            if S == mean_A:
                C += 1  
                S = 0 
                if C == 2: # 在除了A中除最后一项外，能找到两组的和与A/3相等；则必为true
                    return True
    return False  
```

