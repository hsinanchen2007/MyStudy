### 解题思路
对数据先进行排序，然后进行遍历,。
因为输入的数据>=0，所以设置当前标志为cur=-1，对数据进行比较：
    如果 i <= cur，说明需要进行move，因为已经进行排好序了，所以move到比当前大1即可，然后记录move
    否则 让cur = i 没有move
最后输出tmp move的增量

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        tmp = 0
        cur = -1
        for i in A :
            if i <= cur :
                cur += 1
                tmp += cur - i
            else:
                cur = i
        return tmp
```