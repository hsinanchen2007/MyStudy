思路很简单，A求和减去A不重复元素的和，除以(N-1)就是答案。照理这个写法应该遍历了2.5次（求和1次，取不重复元素1次，求不重复元素和0.5次），但结果反而不错。只能说明宁愿调库函数也不要自己发明创造吗。。。。
```
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        return int((sum(A)-sum(set(A)))/(len(A)/2-1))
```
