教训：先明确思路，不是上来就撸代码。

1. 递归生成全排列。
2. 过滤合法的全排列。
3. 找到最大时间值。
4. 格式化输出。

明确思路之后再撸，不是边撸边想，可以少走弯路。注意通过输出验证设想。

```
class Solution(object):
    def largestTimeFromDigits(self, A):
        """
        :type A: List[int]
        :rtype: str
        """
        # 1.生成全排列 
        r = []

        def permutation(A, m, n):
            s = []
            if m == n:  
                s.append(A[0])
                for i in range(1,n):
                    s.append(A[i])
                if s not in r:
                    r.append(s)  
            else:
                for i in range(m, n):
                    if A[m] != A[i]:
                        A[m], A[i] = A[i], A[m]
                    permutation(A, m+1, n)
                    if A[m] != A[i]:
                        A[m], A[i] = A[i], A[m]                  
        permutation(A,0,4)
        #print(len(r),r)
        
        #2.过滤 r 中合法的元素
        s = []
        for a in r:            
            if a[0]*10+a[1] < 24 and a[2]*10+a[3] < 60:
                s.append(a)
        #print(len(s),s)

        #2. 如果结果为空，返回空串
        #print(s)
        if len(s) == 0:
            return ""
        #3. 如果只有一个合法结果，直接返回
        elif len(s) == 1:
            a = s[0][0]*10 + s[0][1]
            b = s[0][2]*10 + s[0][3]
        #4. 如果多于一个合法结果，选择最大时间值
        else:
            a = b = 0  #a,保存小时数；b,保存分钟数             
            for x in s:
                if a < x[0]*10 + x[1]:
                    a = x[0]*10 + x[1]
                    b = x[2]*10 + x[3]
                if a == x[0]*10 + x[1]:
                    if b < x[2]*10 + x[3]:
                        b = x[2]*10 + x[3]    
        #5. 格式化输出
        return '{:0=2}'.format(a) + ":" +'{:0=2}'.format(b)
```
