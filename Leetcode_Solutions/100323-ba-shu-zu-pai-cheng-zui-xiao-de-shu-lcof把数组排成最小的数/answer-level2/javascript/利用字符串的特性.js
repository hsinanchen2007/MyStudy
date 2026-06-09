### 解题思路
看注释

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {string}
 */
var minNumber = function(nums) {
    return minNums = nums.sort((a,b)=>{
        //利用js特性
        //字符串之间相减会像number一样正常减掉，会被转换成number
        //字符串之间相加会转换成两个字符串之间拼接，会被转换成string
        if(`${a}${b}` - `${b}${a}` > 0){
            //b 会被排列到 a 之前
            return 1
        }else{
            //小于 0,a 会被排列到 b 之前
            return -1;
        }
    }).join("")
};
```