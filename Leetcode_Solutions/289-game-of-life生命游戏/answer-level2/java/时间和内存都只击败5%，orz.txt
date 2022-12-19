### 解题思路
解体思路都很简单粗暴，重点在于状态的存储和统计周围8个格子的活细胞情况
1.边界问题
比如第一个格子，它左上一行一列是没有的，这样循环就很困难，这里就用了try-catch来捕获当数组下标越界的时候，直接将数据处理为此处为死细胞，记为0。
2.状态存储
看到有题解是按照为存储的，也有用其他数字代替不同状态的，然后就想到，可以用十位上的数字表示新状态，各位的数字表示旧状态呀。需要新状态就取商，需要旧状态就取余数，最后再把所有的数字除以10取商即可完成状态的更新

最后，这个时间和内存只击败5%告诉我，这些我都多想了，还是老老实实判断情况吧！orz

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
    	for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[i].length; j++) {
				int count = 0;
				int num = 0;
				for (int k = i-1; k <= i+1; k++) {
					for (int k2 = j-1; k2 <= j+1; k2++) {
						if (k != i || k2 != j) {
							try {
								num = board[k][k2] % 10;
							} catch (Exception e) {
								num = 0;
							}
							count += num;
						}
					}
				}
				if (board[i][j] == 1 && (count == 2 || count == 3)) {
					board[i][j] += 10;
				} else if (board[i][j] == 0 && count == 3) {
					board[i][j] += 10;
				}
			}
		}
    	for (int i = 0; i < board.length; i++) {
    		for (int j = 0; j < board[i].length; j++) {
				board[i][j] /= 10;
			}
			
		}
    }
}
```