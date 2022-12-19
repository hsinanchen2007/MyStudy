# 使用指针保存位置
1. 对于两个数，其升序排列一定比降序排列小。这题的关键就是从前往后遍历，寻找最后一对升序组合，记下位置former|latter. 
2. 第二步操作是遍历latter之后的数，寻找最小的且大于former的数，将这个数和former交换位置
3. 将latter开始的数重新使用升序排列
```
class Solution:
    def nextGreaterElement(self, n: int) -> int:
        if n < 10 or n > 2 ** 31 -1 : return -1
        stack = []
        while n >= 1:
            a = n % 10
            n = n // 10
            stack.append(a)
        stack.reverse()
        former = None
        latter = None
        for ind in range(len(stack)):
            if ind + 1 < len(stack):
                if stack[ind + 1] > stack[ind]:
                    former = ind
                    latter = ind+1
        if former is not None:
            aim = latter
            for j in range(latter, len(stack)):
                if stack[j] > stack[former] and stack[j] < stack[aim]:
                    aim = j
            tmp = stack[aim]
            stack[aim] = stack[former]
            stack[former] = tmp
            stack = stack[0:latter] + sorted(stack[latter:], key=lambda x: x)    
        else:
            return -1
        res = 0
        for i in range(len(stack)):
            if i == 0:
                res = stack[i]
            else:
                res = res * 10 + stack[i]
        if res > 2 ** 31 -1: return -1
        return res
```
