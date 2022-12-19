
#### 核心思路：遍历时，查看target和当前数的差是否已经遍历过


思考：

1. 尽量只遍历一次
2. 要检查之前遍历的数，所以需要一个集合
3. 遍历时，查找的是差值（target与当前数的差）在不在集合中
4. 当没找到时要将当前数存储起来，数存集合
5. 当找到时，要返回集合中某个数的下标，要根据数查到下标，用字典比较合适
6. 因为当前值也要返回下标，所以用enumerate

综上，需要一次循环，数据结构需要一个集合和一个字典，要记录下标所以需要enumerate函数


伪代码：

    遍历数组
        判断（target - 当前数)是否在集合中
        如果在
            返回两个下标
        如果不在
            将当前数存入集合
            将当前数的下标存入字典
    遍历完也没有，返回空




将伪装代码翻译成代码：

```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # 定义集合和字典
        myset = set()
        mydict = {}
        # 带索引遍历数组
        for index, value in enumerate(nums):
            # 判断
            if (target - value) in myset:
                index2 = index
                index1 = mydict[target - value]
                return [index1, index2]
            else:
                myset.add(value)
                mydict[value] = index
        return []

```


