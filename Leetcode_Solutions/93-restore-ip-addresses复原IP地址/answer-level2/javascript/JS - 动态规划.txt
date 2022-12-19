### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {string[]}
 */
var restoreIpAddresses = function(s) {
    // DP
    const cache = {};
    const isRightIp = (str) => {
        if (str === '0') {
            return true;
        }
        if (str.charAt(0) === '0' && str.length > 1) {
            return false;
        }
        str = parseInt(str);
        if (str >=0 && str <= 255) {
            return true;
        } else {
            return false;
        }
    }
    const findIpWithNum = (str, num) => {
        let key = `${str}_${num}`;
        let val = cache[key];
        if (!val) {
            val = [];
            cache[key] = val;
            if (num === 1 && isRightIp(str)) {
                val.push(str);
            } else if (num > 1){
                for (let i=1; i<=3; i++) {
                    let currIp = str.substr(0, i);
                    let newStr = str.substr(i);
                    if (isRightIp(currIp)) {
                        findIpWithNum(newStr, num-1).forEach((item) => {
                            val.push(`${currIp}.${item}`);
                        });
                    }
                }
            }
        }
        return val;
    }
    return findIpWithNum(s, 4);
};
```