### 解题思路
[Java-O(1)解法的个人理解](https://leetcode-cn.com/problems/add-digits/solution/java-o1jie-fa-de-ge-ren-li-jie-by-liveforexperienc/)
return (num-1)%9 +1

100*x + 10*y + z = 99*x + 9*y + (x+y+z)


这题也算是取模运算，同样是起始点很奇怪的。
[168. Excel表列名称](https://leetcode-cn.com/problems/excel-sheet-column-title/)

[171. Excel表列序号](https://leetcode-cn.com/problems/excel-sheet-column-number/)

### 代码

```python3
class Solution:
    def addDigits(self, num: int) -> int:
        if num == 0:
            return 0
        val = num%9
        if val == 0:
            val = 9
        return val
```