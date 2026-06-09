## 解题分析
这道题最简单的做法，就是暴力遍历法，遍历整个二位数组的元素，然后找到目标值并且返回，这样的时间复杂度为O(m*n)；且没有用到二维数组**每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序**的条件；

我们首先想到的就是可能从左上角的元素开始遍历，这样做有一个最大的问题，如果当前的元素比目标元素要小，那么就有两种走法，你往下走也会变大，往右走也会变大，这样就有两个选择，就迫使你随机选择一个，如果选错了，回头就很难了；

但是如果我们换一个思路，从右上角或者左下角开始走的话，情景将会发生很大的转变；右上角已经是最大的列了，如果目标值还比当前元素大只有往下走一条路，如果比当前元素小，你也只有往左走一条路，从左下角开始也同理，直到找出界，那么就是不存在目标整数，这样的时间复杂度为O(m+n);

- 题外话 
	
	这道题其实也蕴含了一个哲理，选一条对的路，一直走的头就是答案，给自己太多的选择，终究会找不到回去的路；

## 代码
ps：这里笔者使用的jdk为1.8、python3.7

- java实现（从右上角开始）

	```java
	class Solution {
	    public boolean findNumberIn2DArray(int[][] matrix, int target) {
	        if (Objects.isNull(matrix) || matrix.length == 0 || matrix[0].length == 0) {
	            return false;
	        }
	        int line = 0;
	        int row = matrix[0].length - 1;
	
	        while (true) {
	            if (row < 0 || line >= matrix.length ) {
	                return false;
	            } else if (matrix[line][row] == target) {
	                return true;
	            } else if (matrix[line][row] > target) {
	                row--;
	            } else {
	                line++;
	            }
	        }
	    }
	}
	```

- python实现（从左下角开始）

	```python
	class Solution:
	    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
	        if matrix is None or len(matrix) == 0 or len(matrix[0]) == 0:
	            return False
	        line, row = len(matrix) - 1, 0
	        while True:
	            if line < 0 or row > len(matrix[0]) - 1:
	                return False
	            elif matrix[line][row] == target:
	                return True
	            elif matrix[line][row] > target:
	                line -= 1
	            else:
	                row += 1
	```