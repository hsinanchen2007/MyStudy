【分析】Array + Sort + Count
    （1）对区间[1, n]上的各个数i求各数位之和curSum，并存储映射curSum -> i至一哈希表dic(这里使用字典)；
    （2）将dic按值的长度递减排序；
    （3）排序后，显然dic中的第一对映射对应的键为最大组，然后扫描后续键值对，累加值长度 = 第一对映射值长度的个数。最终返回此个数即可。
    时间复杂度O(nlogn), 空间复杂度O(n)。
```
class Solution:
    def countLargestGroup(self, n: int) -> int:
        dic = collections.defaultdict(list)
        for i in range(1, n + 1):
            temp, curSum = i, 0
            while temp:
                curSum += temp % 10
                temp //= 10
            dic[curSum].append(i)
        dic = sorted(dic.items(), key=lambda k: len(k[1]), reverse=True)
        dic = list(dic)
        res = 1
        for i in range(1, len(dic)):
            if len(dic[i][1]) == len(dic[0][1]):
                res += 1
            else:
                break
        return res
```