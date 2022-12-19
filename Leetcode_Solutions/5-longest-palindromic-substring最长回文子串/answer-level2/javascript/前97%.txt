### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    if(!s) return s
    var range=[0,0],len = s.length
    function findLongest(s, low, range,len){
        let high = low, res
        while(high < len-1 && s[high+1] ===s[low]) //中间重复部分
        high++
        res = high
        //向两边扩展寻找
        while(low > 0 && high < len-1 && s[low-1] === s[high+1]){
            low--
            high++
        }
        if(high -low > range[1]- range[0]){
            range[0] = low
            range[1] = high
        }
        return res
    }
    for(let i=0; i<len; i++){
        i = findLongest(s, i, range,len)
    }
    return s.slice(range[0], range[1]+1)
};

```