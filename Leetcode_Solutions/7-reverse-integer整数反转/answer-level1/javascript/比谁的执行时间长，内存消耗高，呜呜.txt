### 解题思路
此处撰写解题思路
就是把字符串转化成数组，然后判断数组头个是否是‘-’，那么就进行相应的删除和添加。
然后再由数组转化为字符串即可。
不过执行时间长，内存消耗高

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */

var reverse = function(x) {
    let a = x.toString(10).split('')
    let b = null
    if(a[0] === '-') {
      a.shift()
      a.reverse()
      a.unshift('-')
      b = a.join('')      
    } else  {
      a.reverse()
      b = a.join('')      
    }
    if(b > (Math.pow(2,31)-1) ||  b < Math.pow(-2,31)){
        b = 0
    }
    return b
  };
```