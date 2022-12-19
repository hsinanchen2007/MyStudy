主要算法就是贪心，本质还是排序，先把负数的翻成正的，看剩余翻转次数的奇偶性来确定是否把最小的正数翻成负的，然后求和。

有同学说这题题干说只能原地取负，不能原地排序，但这题有没有限制空间，复制出来一样是排序，限制修改只是多此一举。

排序也分两种，一种是快排，然后一个一个翻，再个就是桶排，一桶一桶翻，最后都是求和，没有本质区别，速度上区别也不大。

快排：

```py
class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        A.sort()
        for i in range(K):
            if A[i] < 0:
                A[i] = -A[i]
            else:
                A[i] -= 2 * ((K - i) % 2) * min(A[i], A[i - 1]) 
                #根据奇偶性在数组判断是否减去最小整数，最后都是一起求和，所以只要把这一项加进数组就行
                break
        return sum(A)
```

桶排：

```py
class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        c = [0] * 201
        for i in A:
            c[i] += 1
        p = [[i, c[i]] for i in range(-100, 101) if c[i] > 0]
        for i in range(len(p)):
            if p[i][0] < 0:             #如果小于零就按桶翻转
                if K > p[i][1]:         #翻转次数大于桶的容量就整个桶翻转
                    K -= p[i][1]
                    p[i][0] = -p[i][0]  #直接翻转序号就可以
                else:
                    p[i][1] -= 2 * K    #相当于部分翻转
                    break
            else:
                p += [[(K % 2) * min(p[i][0], p[i - 1][0]), -2]]
                break
        return sum([i * ic for i, ic in p])
```
