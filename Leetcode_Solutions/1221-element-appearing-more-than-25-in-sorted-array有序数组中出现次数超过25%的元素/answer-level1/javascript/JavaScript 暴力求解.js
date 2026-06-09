### 解题思路
![image.png](https://pic.leetcode-cn.com/f731b68c7ffa5f5ac39d300768d82a24a8cdcba413669cdd3beff4a2212c183a-image.png)

- 先通过 obj 对象计算储存起来
- 然后通过遍历得到对应值

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number}
 */
var findSpecialInteger = function(arr) {
    let len = arr.length
    let obj = {}
    for(let i of arr){
        obj[i] = (!obj[i] ? 1 : ++obj[i])
    }

    for(let i = 0; i < len; i++){
        if(obj[arr[i]] > len/4){
            return arr[i]
        }
    }
};
```