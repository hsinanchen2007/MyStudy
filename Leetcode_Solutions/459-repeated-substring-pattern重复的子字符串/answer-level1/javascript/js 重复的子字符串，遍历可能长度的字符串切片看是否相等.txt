一个字符串s若由一个子串重复多次构成，假设字符串长度为len，子串长度为i，则重复次数 t 为 len/i。因为三者都是整数，因此根据子字符串长度建立循环，若 len%i 为整数，则有可能由子串构成；此时子字符串为 s[0, i]，此时遍历剩余字符串，取长度为i的子字符串，若均等于 s[0, i]，则可由子串构成，结束循环；否则不可由子串构成

p.s. 想出取 s + s 的 (1, -1) 切片看是否包含 s 的都是学神吧。。。本渣渣只能想出这个笨笨的方法，不过也可用，很好理解的
 
```
/**
 * @param {string} s
 * @return {boolean}
 */
var repeatedSubstringPattern = function(s) {
    const len = s.length
    if (len === 1) return false
    let firstEle = s[0]
    let multiLen = s.split('').slice(1).filter((i) => {
        if (i === s[0]) return i
    })
    if (multiLen.length === len - 1) return true
    for(let i = 1; i < len - 1; i++) {
        if (len % i) continue
        let target = s.slice(0, i)
        for(let t = i; t < len - i + 1; t = t + i) {
            let str = s.slice(t, t + i)
            if (str !== target) break
            if (str === target && t === len - i) return true
        }
    }
    return false
};
```
