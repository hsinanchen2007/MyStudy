### 方法一：找规律
我们从左下角开始遍历，当该值小于 target 值时，向右搜索；大于 target 值时，向上搜索。如果找到 target 则返回 True，否则返回 False。

![fig 1](https://pic.leetcode-cn.com/6f64febe23e0e25e28dbf816dc8850df70368d4e7d7dad5c7871eee386ec7139-file_1581472766383)

#### 代码

```python []
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix: return False
        m, n = len(matrix), len(matrix[0])
        row, col = m - 1, 0
        while row >= 0 and col < n:
            if matrix[row][col] < target:
                col += 1
            elif matrix[row][col] > target:
                row -= 1
            else:
                return True
        return False
```

```c++ []
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0){
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int row = m - 1;
        int col = 0;
        while (row >=0 && col < n){
            if(matrix[row][col] < target){
                col += 1;
            }
            else if(matrix[row][col] > target){
                row -= 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
```
#### 复杂度分析
- 时间复杂度：$O(m+n)$。m 和 n 分别为行数和列数。最坏情况下，我们从左下角移动到右上角，经过的路径长度为。
- 空间复杂度：$O(1)$。
### 方法二：二分搜索
首先在对角线上迭代，对于每一个对角线元素，对该元素所在的行和列使用二分搜索。


<![幻灯片1.JPG](https://pic.leetcode-cn.com/0435300e535d69fd77cf5de7dbe8844f6abdc203326fd27ce43a7f14bfd2df24-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/d4d43af7be0b14b85a40edfdc1e71bcd02816f965d72c6e163e021c68404fc42-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/241abd84a471c18ac0292ff5d31ccf92f448435976658e32d0ff940d6215663c-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/f8d9fb4f60b3d7cdf4129d08bbe4f12200ffa1ddd139475b1c58edc0a73a122a-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/0f5c8eb23a2064ad6d65d96f8afff8451aa681fbee8fb6eb62a9121a26359037-%E5%B9%BB%E7%81%AF%E7%89%875.JPG),![幻灯片6.JPG](https://pic.leetcode-cn.com/f556631a01970e3021b904f44c9f00a7a0a1ce1452d50e0f487e71d353ba16fd-%E5%B9%BB%E7%81%AF%E7%89%876.JPG),![幻灯片7.JPG](https://pic.leetcode-cn.com/072164f4852e863b3bb28f72cea65a1aa0b43e71e65be31a552547a3cc2d92e2-%E5%B9%BB%E7%81%AF%E7%89%877.JPG),![幻灯片8.JPG](https://pic.leetcode-cn.com/0bd76b4aace15a25fcc165046dd486385e203a107b73285f7988df144528fffe-%E5%B9%BB%E7%81%AF%E7%89%878.JPG),![幻灯片9.JPG](https://pic.leetcode-cn.com/9d78067d278ae02d53cdfee2d7282aef9db0ec63ace710c8b2f4337acde01bf4-%E5%B9%BB%E7%81%AF%E7%89%879.JPG),![幻灯片10.JPG](https://pic.leetcode-cn.com/f79e917e394e2638b52fe4cbd490cef086c2d73f1d9f9e680e38f9514b988d3f-%E5%B9%BB%E7%81%AF%E7%89%8710.JPG),![幻灯片11.JPG](https://pic.leetcode-cn.com/f316a536b019c992d6cd13fb6595ca7e64c0c5d8ff01b40bafd07158cb4f1b3e-%E5%B9%BB%E7%81%AF%E7%89%8711.JPG),![幻灯片12.JPG](https://pic.leetcode-cn.com/310b5c1c5f2f014a1ad646fc674b586d4a698da356f34cbbc28b92c6621097b5-%E5%B9%BB%E7%81%AF%E7%89%8712.JPG)>


#### 代码
```python []
class Solution:
    def binary_search(self, matrix, target, start, vertical):
        lo = start
        hi = len(matrix) - 1 if vertical else len(matrix[0]) - 1 # 垂直搜索：hi = 行数 - 1

        while lo <= hi:
            mid = (lo + hi) // 2
            if vertical:  # 垂直搜索
                if matrix[mid][start] < target:
                    lo = mid + 1
                elif matrix[mid][start] > target:
                    hi = mid - 1
                else: 
                    return True
            else:   # 水平搜索
                if matrix[start][mid] < target:
                    lo = mid + 1
                elif matrix[start][mid] > target:
                    hi = mid - 1
                else:
                    return True

        return False

    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix: return False   # 边界条件

        for i in range(min(len(matrix), len(matrix[0]))):
            vertical_found = self.binary_search(matrix, target, i, True) # 垂直方向是否找到
            horizontal_found = self.binary_search(matrix, target, i, False) # 水平是否找到
            if vertical_found or horizontal_found:  # 任一方向找到即可
                return True

        return False
```
#### 复杂度分析
- 时间复杂度：$O(lgk!)$，$k=min(m,n)$。
- 空间复杂度：$O(1)$。

### 方法三：递归
在 $mid$ 列寻找满足条件 $matrix[row - 1][mid]<target<matrix[row][mid]$ 的点，比如当 $row=3,mid=2$ 时（黄色区域），$9<target<14$，这时我们可以判断出来 $target$ 一定在左下或者右上区域：
- 由 $target>9$，可知 $target$ 在 $9$ 的右侧或下侧；
- 由 $target<14$，可知 $target$ 在 $14$ 的上侧或左侧；

**因此对左下和右上两个区域进行递归，直到遇到终止条件进行回溯，返回结果。** 终止条件为：
- 区域中没有元素；
- $target$ 大于深色区域右下角的值（最大值）或小于深色区域左上角的值（最小值）

其中，找到黄色点的方法如下：
1. 列索引 $mid$ 采用二分查找;
2. 行索引沿 $mid$ 列从上向下移动，并保持该位置元素小于 $target$。


![TIM截图20200229160734.png](https://pic.leetcode-cn.com/00917701153b12d2819e2e0ed681737390b8e5bd26ea1d0c6abd7dfe87c8c927-TIM%E6%88%AA%E5%9B%BE20200229160734.png)



#### 代码
```python []
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix: return False

        def search_backtrack(left, up, right, down):
            if left > right or up > down:
                return False
            elif target < matrix[up][left] or target > matrix[down][right]:
                return False

            mid = left + (right - left) // 2

            row = up
            while row <= down and matrix[row][mid] <= target:
                if matrix[row][mid] == target:
                    return True
                row += 1

            return search_backtrack(left, row, mid - 1, down) or search_backtrack(mid + 1, up, right, row - 1)

        return search_backtrack(0, 0, len(matrix[0]) - 1, len(matrix) - 1)
```
#### 复杂度分析
- 时间复杂度：$O(nlgn)$。
- 空间复杂度：$O(lgn)$。

欢迎提供c++代码~
如有问题，欢迎讨论~