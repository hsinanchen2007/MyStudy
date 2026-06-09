循环处理字符串。
每次循环中，都把挨着的 [] () {} 替换成空字符串
结束时，判断字符串是不是都替换完了（长度是否为0）

举例：

![image.png](https://pic.leetcode-cn.com/b1ce49b9f93ff8f3d97688423df00f62fa83d365114a6e7cfd60ab9c8f1ca639-image.png)

代码：

```js
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
	let re = /(\[\])|(\(\))|(\{\})/g;
	while (re.test(s)) {
		s = s.replace(re, "");
	}
	return s.length === 0;
};
```
