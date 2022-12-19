### 解题思路
1. 先判断是否是空数组，如果是则返回空字符串
2. 再取出最小的字符串
2. 依次遍历最小的字符串判断与其他字符串对应索引的字母是否一致
3. 如果全部一致则加入返回字符串，否则返回对应字符串

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
				var str = ''
				if (strs.length === 0) {
					return str
				}
				var min = strs[0];
				for (var i = 1; i < strs.length; i++) {
					strs[i].length < min.length ? min = strs[i] : min = min
				}
				for (var i = 0; i < min.length; i++) {
					var f = min[i];
					for (var j = 0; j < strs.length; j++) {
						if (strs[j] === min) {
							continue
						}
						if (f != strs[j][i]) {
							return str
						}
					}
					str = str + f
				}

				return str
			};
```