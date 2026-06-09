### 解题思路
python3 哈希表实现，遍历一次数组，一边查找一边向哈希表中插入数据
时间复杂度：O(n)
空间复杂度：O(n)

### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        hashmap={}
        length=len(numbers)
        for i in range(length):
            rest=target-numbers[i]
            if rest in hashmap:
                return [hashmap[rest]+1,i+1]
            hashmap[numbers[i]]=i
```