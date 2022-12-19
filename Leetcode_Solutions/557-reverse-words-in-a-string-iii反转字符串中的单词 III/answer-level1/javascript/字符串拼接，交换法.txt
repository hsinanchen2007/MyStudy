```javascript []
var reverseWords = function (s) {
    let Result = ''
    let arr = s.split(' ')
    let count = 0
    function reverseString(s) {
        for (let i = 0; i < s.length; i++) {
            if (i >= Math.ceil(s.length / 2)) return s
            let str1 = s[i]
            let str2 = s[(s.length - 1) - i]
            s[i] = str2
            s[s.length - 1 - i] = str1
        }
        return s
    };
    for( let i = 0; i < arr.length; i++) {
        count++
        let str = ''
        reverseString(arr[i].split('')).forEach(res => {
            str += res
        })
        if (count <= arr.length) {
            Result += str + ' '
        } else {
            Result += str
        }
        
    }

    return Result
};

console.log(reverseWords("Let's take LeetCode contest"))


/**
 * 解题思路：
 * 
 * 1. 又是一道反转，只是和以前的反转数组有点不同，这回是反转字符串内的每一个单词中的每一个字母
 * 2. 因此我们还是拒绝使用reverse这么厉害又方遍的函数。。。。。。
 * 3. 先将字符串分割，转化成数组，在拿到数组中的 每一项进行反转
 * 4. 再将字符串按格式拼接起来
 */
```
