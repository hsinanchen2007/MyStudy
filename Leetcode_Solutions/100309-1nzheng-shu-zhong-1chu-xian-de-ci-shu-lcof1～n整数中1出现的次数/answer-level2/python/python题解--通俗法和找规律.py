### 递归遍历法
- 提供一个思路,这个方法超出时间限制
```
class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0
    
        def count_1(n):
            if n == 1:
                return 1
            count = 0
            temp = n
            while temp:
                if temp % 10 == 1:
                    count += 1
                temp = temp // 10
            # 或者用字符串匹配的形式也可以
            # string = str(n)
            # for i in string:
            #     if i == '1':
            #         count += 1
            return count + count_1(n-1)
   
        return count_1(n)
```



### 找规律
- 这个是参考大神的解法,我用python实现了一下,大家直接借鉴下吧!!
- [https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/javadi-gui-by-xujunyi/]()

### 代码

```python
class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0

        def count_1(n):
            if n <= 0:
                return 0
            string = str(n)
            high = int(string[0])
            low = pow(10, len(string)-1)
            last = n - high*low
            if high == 1:
                return  count_1(low-1) + last + 1 + count_1(last)
            else:
                return low + high*count_1(low-1) + count_1(last)
        return count_1(n)
```