### 方法一：使用集合
我们遍历一遍数组，判断 `nums[i]` 是否存在于集合中，如果存在，则返回该值；如果不存在，将该值添加到集合中。

#### 代码


```python [] 
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        count = set()
        for i in nums:
            if i in count:
                return i
            else:
                count.add(i)
```

```cpp []
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        set<int> count;
        for(auto i:nums){
            if(count.count(i) == 1){
                return i;
            }else{
                count.insert(i);
            }
        }
        return 0;
    }
};
```
#### 复杂度分析
- 时间复杂度：$O(N)$。最坏条件下，我们遍历了整个数组。
- 空间复杂度：$O(N)$。使用了哈希表。

在这里，将集合换成哈希表实现也可以。其中，哈希表的格式为 `{值：索引}`。
```python []
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        dic = {}
        for index, value in enumerate(nums):
            if value in dic:
                return value
            else:
                dic[value] = index
```

### 方法二：排序
思路很简单，将数组排序，相同的数会挨在一起，因此如果碰到两个相邻的数相等，立即返回即可。但是排序会花费 $O(Nlog N)$ 的时间复杂度。
#### 代码
```python []
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        for i in range(1, n):
            if nums[i] == nums[i - 1]: 
                return nums[i]
```
#### 复杂度分析
- 时间复杂度：$O(Nlog N)$，对数组进行排序。
- 空间复杂度：$O(1)$。

### 方法三：原地实现
注意题目中提到 “长度为 $n$ 的数组 $nums$ 里的所有数字都在 $0～n-1$ 的范围内”。因此我们通过交换 `nums[i]` 和 `nums[nums[i]]` 使得数组元素等于索引，这样如果再次找到一个相同数字，但索引不同，则表明找到了重复数字。
#### 代码
```python []
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        for idx, val in enumerate(nums):
            if idx != val and nums[val] == val: return val # 找到重复数字
            nums[val], nums[idx] = nums[idx], nums[val]
```
#### 复杂度分析
- 时间复杂度：$O(N)$，对数组进行一趟遍历。
- 空间复杂度：$O(1)$，没有使用额外空间，对数组进行原地修改。

欢迎提供c++解法
如有问题，欢迎讨论~