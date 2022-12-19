构造一个长度为numRows的数组，z子的每一行作为该数组的每一个元素

```javascript
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
   if(numRows===1) return s;
   let len = Math.min(s.length,numRows);
   let rows = [];
   for(let i = 0; i < len;i++) rows[i] = '';
   let curRow = 0;
   let goingRow = false;
   for (const num of s) {
       rows[curRow] += num;
       if(curRow === 0 || curRow === numRows-1) goingRow = !goingRow;
       curRow = goingRow ? curRow +1 : curRow-1;
   }
   let ans = '';
   for (const row of rows) {
       ans+=row
   }
   return ans;
};
```