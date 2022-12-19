












    def longestMountain(A):
        n = len(A)
        res = 0
        i = 1

        while i < n:
            l = i - 1  # 左山脚，注意 i 是从 1 开始的
            while i < n and A[i] > A[i - 1]:
                i += 1
            
            if l == i - 1:  # 不是山坡
                i += 1
                continue
            
            r = i - 1  # 右山脚
            while r < n - 1 and A[r] > A[r + 1]:
                r += 1
                
            if r == i - 1:  # 不是山坡
                i += 1
                continue
            else:
                res = max(res, r - l + 1)
                i = r + 1  # 
            
        return res