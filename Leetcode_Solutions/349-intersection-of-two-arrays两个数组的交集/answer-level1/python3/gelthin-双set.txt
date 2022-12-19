### 解题思路
使用两个 set 取交集。
set() 间的运算：

+ 交: x&y
+ 并: x|y
+ 差: x-y
+ 对称差集：x^y
+ 判断两个集合是否相交：x.isdisjoint(y) 若相交则返回 False
+ 判断包含和被包含的关系： y0.issubset(y); y.issuperset(y0)

构造 set() 的运算：

+ x.add(obj) #往集合中添加一个元素
+ x.update(obj)  #往集合x中添加obj中的所有项集，obj可以是list，set中的元素，也可以是dict中的键值
+ x.remove(obj) #删除obj
+ x.pop() #随机弹出某个元素
+ x.discard(obj) #删除数据obj


### 代码

```python3
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list(set(nums1) & set(nums2))
```