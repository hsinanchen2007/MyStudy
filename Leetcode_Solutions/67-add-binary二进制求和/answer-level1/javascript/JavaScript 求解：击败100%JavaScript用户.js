标题党！其实思路很简单:
- 先对两个字符串按照最长长度，在前面用'0'补全长度
- 然后对字符串从后向前遍历，对两个字符串相同位置的字符进行求和
    - 如果和 >=2,说说明发生了进位，保存进位状态为true，下一次求和要 + 1
    - 如果和 < 2,说明没有发生进位，保存进位状态为false,下一次求和要 + 0
- 遍历结束后，如果进位状态为 true, 说明第一位字符串仍然发生了进位，则拼上一个1
- 时间复杂度O(n)

代码：

	var addBinary = function(a, b) {
	    let maxLen = Math.max(a.length, b.length);
	    a = a.padStart(maxLen, '0')
	    b = b.padStart(maxLen, '0')
	    let result = Array.from({length: maxLen}, x => 0)

	    let hasCarry = false
	    for (let i = maxLen - 1;i >= 0;i--) {
	    	let tempa = a[i] || 0, tempb = b[i] || 0;
	    	result[i] = +tempa + +tempb + (hasCarry ? 1 : 0)
	    	hasCarry = result[i] >= 2
	    	result[i] %= 2
	    }
	    result = (hasCarry ? '1' : '') + result.join('')
	    return result
	};

![100.png](https://pic.leetcode-cn.com/e3bed393b66c22c6f81f4073e5f8cac5f4f7d6d3b3720ec68658f8ee3d966afd-100.png)
