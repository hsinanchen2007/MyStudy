思路：只要找出每个房子所需要的最小供热半径，再求最大值就是整体的最小供热半径
房子相对于供暖器共有三种情况，（1）房子只有右侧右供暖器；（2）房子两侧都有供暖器；（3）房子只有左侧右供暖器
为了方便，提前给供暖器数组两侧加入最小值和最大值，这样所有的房子两侧都有供暖器了；
复杂度大概是Math.max(O(nlogn), O(mlogm), O(m + n));
以下是代码：
```
// 先排序
houses.sort((a, b) => a - b);
heaters.sort((a, b) => a - b);
// 左边加入最小值，为了少判断一个j === 0的情况
heaters.unshift(Number.MIN_SAFE_INTEGER);
// 右边加入最大值，为了少判断j === heaters.length的情况
heaters.push(Number.MAX_SAFE_INTEGER);
var hLen = heaters.length;
var radius = 0;
var j = 1; // 供暖器index
for (var i = 0, len = houses.length; i < len; i++) {
    var house = houses[i];
    var dis; // 房子距离两边供暖器的最小距离

    // 遍历找到第一个比房子大的供暖器，即找到离房子最近的右边的供暖器，则j - 1是离房子最近的右边的供暖器
    // 因为多push了一个最大值，因此不需要判断j是否已经超过越界
    while (j < hLen - 1 && house > heaters[j]) {
        j++;
    }
    dis = Math.min(house - heaters[j - 1], heaters[j] - house);
    radius = Math.max(radius, dis);
}
return radius;
```

