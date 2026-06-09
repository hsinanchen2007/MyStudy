### 解题思路
...

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(items) {
    let length = items.length
        for(let i = 0; i < length; i++) {
            let min = i
            for(let j = min+1; j < length; j++) {
                if(items[min] > items[j]) {
                   min = j
                }
            }
            let temp = items[min]
            items[min] = items[i]
            items[i] = temp
        }
    return items
};
```