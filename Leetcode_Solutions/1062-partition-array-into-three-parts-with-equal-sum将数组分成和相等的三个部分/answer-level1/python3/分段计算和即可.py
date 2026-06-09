```
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        s = sum(A)
        
        if s % 3 != 0:
            return False

        s = s//3

        tmp_s = 0
        n = len(A)
        cnt = 0
        for i in range(n):
            tmp_s += A[i]
            if tmp_s == s:
                cnt += 1
                tmp_s = 0
                
        if cnt >= 3:
            #大于是为了处理和为 0 的情况
            return True
        return False
```
