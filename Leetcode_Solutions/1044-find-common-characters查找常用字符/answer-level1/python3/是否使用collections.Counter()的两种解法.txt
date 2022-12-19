```
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        # 1. using collections.Counter
        # from collections import Counter
        # ans = Counter(A[0])
        # for i in range(1, len(A)):
        #     ans &= Counter(A[i])
        # return list(ans.elements())
    
        # 2. don't use collections.Counter
        ans = []
        s = set(A[0])
        for i in s:
            num = min(a.count(i) for a in A)  # 计算A[0]中每一个字符，在列表所有字符串（包括A[0]）中出现的次数，去最小次数
            ans.extend(i*num)  # 这样顺序也不会有问题
        return ans
```
对于时间复杂度的分析，N = len(A), A中字符串的平均长度为M
#### 方法一：使用collections.Counter()时
- `ans = Counter(A[0])` 时间复杂度为O(M)
- `for i in range(1, len(A)): ans &= Counter(A[i])` 分析这里的时间复杂度要注意了
因为`Counter(A[i])`的时间复杂度为O(M)
`Counter(A[i]) & Counter(A[i+1])` 的平均时间复杂度为`min(len(Counter(A[i])), len(Counter(A[i+1])))`，[参考点我](https://stackoverflow.com/questions/8102478/intersection-complexity)，也就是O(M)；一共循环了N次
所以这个for循环总的时间复杂度为O(N \* M \* M)
- list(ans.elements()) 时间复杂度为O(M)))

所以最后总的时间复杂度为**O(N \* M \* M + 2M)**

#### 方法二：不使用collections.Counter()时
- `set(A[0])`的时间复杂度为O(M)
- `for i in s: num = min(a.count(i) for a in A) ans.extend(i*num)` 中
`a.count(i) for a in A`的时间复杂度为O(N*M), `min()`的时间复杂度为O(M))
- `ans.extend(i*num)`的时间复杂度为O(1); 一共循环了M次

所以最后总的时间复杂度为**O(N \* M \* M + M \* M)**

PS: 不要以为同一题提交运行时间越短，时间复杂度就越低，用时取决于leetcode后端运行用例时的服务器状态。有可能同一题，时间复杂度小的解法比时间复杂度大的解法用时更长。