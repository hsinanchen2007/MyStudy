### 解题思路


### 代码
方法一：不使用计数器，利用数组的下标
```javascript
/**
 * @param {string} S
 * @return {string}
 */

    function compressString(s){
				var len = s.length;
				var j = i =0;
				var str = '';
				while(j < len){
					if(s[j] != s[j+1]){
						str += s[j] +(j-i +1);
						i = j+1;
					}
					j++;
				}
				return str.length<len ? str:s;
			}
//方法二：使用计数器
function compressString(S){
				var len = S.length;
				var str = '';
				var count = 1;
				for(var i =1;i<len;i++){
					if(S[i]==S[i-1]){
						count ++;
					}
					else{
						str += S[i-1] + count;
						count = 1;
					}
				}
				str += S[len-1] +count;
				return str.length<len?str:S;
			}
```