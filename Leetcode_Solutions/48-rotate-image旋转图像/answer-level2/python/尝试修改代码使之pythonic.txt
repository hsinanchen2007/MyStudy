### 解题思路
刚开始尝试刷题，开始看了一个题友的代码，我觉得思路挺符合我的思维的，比较好理解，首先确认需要转换的次数，就是有几组由四个点组成的矩形，然后遍历去旋转即可。
代码空间复杂度是有点惨不忍睹，采用了python闭包思想将代码重写了一下，省去了传参过程，继续努力，#穷究于理，成就于工#
对于方阵应该是有规律可循的，我开始的想法就是逐层调换，但后来想想可以根据矩阵的转置然后再翻转应该就是答案？但这种属于掉包侠套路，哈哈

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        lr, lc = 0, 0
        dr, dc = len(matrix) - 1, len(matrix[0]) - 1
        while lr <= dr and lc <= dc:
            def rotate_edge(matrix):
                times = dc - lc 
                for t in range(times):
                    matrix[lr][lc+t], matrix[lr + t][dc], matrix[dr][dc - t], matrix[dr - t][lc] = \
                                matrix[dr - t][lc], matrix[lr][lc+t], matrix[lr + t][dc], matrix[dr][dc - t]
            rotate_edge(matrix)
            lr += 1
            lc += 1
            dr -= 1
            dc -= 1
            
```