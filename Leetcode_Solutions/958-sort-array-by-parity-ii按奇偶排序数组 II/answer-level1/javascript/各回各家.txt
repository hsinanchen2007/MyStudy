### 解题思路

比较好理解, 就是效率比较低

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParityII = function(A) {
    let list = Array(A.length)
    let odd = 1
    let even = 0
    A.forEach(item => {
      if(item % 2 ===0){
        list[even] = item
        even += 2
      } else {
        list[odd] = item
        odd += 2
      }
    })
    return list
};
```



```js
var sortArrayByParityII = function(A) {
    let list = []
    let odd = A.filter(t => t%2===1)
    let even = A.filter(t => t%2===0)
    for(let i=0; i < A.length; i++){
      if(i%2===0){
        list.push(even[0])
        even.shift()
      }else{
        list.push(odd[0])
        odd.shift()
      }
    }
    return list
};
```
