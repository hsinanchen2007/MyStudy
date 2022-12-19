### 解题思路
![image.png](https://pic.leetcode-cn.com/6f21484df981428b8cdb93102a133009da7c43505536c14036c470a61cfab285-image.png)

- 添加正负值，最后判断是否是奇数，而决定是否添加 0
### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */

var sumZero = function(n) {
    const res = [];
    let len = Math.floor(n/2);
    for(let i=1; i <= len; i++){
        res.push(i, -i);
    }
    if(n%2!=0)res.push(0);
    return res;
};


```