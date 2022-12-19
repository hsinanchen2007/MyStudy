### 解题思路

1、分别 `maxPrice`、`maxDistance` 去过滤餐厅；
2、再根据 `veganFriendly` 是 `true` or `false` 去过滤；
3、根据 `评分`、`id` 去排序；
4、返回排序后的 `id` 顺序。

### 代码

```javascript
/**
 * @param {number[][]} restaurants
 * @param {number} veganFriendly
 * @param {number} maxPrice
 * @param {number} maxDistance
 * @return {number[]}
 */
var filterRestaurants = function(restaurants, veganFriendly, maxPrice, maxDistance) {
    restaurants = restaurants.filter(item => item[3] <= maxPrice);
    restaurants = restaurants.filter(item => item[4] <= maxDistance);
    if(veganFriendly) restaurants = restaurants.filter(item => item[2]);
    restaurants = restaurants.sort((a, b) => a[1] === b[1] ? b[0] - a[0] : b[1] - a[1]);
    return restaurants.map(item => item[0]);
};
```