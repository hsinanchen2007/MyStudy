*法一：对象存储元素和它出现的索引,然后循环判断多次出现的元素索引相减*

```js
var nums = [1,2,3,1,2,3];
var k = 2;

var obj = {
1: [0,3],
2: [1,4],
3: [2,5]
}
```
```js
var containsNearbyDuplicate = function(nums, k) {
    var obj = {};
    for (let i = 0; i < nums.length; i++) {
        if(!obj[nums[i]]) {
            obj[nums[i]] = [i];
        } else {
            obj[nums[i]].push(i)
        }
    }
    for (let key in obj) {
        if (obj[key].length > 1) {
            console.log(obj[key])
            for (let j = 0; j < obj[key].length-1; j++) {
                if (Math.abs(obj[key][j+1] - obj[key][j]) <= k) {
                    return true
                }
            }
        }
    }
    return false
};

var nums = [1,2,3,1,2,3];
var k = 2;
console.log(containsNearbyDuplicate(nums, k));
```

*法二:借助Map对象*

1. 遍历数组，如果当前值不存在map表里，把值->key,下标->value,存进map表
2. 如果当前值在map表里存在，看下两个值下标的绝对值是否 <= k
3. 如果 <= k，返回true
4. 否则，更新当前值的下标。因为之前的都不成功，如果有下一个相同元素的话绝对值会更大。
5. 循环完成还没有匹配成功，返回false

优点：改善了法一，可以一边存一遍比较，当然更快一些

```js
var nums = [1,2,3,1];

map = {1 => 3, 2 => 1, 3 => 2}
```

```js
var containsNearbyDuplicate = function(nums, k) {
    let map = new Map();
    for(let i = 0; i < nums.length; i++) {
        if(map.has(nums[i])) {
            if(Math.abs(map.get(nums[i]) - i) <= k) {
                return true
            } else {
                map.set(nums[i], i)
            }
        } else {
            map.set(nums[i], i)
        }
    }
    return false;
}
```


