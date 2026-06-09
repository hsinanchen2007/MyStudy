```javascript []
var reverseString = function (s) {
    for(let i = 0; i < s.length; i++) {
        if (i >= Math.ceil(s.length / 2)) return s
        let str1 = s[i]
        let str2 = s[(s.length - 1) - i]
        s[i] = str2
        s[s.length - 1 - i] = str1
    }
    return s
};

console.log(reverseString(["h", "e", "l", "l", "o", "o", "o", "o"]))

/**
 * 解题思路：
 * 
 * 1. 由题意得知，反转数组。。。。
 * 2. 自然不能使用resveser
 * 3. 但是题目规定不能使用新的内存地址，因此我们不可以建立一个新的数组，也没必要建立其他的内存地址
 * 4. 所以我们只在原数组中操作
 * 5. 每次保存前位与后位相对应的值
 * 6. 进行一次交换，依次循环，但是我们不能让他一直循环下去，得将循环次数卡到数组的一半长度，否则做无用功
 */
```

