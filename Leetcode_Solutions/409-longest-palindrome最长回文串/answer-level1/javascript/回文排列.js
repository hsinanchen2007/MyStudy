### 解题思路
字符串中只要频繁出现两次字符，就能构成回文 且回文的长度加 2；
可以允许中间的字符 只出现一次

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let strArr = s.split('');
    let temp = {};
    let count = 0;
    strArr.map(item => {
    	if(temp[item]){
    		// 当已经存在 改字符，在此出现 可以拼成回文；
    		// 同时对此字符串进行清空
    		count += 2;
    		temp[item] = undefined;
    	}else{
    		temp[item] = 1;
    	}
    });
    if(Object.values(temp).some(item => item === 1)){
    	count += 1;
    }
    return count;

};
```