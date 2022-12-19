1. 这个是看了题解, 有2N个数, N + 1不同, 有一个元素是N个重复值. 只需要找那重复的就好了
```
class Solution(object):
    def repeatedNTimes(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        a = set()
        for i in A:
            if i in a:
                return i
            else:
                a.add(i)
```


2. dictionary 先统计再找值, 也不好
```
class Solution(object):
    def repeatedNTimes(self, A):
        dictionary = {}
        for i in A:
            if i in dictionary:
                dictionary[i] += 1
            else:
                dictionary[i] = 1

        N = len(A) // 2
        for key, value in dictionary.items():
            if value == N:
                return key
```

3. 开始方向错了, 用了比较蠢的方式, 超时
```
class Solution(object):
    def repeatedNTimes(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        set_A = sorted(set(A))
        N = len(set_A) - 1
        # 找到重复N次的那个元素
        for i in set_A:
            if A.count(i) == N:
                return i
```
