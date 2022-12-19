### 解题思路
![222.png](https://pic.leetcode-cn.com/b322194d05895918912bbe4317452c80fdd1afae86a84f2d02ba782b6ded60a5-222.png)
首先通过一个循环获取最大值，然后再建立一个循环，将1-max的每一个值push到res数组中，最后返回

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
			var printNumbers = function(n){
				let max = 0
				let res = []
				for(let i=0;i<n;i++){
					max = max + 9*Math.pow(10,i)
				}
				for(let m=1;m<=max;m++){
					res.push(m)
				}
				return res
			}
```