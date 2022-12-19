前提：不将整数转为字符串来解决这个问题

首先，整数包括：
- 正数
- 0，是回文
- 负数，肯定不是回文


我们只需要专心处理正数

## 思路

在循环中的每一轮，取一头一尾的数字，进行比较。
如果相同，就砍掉一头一尾，拿剩下的数进行下一轮比较。
如果不同，说明不是回文，终止循环。



##### 如何取头尾数字？

取头数字：关键要知道这个数是多少位的，位数用`Math.log10`可以算出来

取尾数字：很简单，`num%10`就可以了。


##### 这种方法有一个陷阱

- `1203021` 头尾都是1，下一轮
- `20302` 头尾都是2，下一轮
- `030` **陷阱：要保证这一轮取头的时候是0，而不是3**


##### 怎么绕过这个陷阱呢？

循环中，每一轮的位数，不能用 `Math.log10` 现算

而是应该：在循环开始前，就用 `Math.log10` 把位数算出来，每轮循环固定减2。

而且，while中必须用_level判断。不能用 `num<10` 判断

## 代码

```js

var isPalindrome = function(num) {
	// 整数：正数 0 负数
	if (num === 0) {
		return true;
	}
	if (num < 0) {
		return false;
	}	
	// 为了绕过陷阱，位数 _level 要在一开始计算出来，每次循环固定减2
	let _level = Math.floor(Math.log10(num));
	// while中必须用_level判断。如果用 num<10 来判断，就会出现：10031 => 3 ，循环中止了
	while (_level >= 1) {
		let firstPos = Math.floor(num / Math.pow(10, _level));
		let lastPos = num % 10;
		if (firstPos !== lastPos) {
			return false;
		}
		num = (num - firstPos * Math.pow(10, _level) - lastPos) / 10;
		_level -= 2;
	}
	return true;
};
```
