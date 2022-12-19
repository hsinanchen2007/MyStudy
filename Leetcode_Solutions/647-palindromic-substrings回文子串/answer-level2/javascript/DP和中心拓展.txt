### 解题思路
dp[i][j]表示字符串i到j是否是回文。s[i]===s[j]并且i,j相邻或者间隔一个表示字符串i到j肯定是回文。dp[i+1][j-1]是因为例如abcda我们i为开始a,j为末尾的a，这时候还不一定是回文，需要判断[i+1][j-1]也就是bcd是否是回文。

中心拓展重点是判断回文是奇数还是偶数。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function(s) {
    //动态规划
		let dp = [...new Array(s.length + 1)].map(()=>new Array(s.length + 1).fill(false)),
        	res = 0;
		for(let i = s.length - 1; i >= 0; i--){
		    for(let j = i; j < s.length; j++){
				dp[i][j] = (s[i] === s[j]) && (j - i <= 2 || dp[i+1][j-1]);
				if(dp[i][j])res++;
			}
		}
        return res;
};
var countSubstrings = function(s) {
//中心拓展
	let res = 0;
	for(let i = 0; i < s.length; i++){
    		for(let j = 0; j < 2; j++){
      			let left = i;
      			let right = i + j;
      			while(s[left] && s[left] === s[right]){
          			left--;
          			right++;
          			res++;
      			}
          	}
	}
	return res;
  };
```