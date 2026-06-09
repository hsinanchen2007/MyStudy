### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    if(!s) return 0;

    // 通过遍历生成map，记录每个字母出现的次数
    let map = new Map();

    const sArr = s.split('');
  

    for(let i=0; i<sArr.length; i++) {
        if(map.get(sArr[i])){
            map.set(sArr[i], map.get(sArr[i]) + 1);
        }else {
            map.set(sArr[i], 1);
        }
    }

    let count = 0;
    let max = 0;
  
    [...map].map(item => {
      let num = item[1];
      //用max记录最大的奇数
      if(num%2 === 1 && num > max) {
        max = num;
      }
      
      // 如果是偶数全部添加  反之添加-1
      if(num % 2 === 0) {
        count += num;
      }else {
        count += num -1;
      }
      
    });
  
    
  // 关键 如果出现过奇数  我们可以将它放在最中间 并加1
  return max > 0 ? count + 1 : count;
  
};
```