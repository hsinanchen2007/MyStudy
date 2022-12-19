### 执行结果
![QQ截图20200326170311.png](https://pic.leetcode-cn.com/265b2a849b37a8f377341fdd195dae635ba88a564fd1e81f2fb7c2115900eed1-QQ%E6%88%AA%E5%9B%BE20200326170311.png)

### 解题思路
从最终结果来看，填满水后应该是从两侧向整体最高点递增的效果，因而自然可以想到双指针法。

### 代码

```javascript
var trap = function (height) {
    let left = 0 // 左指针
    let right = height.length - 1 //右指针
    let sum = 0 // 承接雨水量
    while (height[left] == 0) left++ // 找到左侧边缘
    if (left === right + 1) return 0 // 根本没有柱子
    while (height[right] == 0) right-- // 找到右侧边缘
    let left_top = height[left] // 左侧当前最高
    let right_top = height[right] // 右侧当前最高
    while (true) {
        if (left === right) return sum // 对于只有一个柱子的情况
        while (left_top <= right_top) { // 在左侧最高超越右侧之前
            if (height[++left] <= left_top) sum += (left_top - height[left]) 
            //如果下一个更矮则添水
            else
                left_top = height[left] //否则更新左侧最高
            if (left === right) return sum // 如果左右指针相遇则完成
        }
        while (left_top >= right_top) { // 在右侧最高超越左侧之前
            if (height[--right] <= right_top) sum += (right_top - height[right])
            //如果前一个更矮则添水
            else
                right_top = height[right] // 否则更新右侧最高
            if (left === right) return sum // 如果左右指针相遇则完成
        }
    }
};
```