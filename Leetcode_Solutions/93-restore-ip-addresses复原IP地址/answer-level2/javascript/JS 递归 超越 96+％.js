### 解题思路
递归，DFS的思路，去掉不符合的情况，每次从字符串开始位置截掉长度为 1，2，3之后剩下的子串，用于递归。
注意 0开头，
### 代码

```javascript
/**
 * @param {string} s
 * @return {string[]}
 */
var restoreIpAddresses = function(s) {
    let result = [];
    function helper(s, last, segments){
        if(segments == 3){
            if(s.length <= 3 && parseInt(s.slice(0,3)) <= 255){
                if(s.length >= 2 && s.charAt(0) == "0"){
                    return
                }
                let item = last.concat(s)
                result.push(item);
                return
            }
        }
        if(segments < 3){
            let item = last.concat(s.slice(0,1)).concat(".");
            helper(s.slice(1), item, segments+1)
            if(s.charAt(0) != "0"){
                item = last.concat(s.slice(0,2)).concat(".")
                helper(s.slice(2), item, segments+1)
                if(parseInt(s.slice(0,3)) <= 255){
                    item = last.concat(s.slice(0,3)).concat(".")
                    helper(s.slice(3), item, segments+1);
                }
            }
        }
    }
    helper(s, "", 0);
    return result;
};
```