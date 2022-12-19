### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
                var convert = function(s, numRows) {
					let i = 0;
					let flag = -1;
					let arry = [];
					let str = "";
		            //特殊情况 字符串的长度=1或者行数<=1，那么直接就返回s
		            if(s.length == 1 || numRows<=1 || s.length < numRows )return s;
					for(let j = 0; j < s.length ;j++ ){
		                // 倘若数组最开始为null，就赋值，防止undefined
						if(arry[i] == null) arry[i] = "";
						arry[i] += s.charAt(j);
						if(i==0 || i== numRows -1)flag = -flag;
						i += flag; 
					}
					str = arry.join("");
					return str;
				};
```