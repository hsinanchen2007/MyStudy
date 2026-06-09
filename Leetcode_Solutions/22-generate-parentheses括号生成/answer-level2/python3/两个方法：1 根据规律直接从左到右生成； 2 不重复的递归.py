
方法1：
- 从左到右写括号，保证每一步之后')'，的个数不超过'('的个数（用sum变量控制）。另外用一个ups变量控制'('的个数不超过n。
测试结果 40 ms，内存 14.2MB

```
class Solution:
    def generateParenthesis(self, n):
        if n == 1:
            return ['()']
        p_s = ['()', '((']
        sums = [[0, 1, 0], [0, 1, 2]]
        ups = [1, 2]

        for step in range(n-1):
            num_p = len(p_s)
            for i in range(num_p):
                if ups[i] < n:
                    if sums[i][-1] > 0:
                        new_p = p_s[i] + ')('
                        new_sum = sums[i] + [sums[i][-1] - 1, sums[i][-1]]
                        new_ups = ups[i] + 1
                        p_s.append(new_p)
                        sums.append(new_sum)
                        ups.append(new_ups)

                    if sums[i][-1] > 1:
                        new_p = p_s[i] + '))'
                        new_sum = sums[i] + [sums[i][-1] - 1, sums[i][-1] - 2]
                        new_ups = ups[i]
                        p_s.append(new_p)
                        sums.append(new_sum)
                        ups.append(new_ups)

                    if ups[i] < n - 1:
                        new_p = p_s[i] + '(('
                        new_sum = sums[i] + [sums[i][-1] + 1, sums[i][-1] + 2]
                        new_ups = ups[i] + 2
                        p_s.append(new_p)
                        sums.append(new_sum)
                        ups.append(new_ups)

                    p_s[i] += '()'
                    sums[i] += [sums[i][-1] + 1, sums[i][-1]]
                    ups[i] += 1

                else:
                    p_s[i] += '))'
                    sums[i] += [sums[i][-1] - 1, sums[i][-1] - 2]

        return p_s
```



方法2：
递归
- 把‘（’看作1，‘）’看作-1，问题变成N个1和N个-1组合，任意前i（i=1...2N）个数的和不小于0；
- 或者看作一个点从(0,0)点往右移动2N步，每一步x+1， y+1或者-1，点不能越过x轴，所有的括号组合可以看作该点从(0,0) 到 (2N, 0)的所有符合条件的路线。

- N 时的所有路线集合称作T(N)
- T(N)可以按照第一个 y=0 的点的 x 坐标（不算起始点，xi=2i i=1,2,3...N）不同分成不同的组，称作 T(N, i)
1. 把T(N, i)分成左右两个部分 T(N, i)_left, T(N, i)_right
2. 根据T(N, i)_left的性质，即(0,0)和(0,2i)之间没有y=0点，可以很容易看出: T(N, i)_left = '(' + T(i-1)中所有括号组合 + ')'
3. T(N, i)_right = T(N-i)
- 这样就可以递归了，且不会出现重复情况
测试结果 56 ms，内存 13.9MB

```
class Solution:
    def generateParenthesis(self, n):
        p_dict = {1: ['()']}

        def p_gen(n, p_dict):
            if n in p_dict:
                return  p_dict[n]
            else:
                p_prev = p_gen(n-1, p_dict)
                p_n = ['(' + p + ')' for p in p_prev]
                for i in range(1, n):
                    if i == 1:
                        left = p_gen(i, p_dict)
                    else:
                        left = p_gen(i-1, p_dict)
                        left = ['(' + p + ')' for p in left]
                    right = p_gen(n-i, p_dict)
                    for p_left in left:
                        for p_right in right:
                            p_n.append(p_left + p_right)
                p_dict[n] = p_n
                return p_n

        rs = p_gen(n, p_dict)
        return rs
```