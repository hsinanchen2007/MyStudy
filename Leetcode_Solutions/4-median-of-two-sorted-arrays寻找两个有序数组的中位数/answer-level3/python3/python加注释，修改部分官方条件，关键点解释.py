```
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        A, B, m, n = nums1, nums2, len(nums1), len(nums2)
        if m > n:
            A, B, m, n = B, A, n, m
        if n == 0:
            raise ValueError
        
        half_len = (m+n+1) // 2
        i = (0 + m) // 2
        # 0<=i<=m
        while i in range(m+1):
            # if m+n is odd, then +1 means j is moved one step right, so "left" is one number extra. if odd, medium == max_of_left
            j = half_len - i 
            if i < m and B[j-1] > A[i]:  # j > 0
                # i is too small, must increase it
                i += 1
            elif i > 0 and A[i-1] > B[j]:  # j < n
                # i is too big, must decrease it
                i -= 1
            else:
                # i is perfect, and chose the_max_left & 0
                
                # there is no A[i-1], so max_of_left = B[j-1] 
                if i == 0: max_of_left = B[j-1] 
                # there is no B[j-1], so max_of_left = A[i-1] 
                elif j == 0: 
                    max_of_left = A[i-1]
                # i&j exist, so chose the maximum of (A[i-1], B[j-1]) as max_of_left
                else: max_of_left = max(A[i-1], B[j-1])
                
                # odd, medium == max_of_left, no need to calculate min_of_right
                if (m+n) % 2 == 1:
                    return max_of_left
                
                # there is no A[i], so min_of_right = B[j-1] 
                if i == m: min_of_right = B[j]
                # there is no B[j], so min_of_right = A[j] 
                elif j == n: min_of_right = A[i]
                # i&j exist, so chose the minimum of (A[i], B[j]) as min_of_right
                else: min_of_right = min(A[i], B[j])
                
                # even, medium (max_of_left + min_of_right) / 2.0
                return (max_of_left + min_of_right) / 2.0
```
时间复杂度Log(m)<Log(n+m)，空间复杂度O(1)

已添加注释，对于几点进行说明：
1. 对于m+n的奇偶问题，在计算j的时候+1则代表当m+n为奇数时，j多移一位，即left多一位，则medium为max_of_left；同理，不+1则最后先判断返回min_of_right；
2. 边界问题，其实当j=0时，一定有i=m，m=n，此时可直接返回max_of_left与min_of_right；同理，j=n时，一定有i=0，m=n.但原代码包含了此条件；
3. 当m+n为奇数时，可直接返回medium为max_of_left，所以判断在计算min_of_right之前返回；
4. imin，imax两个变量没存在的必要，while的判断也无存在的必要，while 1也可以执行返回结果；其实half_len也无存在必要，不过节省计算时间；
5. 直接i++&i--，比imin++，imax--少循环次数，因偶数imin/imax加1除以2取整数得i仍然为原值，计算两次i才可以真正+1。
