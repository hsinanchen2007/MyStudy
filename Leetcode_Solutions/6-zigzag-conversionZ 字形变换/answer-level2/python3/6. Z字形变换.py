### 解题思路
最关键的地方是把输入的每一个字符的位置和输出的对应的字符的位置映射起来，这份代码用了一个numpy二维数组保存中间输出结果。时间和空间复杂度都是O(n)。

### 代码

```python3
import numpy as np
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if not s or numRows<=1:
            return s
        length = len(s)
        shang,yushu=divmod(length,numRows-1)
        z_result = np.empty([numRows,shang+1],dtype=str)
        result=''
        for i in range(length):
            i_shang,i_yushu=divmod(i,numRows-1)
            if i_shang%2==1:
                z_result[numRows-1-i_yushu][i_shang]=s[i]
            else:
                z_result[i_yushu][i_shang]=s[i]
        for element in np.nditer(z_result):
            s_elem = str(element)
            if s_elem!='':
                result+=s_elem
        return result
```