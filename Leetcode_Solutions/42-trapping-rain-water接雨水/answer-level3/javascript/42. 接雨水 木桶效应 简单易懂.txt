### 解题思路
很明显，雨水接的大小取决于木桶效应，也就是当前元素左右两边最大高度中较矮的那个高度的大小

例：[0,1,0,2,1,0,1,3,2,1,2,1]

假设当前判断第三个元素，也就是0可以接多少雨水
很明显0左边最大高度为1(第二个元素)，右边最大高度为3(第7个元素)
那么0可以接的雨水量 = 左右两边最大高度中较矮的那个高度(即1) - 0自身的高度(即0) => 0

因此，可以循环整个数组，数组中的每一项都寻找左边最高的高度和右边最高的高度
当且仅当，当前项的高度 < 左右两边较矮的那个高度时，能够接水
且接水量 = 左右两边最大高度中较矮的那个高度 - 当前项的高度

### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let sum = 0
    for(let index=1; index<height.length-1; index++){
        let leftMax = 0 //找左边最大高度
        for(let i=index-1; i>=0; i--){
            leftMax = height[i] >= leftMax ? height[i] : leftMax
        }
        let rightMax = 0 //找右边最大高度
        for(let i=index+1; i<height.length; i++){
            rightMax = height[i] >= rightMax ? height[i] : rightMax
        }
        let min = Math.min(leftMax, rightMax) //得到左右两边最大高度中较矮的那个高度
        if(min > height[index]){
            sum = sum + min - height[index] //接水量 = 左右两边最大高度中较矮的那个高度 - 当前项的高度
        }
        //console.log(leftMax, rightMax, sum)
    }
    return sum
};
```