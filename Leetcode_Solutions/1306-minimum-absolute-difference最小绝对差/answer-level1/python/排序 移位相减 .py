### 解题思路
如果是有序序列 最小的差肯定是相邻元素 新建一个数组 用来存放移位的数组 这样两个数组对应元素相减就是相邻元素的差 如果差小于当前最小值 就舍弃原先的最小值序列 如果差等于当前最小值 那么就将当前最小值append
假如序列是a1 a2 a3 a4 那么最小值就是a2-a1 a3-a2 a4-a3中的最小值 可以看成 [a2,a3,a4] - [a1,a2,a3] 将原始序列【a1 a2 a3 a4】移位变成[0,a1,a2,a3] 两个列表相减
另外需要一个存储最小值min_value 当当前序列差小于最小值 则抛弃以前的最小值序列差 更新为当前的 如果序列差等于最小值 将最小值序列差加入到数组中
执行用时 :
348 ms
, 在所有 python 提交中击败了
96.43%
的用户
内存消耗 :
23.4 MB
, 在所有 python 提交中击败了
100.00%
的用户
### 代码

```python
class Solution(object):
    def minimumAbsDifference(self, arr):
        """
        :type arr: List[int]
        :rtype: List[List[int]]
        """
        arr.sort()
        zerio = [0]+arr[:-1] 
        min_value = 100000000000000
        res = [] # 用来存放结果 
        for i in range(1, len(arr)):
            if arr[i]-zerio[i] < min_value:  # 如果当前序列差小于最小值 抛弃以前的差序列 更新
                min_value = arr[i]-zerio[i]
                res = [[zerio[i], arr[i]]]
            elif arr[i]-zerio[i] == min_value: # 如果当前序列差等于最小值 序列加入到最小值差序列中
                res.append([zerio[i], arr[i]])
        return res

```