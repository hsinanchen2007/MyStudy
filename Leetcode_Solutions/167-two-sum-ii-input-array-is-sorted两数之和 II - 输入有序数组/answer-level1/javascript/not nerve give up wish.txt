### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
    var result = []
            for(var i = 0 ; i < numbers.length ; i++ ){
                for(var j = i + 1 ; j < numbers.length ; j++ ){
                    if( numbers[i] + numbers[j] == target ){
                        result.push( i + 1 , j + 1 )
                        return result
                    }
                }
            }
};
```