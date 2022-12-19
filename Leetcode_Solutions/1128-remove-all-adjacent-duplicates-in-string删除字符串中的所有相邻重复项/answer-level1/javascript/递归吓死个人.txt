### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 * 执行用时 :5352 ms, 在所有 JavaScript 提交中击败了5.28%的用户
    内存消耗 :383.6 MB, 在所有 JavaScript 提交中击败了5.04%的用户
 */
var removeDuplicates = function(S) {
  let arr = S.split('')
  for(let i = 0 ; i < arr.length; i++){
    if(arr[i] ===arr[i+1]){
      arr.splice(i,2)
      S = arr.join('')
      return removeDuplicates(S)
    }
  }
  return S
};
```
看来不适合用递归, 那么 使用栈方法来解

建个数组arr, 循环把S 挨个字符 往 arr 中push, 每次循环 对比 arr的最后元素 是否与将要 push 的元素 相同, 不相同就push, 相同就删掉arr最后元素, 继续循环下去

```
如: S = 'abbacd'

arr = ['a']       开始

arr = ['a','b']   继续

arr = ['a']       b 和 b 相同 把 arr最后元素b去掉, 继续

arr = []          a 和 a 相同  arr最后元素b去掉, 继续

arr = ['c']       继续

arr = ['c', 'd']  循环 结束

```


```js
var removeDuplicates = function(S) {
  let arr = []
  for(let i = 0; i < S.length; i++){
    let index = arr.length ? arr.length - 1 :  arr.length 
    if(arr[index] === S[i]){
      arr.pop()
    } else {
      arr.push(S[i])
    }
  }
  return arr.join('')
};
```


