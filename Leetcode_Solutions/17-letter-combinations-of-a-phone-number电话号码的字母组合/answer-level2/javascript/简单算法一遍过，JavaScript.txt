### 解题思路

首先创建dictionary字典存储该9个数字所对应的所有字母

然后将digits[0]中所有字母放入res中

然后遍历digits，解析出此时的数字所对应的字母，放入arr中。  

    然后将arr中的所有字母都与res中的字母相加一遍，将结果放入临时变量temp中

    最后将temp赋值给res，继续下一个循环

最后res中的所有字符串即为所求。

### 代码

```javascript
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    let len = digits.length;
    if(!len) return [];
    let dictionary = [[],[],['a','b','c'],['d','e','f'],['g','h','i'],['j','k','l'],['m','n','o'],['p','q','r','s'],['t','u','v'],['w','x','y','z']];
    let res = [...dictionary[Number(digits[0])]];
    
    for(let i = 1; i < len; i ++) {
        let temp = [];
        let arr = [...dictionary[Number(digits[i])]];
        let resLen = res.length, arrLen = arr.length;
        for(let x = 0; x < resLen; x ++) {
            for(let y = 0; y < arrLen; y ++) {
                temp.push(res[x] + arr[y]);
            }
        }
        res = temp;
    }
    return res;
};
```