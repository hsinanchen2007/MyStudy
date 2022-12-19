做完之后，看到大家都用二分查找，就发下我的思路。感觉也比较简单，高效。一次排序+一次遍历。

1、从大往小倒排序。结尾多加一个0，本题所有数字大于0，因此加0保证最后总和可以下降到小于target(见后)
2、维护一个总和sums，在总和大于target的时候，sums - 前后两个数字的差 * 目前位置前缀长度。
3、这样子一直减少sums，同时移动指针，直到sums小于target。这时答案就在当前值和前一个值之间。
4、把 target - sums 这部分平均分配给前面所有元素，可以得到最后答案。

```
class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        arr.sort(reverse = True)
        arr.append(0)
        sums, pos = sum(arr), 0
        while sums > target:
            sums -= (arr[pos] - arr[pos + 1]) * (pos + 1)
            pos += 1
        if pos:
            div, mod = divmod(target - sums, pos)            
            return arr[pos] + div + 1 * (mod > pos / 2)
        else: return arr[pos]
```
