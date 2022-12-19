```javascript
/**
 * @param {string[]} list1
 * @param {string[]} list2
 * @return {string[]}
 */
var findRestaurant = function(list1, list2) {
    let hash = {}
    
    let len1 = list1.length
    let len2 = list2.length
    
    let minLen = len1 + len2 - 2
    let i1 = 0
    let i2 = 0
    
    let result = []
    
    while((i1 < len1) || (i2 < len2)) {
        if (i1 < len1) {
            const c = list1[i1]
            if (hash[c] || hash[c] === 0) {
                if (hash[c] + i1 < minLen) {
                    minLen = hash[c] + i1;
                    result = [ c, ]
                } else if (hash[c] + i1 === minLen) {
                    result.push(c)
                }
            } else {
                hash[c] = i1
            }
            
            ++i1
        }
        
        if (i2 < len2) {
            const c = list2[i2]
            if (hash[c] || hash[c] === 0) {
                if (hash[c] + i2 < minLen) {
                    minLen = hash[c] + i2;
                    result = [ c, ]
                } else if (hash[c] + i2 === minLen) {
                    result.push(c)
                }
            } else {
                hash[c] = i2
            }
            
            ++i2
        }
    }
    
    return result
};
```