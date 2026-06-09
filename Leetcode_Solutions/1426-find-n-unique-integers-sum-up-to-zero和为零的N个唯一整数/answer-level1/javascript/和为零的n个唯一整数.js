### 解题思路
实际上一正一负的添加数据就可以，如果是奇数那么添加一个0；剩下的同理

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var sumZero = function(n) {
    let res = [];
    if(n%2 ===0){//偶数个数字
      let num = n/2
      for(let i=1;i<num+1;i++){
         res.push(i);
         res.push(-i);
      }
    }else{//奇数个数字
     let nums = (n-1)/2;
     res.push(0)
     for(let j=1;j<nums+1;j++){
        res.push(j);
        res.push(-j)
     }
    }
    return res;
};
```