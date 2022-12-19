### 解题思路
store对象又来记录右指针遍历元素的种类和个数，当右指针当前元素个数超过1时，左指针向前移动，并把对应在store里的元素个数减一，直到右指针元素对应个数为1，继续右移，每次右移后计算左右指针之间长度，取前后最大值。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(str) {
    let start = 0, end, store = {}, maxLength = 0
    for(end = 0; end < str.length; end++){
        let rightChar = str[end]
        if(!store[rightChar]){
            store[rightChar] = 1
        }else{
            store[rightChar] += 1
        }
        while(store[rightChar] > 1){    //直到右指针元素个数为1
            let leftChar = str[start] 
            store[leftChar] -= 1
            //左针对应元素自减
            start += 1
            //左指针右移
        }
        maxLength = Math.max(maxLength, end - start + 1)
    }
    return maxLength
};
```