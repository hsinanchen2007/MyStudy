### 解题思路
1、括号生成后左括号的数量等于右括号的数量等于n
2、在生成括号的过程中，左括号始终大于右括号（生成最终括号之前）

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
function generateParenthesis(n){
	var arr = [];//存储生成的括号
	generate(0,0,n,'',arr);
	return arr;
}
			
function generate(left,right,n,str,arr){
	if(left==n&&right==n){
		return arr.push(str);
	}
	if(left<n){
		generate(left+1,right,n,str+'(',arr);
	}
	if(right<left){
		generate(left,right+1,n,str+')',arr);
	}
}
```