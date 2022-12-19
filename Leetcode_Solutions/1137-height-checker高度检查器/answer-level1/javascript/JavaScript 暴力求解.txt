### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/57ff9d914225309342d63850283f55b05ca0530ac43067a0e570046365651477-image.png)


- 通过遍历「深拷贝」一个数组
- 通过 sort（），对这个新数组进行排序
- 然后对比先后数组对应位置的值，如果有变化，说明有移动


### 代码

```javascript
/**
 * @param {number[]} heights
 * @return {number}
 */
var heightChecker = function(heights) {
    let arr = []
    for(let i = 0; i < heights.length; i++){
        arr[i] = heights[i]
    }
    arr = arr.sort((a,b) => a - b)
    let num = 0
    for(let i = 0; i < arr.length; i++){
        if(arr[i] != heights[i]){
            num++
        }
    }
    return num
    
};
```