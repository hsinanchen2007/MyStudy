### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        re = []
        direcs = ['right','down','left','up']
        curr_d = 0
        index = 0
        i = 0
        j = 0
        if not matrix:
            return []
        while index < len(matrix)*len(matrix[0]):
            if direcs[curr_d%4] == 'right':
                while j < len(matrix[0]) and matrix[i][j] != -256:
                    re.append(matrix[i][j])
                    matrix[i][j] = -256
                    j += 1
                    index += 1
                curr_d+=1
                j-=1
                i+=1
            elif direcs[curr_d%4] == 'down':
                while i < len(matrix) and matrix[i][j] != -256:
                    re.append(matrix[i][j])
                    matrix[i][j] = -256
                    i += 1
                    index += 1
                curr_d+=1
                i-=1
                j-=1
            elif direcs[curr_d%4] == 'left':
                while j >=0 and matrix[i][j] != -256:
                    re.append(matrix[i][j])
                    matrix[i][j] = -256
                    j -= 1
                    index += 1
                curr_d+=1
                j+=1
                i-=1
            else:
                while i>=0 and matrix[i][j] != -256:
                    re.append(matrix[i][j])
                    matrix[i][j] = -256
                    i -= 1
                    index += 1
                curr_d+=1
                i += 1
                j+=1
        return re
                

```