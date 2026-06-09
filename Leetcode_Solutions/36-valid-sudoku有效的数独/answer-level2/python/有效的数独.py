#### 思路

一个简单的解决方案是遍历该 `9 x 9` 数独 **三** 次，以确保：

* 行中没有重复的数字。
* 列中没有重复的数字。
* `3 x 3` 子数独内没有重复的数字。

实际上，所有这一切都可以在一次迭代中完成。

---
   
#### 方法：一次迭代

首先，让我们来讨论下面两个问题：

* 如何枚举子数独？

> 可以使用 `box_index = (row / 3) * 3 + columns / 3`，其中 `/` 是整数除法。

![image.png](https://pic.leetcode-cn.com/2b141392e2a1811d0e8dfdf6279b1352e59fad0b3961908c6ff9412b6a7e7ccf-image.png){:width="250px"}
{:align="center"}


* 如何确保行 / 列 / 子数独中没有重复项？

> 可以利用 `value -> count` 哈希映射来跟踪所有已经遇到的值。

现在，我们完成了这个算法的所有准备工作：

* 遍历数独。
* 检查看到每个单元格值是否已经在当前的行 / 列 / 子数独中出现过：
    * 如果出现重复，返回 `false`。
    * 如果没有，则保留此值以进行进一步跟踪。
* 返回 `true`。


<![1200](https://pic.leetcode-cn.com/Figures/36/36_slide_2.png),![1200](https://pic.leetcode-cn.com/Figures/36/36_slide_3.png),![1200](https://pic.leetcode-cn.com/Figures/36/36_slide_4.png),![1200](https://pic.leetcode-cn.com/Figures/36/36_slide_5.png),![1200](https://pic.leetcode-cn.com/Figures/36/36_slide_6.png),![1200](https://pic.leetcode-cn.com/Figures/36/36_slide_7.png),![1200](https://pic.leetcode-cn.com/Figures/36/36_slide_8.png),![1200](https://pic.leetcode-cn.com/Figures/36/36_slide_9.png),![1200](https://pic.leetcode-cn.com/Figures/36/36_slide_10.png),![1200](https://pic.leetcode-cn.com/Figures/36/36_slide_11.png),![1200](https://pic.leetcode-cn.com/Figures/36/36_slide_12.png),![1200](https://pic.leetcode-cn.com/Figures/36/36_slide_13.png),![1200](https://pic.leetcode-cn.com/Figures/36/36_slide_14.png),![1200](https://pic.leetcode-cn.com/Figures/36/36_slide_15.png),![1200](https://pic.leetcode-cn.com/Figures/36/36_slide_16.png)>


```java [ciMCoxXQ-Java]
class Solution {
  public boolean isValidSudoku(char[][] board) {
    // init data
    HashMap<Integer, Integer> [] rows = new HashMap[9];
    HashMap<Integer, Integer> [] columns = new HashMap[9];
    HashMap<Integer, Integer> [] boxes = new HashMap[9];
    for (int i = 0; i < 9; i++) {
      rows[i] = new HashMap<Integer, Integer>();
      columns[i] = new HashMap<Integer, Integer>();
      boxes[i] = new HashMap<Integer, Integer>();
    }

    // validate a board
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char num = board[i][j];
        if (num != '.') {
          int n = (int)num;
          int box_index = (i / 3 ) * 3 + j / 3;

          // keep the current cell value
          rows[i].put(n, rows[i].getOrDefault(n, 0) + 1);
          columns[j].put(n, columns[j].getOrDefault(n, 0) + 1);
          boxes[box_index].put(n, boxes[box_index].getOrDefault(n, 0) + 1);

          // check if this value has been already seen before
          if (rows[i].get(n) > 1 || columns[j].get(n) > 1 || boxes[box_index].get(n) > 1)
            return false;
        }
      }
    }

    return true;
  }
}
```
```python [ciMCoxXQ-Python]
class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        # init data
        rows = [{} for i in range(9)]
        columns = [{} for i in range(9)]
        boxes = [{} for i in range(9)]

        # validate a board
        for i in range(9):
            for j in range(9):
                num = board[i][j]
                if num != '.':
                    num = int(num)
                    box_index = (i // 3 ) * 3 + j // 3
                    
                    # keep the current cell value
                    rows[i][num] = rows[i].get(num, 0) + 1
                    columns[j][num] = columns[j].get(num, 0) + 1
                    boxes[box_index][num] = boxes[box_index].get(num, 0) + 1
                    
                    # check if this value has been already seen before
                    if rows[i][num] > 1 or columns[j][num] > 1 or boxes[box_index][num] > 1:
                        return False         
        return True
```


**复杂度分析**

* 时间复杂度：$O(1)$，因为我们只对 `81` 个单元格进行了一次迭代。
* 空间复杂度：$O(1)$。