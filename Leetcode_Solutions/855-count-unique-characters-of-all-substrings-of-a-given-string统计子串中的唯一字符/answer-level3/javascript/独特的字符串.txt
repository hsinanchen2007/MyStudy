### 解题思路
复制粘贴。能有多难😂。js按照普通思维就内存炸了，只能通过一半测试用例
### 代码

```javascript
/**
 * @param {string} S
 * @return {number}
 */
var uniqueLetterString = function(S) {
   var sum = 0;
		for (var i = 0; i < S.length; ++i) {
			for (var j = i - 1; j > -1 && S[j] != S[i]; --j);
			for (var k = i + 1; k < S.length && S[k] != S[i]; ++k);
			sum += (i - j)*( k - i);
		}
		return sum%1000000007;
};

```