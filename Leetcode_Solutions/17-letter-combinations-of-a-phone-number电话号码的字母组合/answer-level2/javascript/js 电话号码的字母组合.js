回溯算法，String.fromCharCode() 获取数字对应的英文字母，因为 2-6、8 分别对应三个字母，7、9分别对应四个字母，所以2-6对应的开头字母是 String.fromCharCode(63 + num + 3 * (num - 2))，65 对应 A，8、9因为7对应四个字母，所以需推后一位

```
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    if (digits.length === 0) return []
    let list = []
    let fn = (str, nums) => {
        let len = nums.length
        if (str.length === digits.length) {
            list.push(str)
            return
        }
        if (len === 0) return
        let num = nums[0] * 1
        let numLen = num !== 7 && num !== 9 ? 3 : 4
        let count = 0
        if (num > 7) count++
        for(let i = 0; i < numLen; i++) {
            str += String.fromCharCode(65 + 3 * (num-2) + i + count).toLowerCase()
            fn(str, nums.slice(1, len))
            str = str.slice(0, str.length - 1)
        }
    }
    fn('', digits)
    return list
};
```
