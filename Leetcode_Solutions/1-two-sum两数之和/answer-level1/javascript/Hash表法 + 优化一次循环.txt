### 1. 暴力 for 循环
```js
// 直接暴力将所有数据两两对比，直到发现符合条件的数值对再返回 i,j
var twoSum = function(nums, target) {
    for(let i = 0; i < nums.length; i++){
        for(let j = 0;j < nums.length; j++){
            if(nums[i] + nums[j] === target && i !== j){
                return [i,j]
            }
        }
    }
};
```

### 2. map存储
```js
// 先将所有值与index都存到map中，计算时再遍历到对应值时，用target减去当前值，
// 求得期望值，然后拿期望值去map里看是否已经有记录，有则返回 i,j
// 一共遍历了两次 nums
var twoSum = function (nums, target) {
    let map = new Map()
    nums.forEach((value, index) => {
        map.set(value, index)
    })
    for (let i = 0; i < nums.length; i++) {
        let tmp = map.get(target - nums[i])
        if (tmp !== undefined && tmp !== i) {
            return [i, tmp]
        }
    }
};
```

### 3. 一次循环
```js
//  因为两个值是相对应的关系，
//  令 nums = [ 1 , 3 , 5 ]  target = 6
//         6 - nums[0] => nums[2]  则 0 和 2 是我们需要的值对
//  同样   6 - nums[2] => nums[0] 此时 2 和 0 也是正确答案
//  也就是说如果完整的遍历一次数组，会得到两次正确答案，因此我们可以在
//  第一次循环 i = 0 时直接判断 map.get(6-1) 是否为有效值，如果无效，
//  有可能是数值 5 在 i 的后面，还未存入map中，将此时的 key: 1 和 value:0 
//  存入map中，等到 i = 2 时，判断 map.get(6 - 5) 时即可取出正确答案，这么做可以减少一次全量循环
var twoSum = function (nums, target) {
    let map = new Map()

    for (let i = 0; i < nums.length; i++) {
        let tmp = map.get(target - nums[i])
        if (tmp !== undefined && tmp !== i) {
            return [i, tmp]
        }
        map.set(nums[i], i)
    }
};
```