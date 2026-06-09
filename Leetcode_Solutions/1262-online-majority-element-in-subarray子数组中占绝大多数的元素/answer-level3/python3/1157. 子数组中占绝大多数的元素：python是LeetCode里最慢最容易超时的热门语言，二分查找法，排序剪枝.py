已经不止一次碰到，相同算法其他语言可以过，python过不了的情况了。

Counter法，一开始能过，比赛的时候能过，现在过不了了，就算能过的时候也是在超时的边缘徘徊，一般都要2000ms+，目测是开题时候是3000ms及格。

原理也不难，就是计数，然后统计计数结果，统计数据结构比暴力循环for要快不少，理论上查询部分应该算是$O(n+m)$，其中n是数组长度，m是不重复的数字个数，m最大为n，综合最坏$O(2n)$，因为数据问题，系数最好不要忽略。

```py
class MajorityChecker:

    def __init__(self, arr: List[int]):
        self.arr = arr

    def query(self, left: int, right: int, threshold: int) -> int:
        count = collections.Counter(self.arr[left: right + 1])
        for num, ct in count.items():
            if ct >= threshold:
                return num
        return -1
```

索引二分查找，超时，把数字的索引以列表的形式记录进以数字为key的字典里，每次通过二分查找来找到包含的索引数量，再和threshold比较就行，理论上平均应该是$O(\frac{\sum_{i = 1}^{m}2*log(len(d[i]))}{m})$，理论最坏情况取$m=\sqrt{n}$，理论综合最坏 $O(log(n))$，实际上最坏应该是每个数不同$m=n$，每个数都必须验证一次，所以查询最坏应该是$O(n)$，完全相同的代码结构，其他语言的基本都能过。

```py
class MajorityChecker:

    def __init__(self, arr: List[int]):
        self.idx = collections.defaultdict(list)
        for i, num in enumerate(arr):
            self.idx[num] += [i]

    def query(self, left: int, right: int, threshold: int) -> int:
        for num in self.idx:
            if len(self.idx[num]) >= threshold:
                l_idx = bisect.bisect_left(self.idx[num], left)
                r_idx = bisect.bisect(self.idx[num], right)
                if r_idx - l_idx >= threshold:
                    return num
        return -1
```

既然对数级的算法都过不了，没办法只能针对测试优化了一下，把字典的遍历序按索引数量从大到小排列了一下，再剪了下枝，勉强通过了，不剪还过不了。

更改遍历序只是提高了中奖率，最坏查询时间复杂度理论上和上面是一样的，但实际复杂度应该会降低不少，毕竟大部分答案肯定是由索引数量多的数字产生。

不过我个人十分想吐槽的是不剪枝会超时，明明剪去的只是无效循环而已，只能说明python就连空转的for循环都慢到家了，就一个简单len()和if就可以占用这么多时间。

通过时间644ms仅供参考，目前可以生成柱状图了，还是最快的。

```py
class MajorityChecker:

    def __init__(self, arr: List[int]):
        self.idx = collections.defaultdict(list)
        for i, num in enumerate(arr):
            self.idx[num] += [i]
        self.idx = sorted(self.idx.items(), key = lambda x: -len(x[1]))

    def query(self, left: int, right: int, threshold: int) -> int:
        for num, idxs in self.idx:
            if len(idxs) >= threshold:
                l_idx = bisect.bisect_left(idxs, left)
                r_idx = bisect.bisect(idxs, right)
                if r_idx - l_idx >= threshold:
                    return num
            else:
                break
        return -1
```
![image.png](https://pic.leetcode-cn.com/add930d6353db8e72e65f72d32698fb6af57e4e498f999516d817311e1343f31-image.png)
