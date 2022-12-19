要算出所有能积累起来的雨水，只要算出每根柱子上面积累的雨水的总和就可以了，而每根柱子上能积累起来的雨水取决于两边的柱子，仔细思考就会发现，是等于两边最高柱子中较小的那个减去柱子本身的高度，即：
    `water[i] = min(leftMax[i], rightMax[i]) - height[i];`

所以先遍历一遍数组得出每根柱子左右两边最高柱子的值并分别保存在leftMax、rightMax数组中，然后再遍历一遍求出每根柱子上遗留水的和即可。

```javascript []
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    var sum = 0;
    var len = height.length;
    var leftMax = new Array(len).fill(0);
    var rightMax = new Array(len).fill(0);
    for(var i = 1; i < len; i++){
        leftMax[i] = Math.max(height[i-1], leftMax[i-1]);
        var j = len - 1 - i;
        rightMax[j] = Math.max(height[j+1], rightMax[j+1]);
    }
    for(var i = 1; i < len; i++){
        sum += Math.max(0, Math.min(leftMax[i], rightMax[i]) - height[i]);
    }
    return sum;
};
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```
