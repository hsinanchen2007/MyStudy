```javascript
/**
 * @param {character[]} letters
 * @param {character} target
 * @return {character}
 */
var nextGreatestLetter = function(letters, target) {
    let left = 0
    let right = letters.length-1
    while(left <= right){
        let mid = parseInt(left + ((right - left) >> 1))
        if(letters[mid] > target){
            right = mid - 1
        }else{
            left = mid + 1
        }
    }
    return letters[left % letters.length]
};
/**
 * 寻找目标的最小值 即为left值 如若寻找目标的最大值，即为right值
 * left % letters.length 获取取余整数
 */
```
