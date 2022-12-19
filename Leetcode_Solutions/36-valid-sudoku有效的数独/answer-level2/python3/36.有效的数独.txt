### 解题思路
看了官方题解，自己写了一遍
深感算法的美妙啊。

为行开辟一个数组，数组中的元素对应每一行中数字的情况，key是数字，value是出现次数
rows = [{1:1,2:0,3:1,....},{1:1,2:0,3:1,....},{1:1,2:0,3:1,....},{1:1,2:0,3:1,....}]

列和box同理

box的id计算也很美妙：(i//3)*3+(j//3)

大概还是因为自己见识短浅觉得啥都好神奇。反正你们牛逼就是了。

执行用时：92ms     击败54.10%
内存消耗：11.8MB   击败12.45%

### 代码

```python
class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        rows = [{} for i in range(9)]
        lines = [{} for i in range(9)]
        boxes = [{} for i in range(9)]

        for i in range(9):
            for j in range(9):
                num = board[i][j]
                boxes_index = (i//3)*3 + (j//3)
                if num != '.':
                    num = int(num)
                    
                    rows[i][num] = rows[i].get(num,0) + 1
                    lines[j][num] = lines[j].get(num,0) + 1
                    boxes[boxes_index][num] = boxes[boxes_index].get(num,0) + 1

                    if rows[i][num]>1 or lines[j][num]>1 or boxes[boxes_index][num]>1:
                        return False
        return True
```