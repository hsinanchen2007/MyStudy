### 解题思路
![image.png](https://pic.leetcode-cn.com/27786f4b31f0bcb17a22c028dd03e384948337ee51ab298c06fd5455f4edbf1f-image.png)
- 通过转化为数组, 通过 indexOf 进行遍历，通过splice删除
- 剩下的元素通过 toString()转化得到

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    let a = s.split('')
    let b = t.split('')
    for(let i = 0; i < a.length; i++){
        let tmp = 0
        tmp = b.indexOf(a[i])
        b.splice(tmp,1)
    }
    return b.toString()
}
```