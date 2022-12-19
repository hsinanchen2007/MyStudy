### 解题思路
- 执行用时和内存仅仅击败了百分之个位数的用户，可以说算法比较辣鸡，但是个人认为思路比较好理解
1. 首先set一下去重
2. 然后用数组的count方法建立一个值-数量的字典
3. 接着把字典根据value进行倒序排序
4. 输出排序后前k个元素组成的列表
- 虽然很辣鸡，但是还是厚着脸皮发出来了hhh

### 代码

```python3
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # 先去重
        num_set = set(nums)
        # 然后建立值-数量的字典映射
        num_dict = {}
        for num in num_set:
            num_dict[num] = nums.count(num)
        res = []  # 用于存放最终结果的列表
        # 将字典根据value进行降序排序
        sorted_dict = sorted(num_dict.items(), key = lambda item:item[1], reverse=True)
        # 将sorted_dict的前k个元素加入到res中
        for i in range(k):
            res.append(sorted_dict[i][0])
        return res
```