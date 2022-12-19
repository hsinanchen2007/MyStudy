**大概思路**
将区间按起点从小到大排序，然后从左到右扫一遍找最远的右端点。交错或包含的区间就合并。

**算法**
- 使用 `lambda` 匿名函数，对intervals进行排序，声明保存结果的 `result` 变量。
- 遍历 `intervals`。
  - 如果还未曾向 `result` 中添加过内容（也就是 `result` 是空的）或者是间隔了的区间，就添加当前数据。
  - 如果 `result` 非空，且满足合并条件（前一个区间的 `end` 大于等于后一个区间的`start`），就合并。
- 返回 `reslut`。

**代码**
```python
class Solution:
    def merge(self, intervals):
        intervals = sorted(intervals, key=lambda x: x[0])  # 使用lambda匿名函数，对intervals进行排序。
        result = []  # 声明保存结果的result变量
        for interval in intervals:  # 遍历intervals
            if len(result) == 0 or result[-1][1] < interval[0]:  # 如果还未曾向result中添加过内容或者是间隔了的区间，就添加当前数据。
                result.append(interval)
            else:  # 如果result非空，且满足合并条件（前一个区间的end大于等于后一个区间的start），就合并。
                result[-1][1] = max(result[-1][1], interval[1])  # 合并方法是选择要合并的两个区间中end较大的那个来作为新区间的end。
        return result  # 返回result

print("leet code accept!!!")
Input = [[[1,4],[2,3]], [[1,4],[0,4]], [[1,3],[2,6],[8,10],[15,18]], [[1,4],[4,5]]]
Answer = [[[1,4]], [[0,4]], [[1,6],[8,10],[15,18]], [[1,5]]]

if __name__ == "__main__":
    solution = Solution()
    for i in range(len(Input)):
        print("-"*50)
        reslut = solution.merge(Input[i])
        print(reslut == Answer[i])
```