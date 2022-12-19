### 解题思路
由于最大10万，317 * 317已经超过最大值10万了，所以我们用这个上界
确定低于317的质数一共有66个质数 prime_nums = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317]  66个
然后依次去分解质因数...
分解后生成倒排索引表

比如2，4，6，9 生成的索引表类似 {2: [2, 4, 6], 3: [9, 6]}
然后 2和4是联通的，4和6的是联通的，9和6是联通的，直接使用并查集，合并。。
合并后，结果就是最大并查集大小。

分解质因数，时间复杂度类似66 * 10(认为平均有10个不同的质因数吧) * N
倒排索引总大小类似和上面类似，并查集合查询可以看作线性复杂度。

总之时间复杂度类似66 * 10(认为平均有10个不同的质因数吧) * N（2万个数字） * 3（一共算了三次）

O(N)， 前面的常数大小1980...


### 代码

```python
class Solution(object):

    def largestComponentSize(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        dic2 = {}

        def union(k, v):
            if k not in dic2:
                dic2[k] = k
            if v not in dic2:
                dic2[v] = v
            dic2[check(dic2[k])] = check(v)

        def check(k):
            if dic2[k] != k:
                dic2[k] = check(dic2[k])
            return dic2[k]
        # 由于最大10万，317 * 317已经超过最大值10万了，所以我们用这个上界，直接写死
        prime_nums = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317]
        dic = {}
        for v in A:
            new_v = v
            while new_v > 1:
                divide = new_v
                for c in prime_nums:
                    if new_v % c == 0:
                        divide = c
                        break
                    if c ** 2 > new_v + 10:
                        break
                if divide not in dic:
                    dic[divide] = []
                dic[divide].append(v)
                new_v = new_v / divide
        for k in dic:
            dic[k] = list(set(dic[k]))

        for nums in dic.values():
            k = nums[0]
            for v in nums:
                union(k, v)

        counter = {}
        for num in A:
            if num < 2:
                continue
            group_id = check(num)
            counter[group_id] = counter.get(group_id, 0) + 1

        return max(counter.values())
```