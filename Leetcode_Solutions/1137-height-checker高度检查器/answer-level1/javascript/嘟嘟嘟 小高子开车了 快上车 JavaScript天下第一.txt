```javascript []
/**
 * @param {number[]} heights
 * @return {number}
 */
var heightChecker = function(heights) {
    // 思路 
    // 1.原数组拷贝一份
    // 2.原数组非递减排序
    // 3.比较两个数组
    let int = 0
    function sortHeights(a,b){
        return a - b
    }
    let arr = Object.assign([],heights)
    heights.sort(sortHeights)
    
    arr.forEach((val,index)=>{
        if(val != heights[index]){
            int ++
        }
    })
    return int
};
```

