### 解题思路
从右往左找需要交换的位数，然后再排序，加上没比较的，注意判断有没有超范围
![UC截图20200108154439.png](https://pic.leetcode-cn.com/b4ef94269607101fa903abc43834dc32499a388da3059128492dce387e938938-UC%E6%88%AA%E5%9B%BE20200108154439.png)


### 代码

```python3
class Solution:
    def nextGreaterElement(self, n: int) -> int:
        if n >= pow(2,31):
            return -1
        string = list(str(n))
        length = len(string)
        res = ''
        for i in range(length - 1, -1, -1):
            res = string[i] + res
            if sorted(res,reverse=True) == list(res):
                continue
            else:
                for num in sorted(res):
                    if num > string[i]:
                        break
                l = list(res)
                l.pop(l.index(num))
                str1 = [num] + sorted(l)
                string[:] = string[:i] + str1
                return int(''.join(string)) if int(''.join(string)) < pow(2,31) else -1

        return -1
```