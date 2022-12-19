### 解题思路
创建numRows个数组，向其中填值

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
const convert = (s, numRows)=> {
  if(s<=numRows || numRows===1) return s;
  
  const rows = new Array(numRows);
  for( let l = 0; l < numRows; l+=1){
    rows[l] = [];
  }
  const sArr = Array.from(s);
  let id = 0;
  let direct = 1;

  for(let i = 0; i < sArr.length; i+=1){
    rows[id].push(sArr[i]);
    if(id === 0){
      direct = 1;
    }
    if(id===rows.length - 1){
      direct = -1;
    }
    id += direct;
  }
  let res = '';
  for( let l = 0; l < numRows; l+=1){
    res += rows[l].join('');
  }

  return res;
};
```