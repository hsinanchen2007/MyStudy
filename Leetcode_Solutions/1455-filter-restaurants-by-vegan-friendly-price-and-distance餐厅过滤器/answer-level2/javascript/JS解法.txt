其实也可以写成一句，但是分开写更清楚好懂一些。
题目不难，主要是要熟悉一些js对数组的操作。
我是边查边写的，太菜了。。看到没有js的题解所以写一下 =。=
```
var filterRestaurants = function(restaurants, veganFriendly, maxPrice, maxDistance) {
    var temp = restaurants.filter(item => {
            return (item[2] == veganFriendly || veganFriendly == 0) && (item[3] <= maxPrice) && (item[4] <= maxDistance)
        })
        temp.sort(function (a, b) {
             return a[1] == b[1] ? b[0] - a[0] : b[1] - a[1]
        })
        var res = temp.map(item => {
            return item[0]
        })
        return res
};
```
