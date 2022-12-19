```
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        # 1. brute force O(n**2)
        # count, N = 0, len(dominoes)
        # for i in range(N - 1):
        #     for j in range(i+1, N):
        #         if sum(dominoes[i]) == sum(dominoes[j]) and (dominoes[i][0] in dominoes[j]):
        #             count += 1
        # return count

        # 2. delete item when brute force
        ans = 0
        for i in range(len(dominoes) - 1):
            cnt = 1
            for j in range(len(dominoes) - 1, i, -1):
                if sum(dominoes[i]) == sum(dominoes[j]) and (dominoes[i][0] in dominoes[j]):
                    cnt += 1
                    dominoes.pop(j)  # do not use .remove() here
            ans += cnt * (cnt - 1) // 2
        return ans
        
        # 3. Hashable without extra space. O(n)
        # count = 0
        # for i, pair in enumerate(dominoes):
        #     dominoes[i] = pair[0]*10 + pair[1] if pair[0] >= pair[1] else pair[1]*10 + pair[0]
        # for v in collections.Counter(dominoes).values():
        #     count += v*(v - 1) // 2
        # return count
```
#### 1.暴力循环
- 这个大家都容易想到，通过两次for循环一个个找，找到了count+1；时间复杂度为O(n**n);
- 判断两个list是否为pair，我的写法是`if sum(dominoes[i]) == sum(dominoes[j]) and (dominoes[i][0] in dominoes[j]):`，也可以写成其它的
- 时间复杂度是**O(N\**N)**，会超时

#### 2.暴力循环的同时删除
- 首先要知道的是，假设dominoes中有如`[[1, 2], [2, 1], [1, 2], [2, 1]]`，那么这4个元素一共有6对pair，排列组合中的`C(4, 2) = 4 x (4 - 1) / 2 = 6`；
- pair找出来之后就删掉，数量通过`cnt * (cnt - 1) // 2`计算得到；
- 删掉元素之后下标会变化，所以`j`从后向前循环；
- 因为要删掉元素，所以在第二个循环体`for j in range(len(dominoes) - 1, i, -1):`中 **len(dominoes)** 是会不断变换的，别在最开头初始化`N = len(dominoes)`之类的然后调用
- 注意python列表中`.remove(item)`和`.pop(index)`的区别
- 其实最坏时间复杂度也是**O(N\**N)**，但leetcode不超时是因为循环过程了删掉了一些元素，在执行给定测试用例的时候，执行时间比第一种方法少了很多

#### 3.使用Hash表
- `[1, 2], [2, 1]`或`[1, 2], [1, 2]`是pair的话，小的放前面，大的放后面，转换成整数都是12
- 利用上面的规律把dominoes中的元素都计算出来
- 然后使用`collections.Counter(dominoes)`计算一下就好了，计算方法就是方法二中说的排列组合
- 时间复杂度是**O(N)**