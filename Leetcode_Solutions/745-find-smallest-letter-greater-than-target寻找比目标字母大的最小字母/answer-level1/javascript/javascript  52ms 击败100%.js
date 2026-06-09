### 解题思路
因为是有序数组，所以解题思路就是二分。
有一点需要注意

1. 题中没说如果数组中所有字母都比目标小如何处理，答案是返回数组中的第一个元素

### 代码

```javascript
/**
 * @param {character[]} letters
 * @param {character} target
 * @return {character}
 */
var nextGreatestLetter = function(letters, target) {
    let low=0
    let high=letters.length;
    while(low<=high){
        let mid=Math.floor(low+(high-low)/2)
        if(letters[mid]>target){
            high=mid-1
        }
        else{
            low=mid+1
        }
    }
    return low>=letters.length?letters[0]:letters[low]
};
```