### 解题思路
这里面分成几种情况,首先是小于0的数被直接排除,大约0且小于10的数必定是回文数.接下来就要靠自己的算法去实现了.这里边,无非就是取出前边的数和后边的数做一个对比.因为题意说了,最好不要用到转成字符串,所以,这里考验的实际上是取一个整数第几位的能力.也就是利用 n/Math.pow(10,len - i) / Math.pow(10,len -i -1) 去求前边的位数,至于这里为什么多了一句判断是,parseInt在做转换时,对于小于1e-6的数会利用科学计数法,导致转换后得到的结果不正确.所以这里用大小比较去做兼容.比较前后的位数是否正确,得到正确结果.

### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
		let len = (x + '').length,flag = true;
		if(x < 0){
			return false;
		} else if (x >= 0&&x <10){
			return true;
		} else {
			for (let i = 0;i <  Math.floor(len/2); i++){
				let x1 = x%Math.pow(10, len - i)/Math.pow(10,len - i -1) < 1 ? 0 : parseInt(x%Math.pow(10, len - i)/Math.pow(10,len - i -1));
				if(x1 !== parseInt(x%Math.pow(10,i + 1)/Math.pow(10,i))) {
					flag = false;
				}
			}
		}
		return flag;
	};
```