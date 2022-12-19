### 解题思路
1、	List常用函数len(),append(),pop();
2、	List访问可以使用反向下标索引访问-1，-2等，例如L[-2]；
3、	Python内置函数sum()，对系列进行求和计算；

### 代码

```python3
class Solution:
    def calPoints(self, ops: List[str]) -> int:
        if len(ops) <0  or len(ops) > 1000:
            return 0 
        pointlist=[]
        for str_i in ops:
            if str_i == "C":
                if len(pointlist) > 0:
                    pointlist.pop()
            elif str_i == "D":
                if len(pointlist) == 0:
                    pointlist.append(0)
                else:
                    pointlist.append(2 * pointlist[-1])
            elif str_i == "+":
                if len(pointlist) < 2:
                    pointlist.append(sum(pointlist))
                else:
                    pointlist.append(pointlist[-1] + pointlist[-2])
            else:
                pointlist.append(int(str_i))
        return sum(pointlist)

```