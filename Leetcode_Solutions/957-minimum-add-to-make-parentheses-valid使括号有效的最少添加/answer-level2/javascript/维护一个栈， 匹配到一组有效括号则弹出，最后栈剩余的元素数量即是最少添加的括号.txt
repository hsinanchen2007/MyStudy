### 解题思路
维护一个栈， 如果栈顶为( ,当前为 ) , 构成一个有效括号(), 此时弹出栈顶( ，否则元素入栈， 最后无效的括号都在栈中， 返回栈的元素数量即可。  

### 代码

```javascript
/**
 * @param {string} S
 * @return {number}
 */
var minAddToMakeValid = function(S) {
    var st=[];
		for(let c of S){
			if(st.length && st[0]=='(' && c==')'){
				st.shift();
			}else{
				st.unshift(c);
			}
		}
		return st.length;
};
```