### 解题思路
3个HashMap存放对应的每一行，每一列，每一个宫格的数值
依次判断每个item是否已经存在对应的行，列，宫格中!

主要是: int boxIndex = j / 3 + (i / 3) * 3; 计算对应的board[i][j]在1~9各宫格中的哪一个!
### 代码

```java
class Solution {
   public boolean isValidSudoku(char[][] board) {
		// 1到9行
		Map<Integer, List<Character>> rowMap = new HashMap<>();
		// 1到9列
		Map<Integer, List<Character>> columnMap = new HashMap<>();
		// 1到9个box
		Map<Integer, List<Character>> boxMap = new HashMap<>();
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				char val = board[i][j];
				if (val != '.') {
					int boxIndex = j / 3 + (i / 3) * 3;
					if (!boxMap.containsKey(boxIndex)) {
						boxMap.put(boxIndex, new ArrayList<>());
					}
					if (!rowMap.containsKey(i)) {
						rowMap.put(i, new ArrayList<>());
					}
					if (!columnMap.containsKey(j)) {
						columnMap.put(j, new ArrayList<>());
					}
					List<Character> itemBoxVals = boxMap.get(boxIndex);
					List<Character> itemRowVals = rowMap.get(i);
					List<Character> itemColumnVals = columnMap.get(j);
					if (itemBoxVals.contains(val) || itemRowVals.contains(val) || itemColumnVals.contains(val)) {
						return false;
					} else {
						itemBoxVals.add(val);
						itemRowVals.add(val);
						itemColumnVals.add(val);
					}
				}
			}
		}
		return true;
	}
}
```