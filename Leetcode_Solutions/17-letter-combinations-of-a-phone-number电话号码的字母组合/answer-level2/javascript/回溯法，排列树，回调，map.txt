### 解题思路
结果如下：
![image.png](https://pic.leetcode-cn.com/ed86665981dd1423080c56789b48afb33987b95a74670ef77c286fbca8272dbb-image.png)

类似于生成一个树（有点回溯法的感觉），顶点是第一个数字，下面的根是数字里面的字母，然后字母下面在一个数字

代码应该挺好理解

### 代码

```javascript
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    if(digits.length == 0) {
        return []
    }
    let resArr = [];
    const letter = {
        '2': ['a', 'b', 'c'],
        '3': ['d', 'e', 'f'],
        '4': ['g', 'h', 'i'],
        '5': ['j', 'k', 'l'],
        '6': ['m', 'n', 'o'],
        '7': ['p', 'q', 'r', 's'],
        '8': ['t', 'u', 'v'],
        '9': ['w', 'x', 'y', 'z']
    };
    
    // 使用回溯法
    function _generate(str, arr) {// 'a', [2,3] 
        if(arr.length == 0) {
            resArr.push(str)
        } else {
            let newarr = [...arr];
            let k = newarr.shift();
            for(let n of letter[k]) {
                let gstr = str + n;
                _generate(gstr, newarr)
            }
        }
    }
    var numArr = digits.split("");
    _generate("", numArr);
    return resArr
};
```