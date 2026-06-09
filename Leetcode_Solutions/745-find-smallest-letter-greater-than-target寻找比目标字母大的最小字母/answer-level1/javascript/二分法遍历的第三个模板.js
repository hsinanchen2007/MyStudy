### 解题思路
此处要先判断特殊情况，一种是都小于目标的选第一个，还有就是都大于的也选第一个
再就是不需要找到相同的目标，因为他的后一个可能还是相同的

### 代码

```javascript
/**
 * @param {character[]} letters
 * @param {character} target
 * @return {character}
 */
var nextGreatestLetter = function(letters, target) {
    if(letters ==null) {return letters}
    let l = 0 ,r = letters.length -1;
    if(target >= letters[r] || target < letters[l]) {return letters[0]}

    let mid;
    while(l +1 < r){
        mid = Math.round(l + (r - l)/2)
      if(letters[mid] > target){
            r = mid
        }else {
            l = mid 
        }
    } 
    return letters[r] 
};
```