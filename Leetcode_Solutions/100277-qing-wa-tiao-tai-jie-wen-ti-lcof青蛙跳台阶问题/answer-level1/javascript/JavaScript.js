### 解题思路
递归的方法：
初始化  n=0和n = 1的数组，即numWay[0] = 1;num[1] = 1
总结发现n = 2 时，numWay = numWay[0] + numWay[1] = 2;
即：f(n) = f(n-1) + f(n-2);


### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
function numWays(n){
				var numWay = [1,1];
				for(var i = 2;i<=n;i++){
					numWay[i] = (numWay[i-1] + numWay[i-2])%(1e9+7);
				}
				return numWay[n];
			}
```