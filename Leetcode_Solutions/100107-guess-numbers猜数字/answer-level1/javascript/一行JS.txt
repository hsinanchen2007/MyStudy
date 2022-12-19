### 解题思路
执行用时 : 60 ms , 在所有 javascript 提交中击败了76.37%的用户 内存消耗 : 33.9 MB, 在所有 javascript 提交中击败了 100.00% 的用户

### 代码

```javascript
/**
 * @param {number[]} guess
 * @param {number[]} answer
 * @return {number}
 */
const game = (guess, answer) => guess.filter((x,i) => x === answer[i]).length;
```