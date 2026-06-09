## 分析：
- 最近一直在做数组的题目，这种题一眼就想到了计数排序，唯一的不同就是在排序的时候要按arr2的顺序排。
- 我的代码是遍历了两边，第一遍是遍历arr2，第二遍遍历整个排序，如果你有更好的计数排序方法，欢迎你告诉我。
- 不知道你们有没有遇到过计数排序，我尽可能的把注释写的详细一点，好给没接触过的人参考一下。（反正多遇到几次就写的很熟了）
- 其实就是用到了hash表。

## 代码：
```python
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        arr = [0 for _ in range(1001)]  # 由于题目说arr1的范围在0-1000，所以生成一个1001大小的数组用来存放每个数出现的次数。
        ans = []  # 储存答案的数组。
        for i in range(len(arr1)):  # 遍历arr1，把整个arr1的数的出现次数储存在arr上，arr的下标对应arr1的值，arr的值对应arr1中值出现的次数。
            arr[arr1[i]] += 1  # 如果遇到了这个数，就把和它值一样的下标位置上+1，表示这个数在这个下标i上出现了1次。
        for i in range(len(arr2)):  # 遍历arr2，现在开始要输出答案了。
            while arr[arr2[i]] > 0:  # 如果arr2的值在arr所对应的下标位置出现次数大于0，那么就说明arr中的这个位置存在值。
                ans.append(arr2[i])  # 如果存在值，那就把它加到ans中，因为要按arr2的顺序排序。
                arr[arr2[i]] -= 1  # 加进去了次数 -1 ，不然就死循环了。
        for i in range(len(arr)):  # 如果arr1的值不在arr2中，那么不能就这么结束了，因为题目说了如果不在，剩下的值按照升序排序。
            while arr[i] > 0:  # 同样也是找到大于0的下标，然后一直加到ans中，直到次数为0。
                ans.append(i)
                arr[i] -= 1
        return ans  # 返回最终答案。
```

## 复杂度分析：
- 时间复杂度：O(n+m) n 为arr2的长度，m为arr1的长度。arr的长度固定是1001，所以就算arr中只有1个有次数,也要遍历1001遍。
- 空间复杂度：O(n) n 为arr1的长度。