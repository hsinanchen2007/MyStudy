### 解题思路
1.定义判断回文字符串的函数，保证每一个子串必须是回文子串，我们才进行后续的操作
2.通过递归判断，确定当前子串是回文子串后，我们得将剩余的子串也判断是否为子串

### 代码

```javascript
/**
 * @param {string} s
 * @return {string[][]}
 */
var partition = function(s) {
    // 定义是否为回文字符串
    const isPalidrome = (str) => {
        let left = 0, right = str.length-1
        while(left < right) {
            if (str.charAt(left) !== str.charAt(right)) return false

            right--
            left++
        }
        return true
    }

    // 定义回溯算法
    const backTrack = (res, str, tempRes) => {
        // 需要注意，这里必须是 tempRes 的拷贝
        if (str.length === 0) {
            res.push(tempRes.concat())
        }

        for (let i = 1; i <= str.length; i++) {

            if (isPalidrome(str.substring(0, i))) {
                tempRes.push(str.substring(0, i))
                backTrack(res, str.substring(i, str.length), tempRes)
                // 返回上一次递归时，需要去除这次递归的回文子串
                tempRes.pop()
            }
        }
    }
    let res = []
    backTrack(res, s, [])
    return res
};
```