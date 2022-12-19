### 解题思路
先排序，然后当前项与前一项进行对比

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    const repeatArr =  nums.sort().filter((ele,i,arr)=>{
        return i !== 0 && ele === arr[i-1]
    })
   
    return repeatArr[parseInt(Math.random()*repeatArr.length)]
};
```