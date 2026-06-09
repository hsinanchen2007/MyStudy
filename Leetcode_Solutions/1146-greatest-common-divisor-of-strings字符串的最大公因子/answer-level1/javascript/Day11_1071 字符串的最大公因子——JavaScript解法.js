### 解题思路
//如果str1 + str2 !== str2 + str1;直接返回空字符串
//如果满足返回两个字符串长度的最大公约数的字串
//重点：求两个数的最大公约数：欧几里得算法求最大公约数
//欧几里得算法参考：https://blog.csdn.net/Canhui_WANG/article/details/50760510?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task

### 代码

```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1,str2){
				var len1 = str1.length;
				var len2 = str2.length;
				if(str1+str2 !== str2+str1){
					return '';
				}
				return str1.substring(0,gcd(len1,len2));
				//获取长度的最大公约数
				function gcd(a,b){
					return b==0 ? a:gcd(b,a%b);
				}
};
```