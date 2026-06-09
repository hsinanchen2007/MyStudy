### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
            let arr = s.split(''),le = [],str='',index = 0
            if (!s) return 0
            for (let i = 0; i < arr.length; i++) {
                index = str.indexOf(arr[i])
                if (index !== -1) {
                    le.push(str.length)
                    str = str.substring(index+1,str.length)
                }
                str += arr[i]
            }
            le.push(str.length)
            return Math.max.apply(null,le)
        };
```