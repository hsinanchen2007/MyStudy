### 解题思路
首先使用hash表，存储每项出现得次数
```
for(let i = 0; i < nums.length; i++){
    if(!map.has(nums[i])){
        map.set(nums[i], 1);
    }else{
        let count = map.get(nums[i]);
        count++;
        map.set(nums[i], count);
    }
}
```
然后将hash表中得所有项都存放在一个排序数组中，进行排序，取后k项目
```
map.forEach(item =>{
    sortMap.push(item);
})
sortMap.sort((a, b) => a-b);
let allItem = sortMap.slice(sortMap.length-k);
```
再次遍历哈希表，找出value 等于后K项得所有key
```
map.forEach((value,key) =>{
    if(allItem.indexOf(value) != -1){
        result.push(key);
    }
})
```


### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
    let map = new Map();
    let sortMap = [];
    for(let i = 0; i < nums.length; i++){
        if(!map.has(nums[i])){
            map.set(nums[i], 1);
        }else{
            let count = map.get(nums[i]);
            count++;
            map.set(nums[i], count);
        }
    }
    map.forEach(item =>{
        sortMap.push(item);
    })
    sortMap.sort((a, b) => a-b);
    let allItem = sortMap.slice(sortMap.length-k);
    let result = [];
    map.forEach((value,key) =>{
        if(allItem.indexOf(value) != -1){
            result.push(key);
        }
    })
    return result;
};
```