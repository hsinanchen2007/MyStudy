### 总体思路

题目的意思是把所有的糖果分成两份，其中一份要尽可能拥有最多种类的糖果。

假设糖果一共有 `x` 颗，糖果种类有 `y` 种，那么分成两份后每份有糖果 `x / 2`：

- 如果 `y >= x / 2`，那么可以直接拿出 `x / 2` 种糖果
- 如果 `y < x / 2`，那么最多也只能分配到 `y` 种糖果了

所以这道题只要求出糖果的种类 `y` 即可。而求出糖果种类的方法也有好几种。

### 解法一：字典

将糖果种类的数字值作为 key 存储在字典中，糖果一旦存在则进行标记，并将糖果种类加一。

```python []
class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        length = len(candies)
        each = length // 2
        type_dict = dict()
        type_cnt = 0
        
        for c in candies:
            if type_dict.get(c, 0) == 0:
                type_dict[c] = 1
                type_cnt += 1
        
        if type_cnt >= each:
            return each
        else:
            return type_cnt
```
```go []
func distributeCandies(candies []int) int {
    var candiesMap map[int]bool
    candiesMap = make(map[int]bool)
    var candiesCount = 0
    for i := 0; i < len(candies); i++ {
        candie := candies[i]
        _, ok := candiesMap[candie]
        // candie 不存在，开始计数
        if !ok {
            candiesMap[candie] = true
            candiesCount += 1
        }
    }
    var each = len(candies) / 2
    if candiesCount >= each {
        return each
    } else {
        return candiesCount
    }
}
```

- 时间复杂度 O(n)
- 空间复杂度 O(n)

### 解法二：集合

利用集合无重复元素的特性，将数据存入集合，从而求出糖果的种类。

```python
class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        each = len(candies) // 2
        candies_set = set(candies)
        return each if each <= len(candies_set) else len(candies_set)
```

- 时间复杂度 O(n)
- 空间复杂度 O(n)

### 解法三：先排序

先对数组进行排序，然后将相邻的数字进行对比，如果相邻数字不同，则说明出现了新种类的糖果。

```python []
class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        length = len(candies)
        each = length // 2
        candies.sort()
        count = 1
        for i in range(1, length):
            if candies[i] != candies[i - 1]:
                count += 1
        return each if each <= count else count
```
```go []
import (
    "sort"
)

func distributeCandies(candies []int) int {
    var length = len(candies)
    var each = length / 2
    var count = 1
    sort.Ints(candies)
    for i := 1; i < length; i ++ {
        if candies[i] != candies[i - 1] {
            count++
        }
    }
    
    if count >= each {
        return each
    } else {
        return count
    }
}
```

- 时间复杂度：O(nlogn)
- 空间复杂度：O(1)