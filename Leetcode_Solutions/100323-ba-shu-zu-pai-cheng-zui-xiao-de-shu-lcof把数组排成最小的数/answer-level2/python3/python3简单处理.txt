### 解题思路
例如数组test = [3, 30, 34, 5, 9]
![image.png](https://pic.leetcode-cn.com/19c699aa9afa2e292f860649a6e86a573ff3cc63c4836998956af8b6fd3a461f-image.png)
例如'30' + '3' = '303'
从小到大排序：303 < 330, 确定30一定在3前面; 3034 < 3430, 30一定在34前面; 334 < 343...
以此类推。。。30, 3, 34, 5, 9, 所以输出结果3033459

### 代码

```python3
class cmpSmaller(str):
    def __lt__(self, y):
        return self + y < y + self  # 字符串拼接比较(两两比较)
    # 按由小到大来排列

class Solution:
    def minNumber(self, nums: List[int]) -> str:
        res=sorted(map(str, nums),key=cmpSmaller)
        smallest = ''.join(res)
        return smallest




```