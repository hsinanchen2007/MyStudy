### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} guess
 * @param {number[]} answer
 * @return {number}
 */
var game = (guess, answer)=>guess.filter((item,index)=>item===answer[index]).length

```