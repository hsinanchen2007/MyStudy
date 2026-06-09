### 解题思路
#### 解法一 暴力求解
遍历`queries`中所有的数对，按要求将数字加到数组`A`指定的位置，并求出A中偶数的和，添加到`ans`尾部。

```python3
class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        ans = []
        for i in queries:
            A[i[1]] += i[0]
            res.append(sum[i for i in A if not i % 2])
        return ans
```
此算法看似简洁，在计算A中偶数和时每次都遍历一次数组，筛选出偶数，求和，并添加到一个列表中。
由于此算法时间、空间复杂度都很高，因此在处理很大的数据时，此算法超时。

#### 解法二 优化暴力算法：奇偶分析法
从暴力算法出发，由于暴力算法在创建`ans`数组、改变`A[queries[i][1]]`的步骤都是无法避免的，因此可以考虑优化计算偶数和的方法。
由于数组`A`中数的奇偶性可能会在操作后变化，而整数奇偶性的变化都是有规律可循的，因此采用逐步的奇偶分析法：

> 奇数 + 奇数 = 偶数
> 偶数 + 偶数 = 偶数 
> 奇数 + 偶数 = 奇数

从数论中的基本理论出发，可以得到如下代码：

### 代码

```python3
class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        ans = []
        base = 0                # 用于储存数组A中偶数的初始值
        for i in A:
            if not i % 2:
                base += i
        for i in queries:
            if A[i[1]] % 2:     # 考虑A中的数为奇数的情况
                if i[0] % 2:    # 如果加上一个奇数，则A[i[1]]变成偶数，符合要求
                    base += A[i[1]] + i[0]  # 由于每一次加都会产生影响，则改变base的值。凭空产生偶数，所有加上两个数
            else:               # 考虑A中的数是偶数的情况
                if i[0] % 2:    # 如果加上一个奇数
                    base -= A[i[1]]     # 生成奇数，原偶数消失
                else:           # 如果加上一个偶数
                    base += i[0]        # 生成偶数，增加加上的偶数的值
            ans.append(base)
            A[i[1]] += i[0]
        return ans
```