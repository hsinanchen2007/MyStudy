### 解题思路
用map统计元素出现次数
注：用js刷题的人真少
![image.png](https://pic.leetcode-cn.com/eeb625b98af71604fb57f0118be6842172b03f346fcd22b190c8eebdce25f136-image.png)

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number}
 */
var findLucky = function(arr) {
    let map = new Map()
    arr.map(v => {
        map.has(v) ? map.set(v, map.get(v) + 1) : map.set(v, 1)
    })
    let result = -1
    for(const [key, value] of map){
        if(key == value) result = Math.max(result, key)
    }
    return result
};
```