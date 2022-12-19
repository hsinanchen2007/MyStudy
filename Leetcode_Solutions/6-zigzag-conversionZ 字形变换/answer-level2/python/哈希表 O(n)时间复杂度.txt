### 解题思路
根据观察，从字符串的开头算起，每 numRow + (numRow - 2) 个字母组成一个循环单元。例如，

L     D     R
E   O E   I I
E C   I H   N
T     S     G

中，
L        
E   O 
E C   
T  
的各个字母所处的行号分别为0,1,2,3,2,1, 且每个这样的循环单元都呈现同样的变化规律。

因此可以使用哈希表以行号为键，存储当前行的字母。顺序遍历字符串s，即可个行内的字母顺序存储。最后按行号的顺序，将哈希表内的字母拼接起来。整个程序的时间复杂度为O(n), 空间复杂度为O(n).


### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        letters = {}
        for i in range(numRows):
            letters[i] = []
        
        if numRows == 1:
            return s 

        for i in range(len(s)):
            if i%(numRows*2-2) < numRows:
                letters[i%(numRows*2-2)].append(s[i])
            else:
                letters[(numRows-1)*2-i%(numRows*2-2)].append(s[i])
            
        res = []
        for i in range(numRows):
            res.extend(letters[i])

        return ''.join(res)
```