### 解题思路
此处撰写解题思路
1.数组排序，取最短的项为匹配值去和其余匹配，只要有一个匹配不上，则最短项去掉最后一个字符串，继续匹配，直到最后删除到全部匹配或者删到匹配项为空。最后返回匹配项

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
				let arr = strs.sort((a, b) => {
					return a.length - b.length;
				});
				let str = arr[0]||'';
				console.log(arr);
				for (let i = arr.length - 1; i > 0; i--) {
					const el = arr[i];
					console.log(el);
					if (el.indexOf(str) == 0) {
						console.log(el);
						continue;
					} else {
						console.log(el, str);
						while (el.indexOf(str) !== 0) {
							str = str.slice(0, str.length - 1);
							console.log(str);
							if (str.length < 1) return '';
						}
					}
				}
				console.log(str);
				return str;
			};
```