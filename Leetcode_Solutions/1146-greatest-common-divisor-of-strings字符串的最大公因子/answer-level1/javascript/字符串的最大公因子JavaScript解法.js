### 解题思路
额，这次的解题思路比较丑陋，直接就是暴力解决法，先找到str1和str2的所有公共前缀，然后str1和str2分别用这些公共前缀用split分割成数组，如果分割后的数组中有元素不为'',则表示这个前缀不是它们的公约数，用splice截取掉，最后剩下的前缀就是他们的公约数，再从他们中间找出长度最长的字符串就是他们的最大公约数了。

最高赞解法以及众多题解中用到的辗转相除法(欧几里得算法)原谅我小学数学没学好。。。

### 代码

```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
    let isPrefix = true;
    let prefix = "";
    let result = [];
    let num = 0;
	let index = 0;
    for (let i = 0; i < str1.length; i++) {
        if (!isPrefix) break;
        if (str1[i] === str2[i]) {
            prefix += str1[i];
            result.push(prefix);
        } else {
            isPrefix = false;
        }
    }
    for (let i = 0; i < result.length; i++) {
        if (str1.split(result[i]).some(a => a !== '') || str2.split(result[i]).some(a => a !== '')) {
            result.splice(i, 1);
            i -= 1;
        }
    }
    result.map((re, i) => {
			if (re.length >= num) {
					num = re.length;
					index = i;
			}
	})
	return result[index] || "";
};
```

### 附上最高赞js解法

[链接在此](https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/solution/1071-zi-fu-chuan-de-zui-da-gong-yin-zi-by-wonderfu/)

## ```javascript
var gcdOfStrings = function(str1, str2) {
  if (str1 + str2 !== str2 + str1) return ''
  const gcd = (a, b) => (0 === b ? a : gcd(b, a % b))
  return str1.substring(0, gcd(str1.length, str2.length))
};
```