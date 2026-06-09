### 解题思路
此处撰写解题思路
从数组最后一位开始向前遍历，记下9的个数，当运行到某一位时不等于9就停下，如果9的个数等于数组长度，就全部变为0，首位添加1.如果不等于数组长度，把9变为0，最前面的9的前一位加1
### 代码

```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    		var digits ;
			var num = 0 ;/*用于记住9的个数*/
			for(var i = digits.length-1; digits[i]==9;i--)
				{
					num++;/*倒着计数，不是9的就中断循环*/
				}
			if(num == digits.length)
				{
					digits.fill(0);
					digits.unshift(1);/*全部为9，则全部变为0，第一位插入1*/
                    return digits;
				}
			else
				{
					digits.fill(0,digits.length-num);
					digits[digits.length-num-1] = digits[digits.length-num-1] + 1;/*部分为9，着从最前面的9的位置后面全部变0，且它的前一位＋1*/
					return digits;
				}
};
```