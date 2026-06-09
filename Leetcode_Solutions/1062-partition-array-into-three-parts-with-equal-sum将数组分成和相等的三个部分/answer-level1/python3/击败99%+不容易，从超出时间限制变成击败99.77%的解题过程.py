### 解题思路
一上来的思路是计算数组和除以3得到每一段的和，统计整个数组能分成几段
求和先是直接偷懒使用的sum，提交后遇到了超时的问题，于是改成了挨个加起来求和：）
开始判断的n==3，遇到了n>3的情况，然后加了判断limit==0，后来经过思考，如果n>3, 那么`n*limit= 3*limit`,所以n>3的时候limit一定0，所以n>=3时返回True

### 代码
72 ms	18.7 MB
```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        n = 0
        s = 0
        # j = 0
        for i in range(len(A)):
            s += A[i]
            # s = sum(A[j:i+1])
            if s==limit:
                n += 1
                # j = i+1
                s = 0
        # n>3 一定limit=0
        if n >= 3:
            return True
        return False

        # if n == 3:
        #     return True
        # if m < 3:
        #     return False
        # if limit == 0 :
        #     return True
        # return False      
```
### 解题思路
提交通过后，开始看评论与题解，于是添加了一个判断sum(A)是否能被3整除的判断，不过感觉影响不大。
倒是看到使用双指针两面夹逼，所以试了一下，确实会快那么一丢丢，然后在看题解的过程中发现，如果和n>3的情况类似，如果s1==limit 且 s2==limit，那么剩下的部分就是`3*limit-2*limit=limit`啊，于是把判断条件减少了一部分，当然并没有什么大的影响

### 代码
68 ms	18.7 MB
```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        # 看解析添加的判断
        sumA = sum(A)
        if sumA%3 !=0:
            return False

        limit= sumA/3
        i  = 0
        j  = len(A)-1
        s1 = A[i]
        s2 = A[j]
        while i+1<j:
            if s1 == limit and s2 == limit: # and sum(A[i+1:j])==limit:
                return True

            if s1!=limit:
                i += 1
                s1+=A[i]
            if s2!=limit:
                j -= 1
                s2+=A[j]
        return False  
``` 
### 解题思路
上一步里既然双指针能判断两段等于就可以返回结果，那么for循环里一样可以啊，所以有了下面的代码。
n==2的时候，只要还没有遍历完，就可以得到True的结果。

### 代码
44 ms	18.8 MB
```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        # 看解析添加的判断
        sumA = sum(A)
        if sumA%3 !=0:
            return False

        limit= sumA/3
        n = 0
        s = 0
        for i in range(len(A)-1):
            s += A[i]
            if s == limit:
                n += 1
                s = 0
                if n==2:
                    return True
        return False
``` 