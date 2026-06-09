这里纸不够，我写不下了。

```javascript []
var isValidSudoku = function(chars) {
    //二进制存储，输入值对应于索引位置的值1，用移位操作设值
	var row = [0,0,0,0,0,0,0,0,0], col = [0,0,0,0,0,0,0,0,0], box = [0,0,0,0,0,0,0,0,0];
	for (var i = 0; i < 9; i++) {
		for (var j = 0; j < 9; j++) {
			if (chars[i][j] == '.') continue;
			//数和框
			var num = chars[i][j].charCodeAt(0) - 48, boxNum = (i - i % 3) / 3 * 3 + (j - j % 3) / 3;
			//处理行
			if ((row[i] >> num & 1) != 0) return false; else row[i] += 1 << num;
			//处理列
			if ((col[j] >> num & 1) != 0) return false; else col[j] += 1 << num;
			//处理框
			if ((box[boxNum] >> num & 1) != 0) return false; else box[boxNum] += 1 << num;
		}
	}
	return true;
};
```
```java []
public boolean isValidSudoku(char[][] chars) {
  //二进制存储，输入值对应于索引位置的值1，用移位操作设值
	int[] row = new int[9], col = new int[9], box = new int[9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (chars[i][j] == '.') continue;
			//数和框
			int num = chars[i][j] - 48, boxNum = i / 3 * 3 + j / 3;
			//处理行
			if ((row[i] >> num & 1) != 0) return false; else row[i] += 1 << num;
			//处理列
			if ((col[j] >> num & 1) != 0) return false; else col[j] += 1 << num;
			//处理框
			if ((box[boxNum] >> num & 1) != 0) return false; else box[boxNum] += 1 << num;
		}
	}
	return true;
}
```
![1.png](https://pic.leetcode-cn.com/d129004cb6a95bd07fc17f51d396d69af91bc335d62f7ab250069917c64af2f6-1.png)
