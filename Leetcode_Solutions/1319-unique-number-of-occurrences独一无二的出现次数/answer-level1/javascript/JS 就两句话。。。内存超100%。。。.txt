### 解题思路
emmmm。。。就是集合去个重，然后看看有没有去重。。。

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = (arr)=>{
    let check = {};
    for (let item of arr) check[item] != null ? check[item]++ : check[item] = 1;
    return Object.values(check).length === new Set(Object.values(check)).size
};

```