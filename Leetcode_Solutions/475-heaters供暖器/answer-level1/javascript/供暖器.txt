**理解题意：**

1.	对于每个房屋，要么用前面的暖气，要么用后面的，二者取近的，得到距离；
2.	对于所有的房屋，选择最大的上述距离。

*法一：暴力双循环*

```js
var findRadius = function(houses, heaters) {
    houses.sort((a, b) => a - b);
    heaters.sort((a, b) => a - b);
    let count = 0;
    let nums = [];
    for (let i = 0; i < houses.length; i++) {
        count = Math.abs(houses[i]-heaters[0]);
        for(let j = 0; j < heaters.length; j++) {
            if (Math.abs(houses[i]-heaters[j]) > count) {
                break;
            }
            if (Math.abs(houses[i]-heaters[j]) < count) {
                count = Math.abs(houses[i]-heaters[j]);
            }
        }
        nums[i] = count;
    }
    nums.sort((a, b) => a - b);
    return nums[nums.length-1]
};
```

*法二：双指针*

```js
var findRadius = function(houses, heaters) {
    houses.sort((a, b) => a - b);
    heaters.sort((a, b) => a - b);
    let res = 0;
    let i = 0; // 房子指针
    let j = 0; // 暖气指针
    let r = 0; // 半径
    while(i < houses.length && j < heaters.length) {
        // 房子用右边的暖气
        if (houses[i] <= heaters[j]) {
            r = heaters[j] - houses[i];
            i += 1;
        // 房子左右两边的暖气都可用的时候，用距离小的那边的
        } else if (j < heaters.length - 1) {
            r = Math.min(heaters[j+1] - houses[i], houses[i] - heaters[j]);
            if (houses[i] < heaters[j+1]) {
                i += 1;
            } else {
                j += 1;
            }
        // 暖气指针指到最后一位时，房子只能用左边的暖气
        } else {
            r = houses[i] - heaters[j];
            i += 1
        }
        res = Math.max(res, r)
    }
    return res;
};
```

