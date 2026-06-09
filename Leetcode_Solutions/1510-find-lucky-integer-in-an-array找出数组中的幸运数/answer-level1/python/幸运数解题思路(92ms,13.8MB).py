### 解题思路
此处撰写解题思路
1.用sorted方法获取去重后的每个元素
2.遍历记录每个元素出现的次数，并生成新的‘元素：出现次数‘字典表
3.过滤掉元素值不等于出现次数的成员
4.对字典表重新排序-升序
5.如果字典表为空返回-1，否则返回最后(最大)一个成员的值
### 代码

```python3
class Solution:
    def findLucky(self, arr: List[int]) -> int:
        arr_sorted = sorted(arr)
        arr_set = set(arr)
        dt = {}
        for i in arr_set:
            count = 0
            for j in arr:
                if i == j:
                    count += 1
            dt[i] = count
        print(dt)
        for k in list(dt.keys()):
            if k != dt[k]:
               dt.pop(k)
       
        if len(dt) > 0:
           list_sorted = sorted(dt.items(),key=lambda x:x[1])
           rst = list_sorted[-1][1]
        else:
           rst = -1
        return rst
```