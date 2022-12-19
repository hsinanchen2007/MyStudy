### 解题思路
我们先把
```
L   C   I   R
E T O E S I I G
E   D   H   N
```
写成下面这个样子，也就是V型的，比题目说的N型好理解
可以想象用手捏着最后一个字符，往右拉了一下：
```
L       C       I       R
  E   T   O   E   S   I   I   G
    E       D       H       N
```
这时候每一列跟原字符串是一一对应的：
```
L E E T C O D E I S H I R I N G
| | | | | | | | | | | | | | | |
L | | | C | | | I | | | R | | |
  E | T   O | E   S | I   I | G
    E       D       H       N
```
然后我们把
```
L       C       I       R
  E   T   O   E   S   I   I   G
    E       D       H       N
```
每一行用原字符串对应的字符一一补齐：  
```
'L'E E T'C'O D E'I'S H I'R'I N G    
 L'E'E'T'C'O'D'E'I'S'H'I'R'I'N'G'   
 L E'E'T C O'D'E I S'H'I R I'N'G  
```
为了直观的看，我放了python3的Blackboard主题配色截图：

![image.png](https://pic.leetcode-cn.com/6b45ff2389e4649ed2872777043782079f300799cb80b77d6f3447b73b8e18a6-image.png)

可以看到题目说的N字型的走向：

![image.png](https://pic.leetcode-cn.com/28ac1a0cbbe2c7193ad27b798ee0a78dbc76f457dee33fe1a9f11acdcd8b1646-image.png)

实际上就是，
对列来说，一直往右走，
对行来说，碰到边界就改变方向；


### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows <= 1:return s
        array = [s for i in range(numRows)]
        """
        拿题目用例 LEETCODEISHIRING 举例子
        这里的array是这样的：
        ['LEETCODEISHIRING',
         'LEETCODEISHIRING', 
         'LEETCODEISHIRING']
        """
        ans = [list() for i in range(numRows)]
        """
        ans用来存array里我们需要的字符
        最后，ans里面将会是这样的：
        [['L', 'C', 'I', 'R'],
         ['E', 'T', 'O', 'E', 'S', 'I', 'I', 'G'], 
         ['E', 'D', 'H', 'N']]
        """
        i, direction = 0, 1
        for j in range(len(s)):
            ans[i].append(array[i][j])
            i += direction
            if i == 0 or i == numRows - 1:  
                direction *= -1
        result = list()
        for i in ans:
            result.extend(i)
        """
        result 存的是：
        ['L', 'C', 'I', 'R', 'E', 'T', 'O', 'E', 'S', 'I', 'I', 'G', 'E', 'D', 'H', 'N']
        """

        #   最后转换成字符串返回
        return ''.join(result)