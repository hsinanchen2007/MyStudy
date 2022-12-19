### 解题思路
为了力求一次循环解决问题
将数组化的字符串在循环中set到对象里，并对对应的下标做判断
如果遇到已经存在的字母，则会触发改变最长长度的变化
max始终记录最长的下标差
最后返回max为题目要求的字段

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let tempArr = {}
    let max = 0
    let start = -1
    let end = -1
    if (s){
        let sArr = s.split('')
        for (let i=0;i<sArr.length;i++){
            let el = sArr[i]
            if(!tempArr[el] && tempArr[el] != 0 || start > tempArr[el]){
                tempArr[el] = i
                end = i
            }else{
                // let len = end - start
                max = max < end - start ? end - start : max
                if (max>sArr.length-start){
                    break
                }
                start = tempArr[el]
                tempArr[el] = i
                end = i
            }
        }
        max = max < end - start ? end - start : max
    }
    return max
};

```