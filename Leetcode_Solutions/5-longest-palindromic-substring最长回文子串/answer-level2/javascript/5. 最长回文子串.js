### 解题思路
最长的回文子串

规律：
1.长度为1的回文子串：每个元素都是回文子串，因为第i个元素和第i个元素相等，例如："b","a","b","a","d"
2.长度为2的回文子串：满足第i个元素和第i+1个元素相同，例如："bb"
3.长度为3的回文子串：首先满足第i个和自己相等，然后满足i-1和i+1的元素相等，例如："aba"

假设现在有一个用于判断回文子串的函数，它接受三个参数，分别是左下标，右下标，和字符串本身，那么有两种情况
第一：从第i个元素和第i个元素开始找起，然后开始判断i-1和i+1上的元素是否相等，对应规律1和3
第二：从第i个元素和第i+1个元素开始找起，对应规律2

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    let maxStr = "", resStr = ""
    if(!s || s.length < 1) return ""
    for(let i=0; i<s.length; i++){
        let str1 = findLongestSubString(i, i, s) //第一种情况
        let str2 = findLongestSubString(i, i+1, s) //第二种情况
        //console.log("str1", str1, "str2", str2)
        maxStr = str1.length > str2.length ? str1 : str2
        if(maxStr.length > resStr.length){
            resStr = maxStr
        }
    }
    return resStr
    
};

function findLongestSubString(leftIndex, rightIndex, s){
    while(leftIndex>=0 && rightIndex<s.length && s[leftIndex] === s[rightIndex]){
        leftIndex--
        rightIndex++
    }
    return s.substring(leftIndex + 1, rightIndex)
}
```