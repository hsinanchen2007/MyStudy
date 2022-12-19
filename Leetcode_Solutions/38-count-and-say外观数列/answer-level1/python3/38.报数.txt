### 解题思路
输入n的话，就从1一直计算到n再返回n
比如输入4，
首先是n=1,返回1
n=2，上面有1个1，则返回11
n=3,上面有两个1，则返回21
n=4,上面有1个2，1个1，则返回1211
所以输入4，返回1211

就是一直在计算前面一个字符串从0位置开始的重复数目，然后把这个数目化成字符串加在数字之前就可。

### 代码

```python3
import re
class Solution:
    def countAndSay(self, n: int) -> str:

        base_num = '1'

        if n==1:
            return base_num

        for i in range(2,n+1):
            i_num = ''
            
            while base_num:
                first_str = base_num[0]
                num = len(re.findall('^{}*'.format(first_str),base_num)[0])
                base_num = base_num[num:]
                i_num += str(num) + first_str
  
            base_num = i_num
    
        return base_num
```
![图片.png](https://pic.leetcode-cn.com/32f5021253f82913ef706344b52efbfa483c585ee4daab5337a6a1e367eae78a-%E5%9B%BE%E7%89%87.png)

