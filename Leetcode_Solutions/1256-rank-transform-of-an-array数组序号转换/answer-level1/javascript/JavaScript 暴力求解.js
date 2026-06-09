### 解题思路
![image.png](https://pic.leetcode-cn.com/d85a72cc1f5278cb8455e5fdcf36a289b0bc62e6f69ed8a32021e2e8ad4cf207-image.png)

- 通过 ES6 的 Map() 数据结构进行记录 arr 的编号,通过 set() 进行设定
- 然后通过 map().get()/has() 重新设定 res

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number[]}
 */
var arrayRankTransform = function(arr) {
    let len = arr.length
    if(len == 0) return []
    if(len == 1) return [1]
    let temp = [...arr]
    temp.sort((a,b) => a-b)
    let map = new Map()
    for(let i = 0, index = 1; i < len; i++){
        if(!map.has(temp[i])){
            map.set(temp[i], index++)
        }
    }
    let res = []
    for(let i = 0; i < len; i++){
        if(map.has(arr[i])){
           res.push(map.get(arr[i]))
           }
    }
    return res
};
```