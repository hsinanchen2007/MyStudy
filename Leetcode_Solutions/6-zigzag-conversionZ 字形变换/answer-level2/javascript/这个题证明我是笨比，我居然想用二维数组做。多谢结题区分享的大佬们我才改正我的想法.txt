### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
			var convert = function(s, numRows) {
				let a = []
				let index = 0
				let down = true //index 是否下移
				if (numRows === 1) {
					return s
				}
				for (let i = 0; i < s.length; i++) {
					// a[index]是否为undefined
					a[index] = a[index] ? a[index] + s[i] : s[i]
					index = down ? ++index : --index
					if (index === 0) {
						down = true
					} else if (index === numRows - 1) {
						down = false
					}
				}
				return a.join('')
			}
```