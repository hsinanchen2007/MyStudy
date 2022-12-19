### 解题思路
1、初始化类
2、把add进来的val值追加到数组后面
3、数组进行降序排序
4、返回第k大的数，即k-1索引的值

### 代码

```python3
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k=k
        self.nums=nums
        

    def add(self, val: int) -> int:
        self.nums.append(val)
        self.nums.sort(reverse=True)
        #打印第8个用例会出现超出输出限制
        #print(self.nums)
        #每次add的值都一直在列表中，删除了返回值就不对
        #self.nums.remove(val)
        return self.nums[self.k -1]

```