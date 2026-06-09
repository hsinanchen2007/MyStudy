##### 不使用哈希表
1. 已知list1的长度是m，list2的长度是n，所以索引总和sum的范围是0 <= sum <= m + n - 1；假设i是list1的元素索引，j是list2的元素索引，那么他们的索引和sum = i  + j，所以，只要升序枚举所有可能的sum，再遍历list1，就可以得到对应list2的索引，从而可以省去哈希表的内存开销；
2. 若list1[i] === list2[j]且j >= 0,将list1存入一个空的列表res，由于是升序枚举sum的，所以本轮sum枚举结束后，只要res不是空的，即可返回res，因为当前res就是最小索引总和的数组。
##### 代码
```javascript
/**
 * @param {string[]} list1
 * @param {string[]} list2
 * @return {string[]}
 */
var findRestaurant = function(list1, list2) {
    let sumList = list1.length + list2.length - 1;
    let sum = 0;
    let res = [];
    while (sum <= sumList) {
        for (let i = 0; i < list1.length; i++) {
            let j = sum - i;
            if (j >= 0 && list1[i] === list2[j]) {
                res.push(list1[i]);
            }
        }
        if (res.length > 0) break;
        sum++;
    }

    return res;
};
```

##### 使用线性哈希表
1. 首先遍历list1，并建立列表元素本身对列表元素索引的映射，代码为map.set(list1[i], i);
2. 遍历list2，通过list2的元素判断哈希表中是否有值，若有值，则表示当前元素与list1的对应元素相等，效果等同于list1[i] === list2[j]；当前索引和sum = i + j，对比当前最小索引和min，对比成功更新当前最小索引和，并重置最小索引和数组res的长度；
3. 当前索引和等于最小索引总和，表示最小索引总和数组不止一个元素，将当前元素push进数组；
##### 代码

```javascript
/**
 * @param {string[]} list1
 * @param {string[]} list2
 * @return {string[]}
 */
var findRestaurant = function(list1, list2) {
    let map = new Map();
    for (let i = 0; i < list1.length; i++) {
        map.set(list1[i], i);
    }

    let res = [];
    let min = -1;
    for (let j = 0; j < list2.length; j++) {
        if (map.has(list2[j])) {
            let sum = j + map.get(list2[j]);
            //初始化min
            if (min < 0) {
                min = sum;
            }
            if (sum < min) {
                min = sum;
                res.length = 0;
            }

            if (sum <= min) {
                res.push(list2[j]);
            }
        }
    }
    return res;
};
```