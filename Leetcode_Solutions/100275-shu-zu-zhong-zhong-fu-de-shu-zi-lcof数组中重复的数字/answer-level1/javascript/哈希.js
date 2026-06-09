### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    //哈希
    let map = new Map()
    for(let item of nums){
        if(map.has(item)){
            map.set(item,true)
        }else{
            map.set(item,false)
        }
    }
    for(let item of map.entries()){
        if(item[1]){
            return item[0]
        }
    }
};
```