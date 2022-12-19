### 解题思路
#### 思路描述：
 通过观察回文串可以总结出几个特点，
 1、产出的回文串最大长度大于原字符串的长度
 2、回文串中如果小于字符串总长度，说明字符串中一定有多个奇数个字母，这时只能取其中一个
 3、回文串总长度是奇数时，必有一个字符存在的个数是奇数 例如 "bcb"
 4、回文串总长度是偶数时，所有字符存在的个数定是偶数 例如 "bb" 
 #### 实现过程：
 将字符串转换成数组，通过 Map 记录数组中的每一项出现的个数，判断对应字符的个数是奇数还是偶数，
 如果是奇数，则取最大偶数个加到总长度中，如果是偶数，直接加到总长度中，
 回文串总长度如果小于字符串的总长度，需要加一个出现数量为奇数个的字母
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let sArray = s.split(""), sMap = new Map(), maxLen = 0;
    for(let i = 0; i < sArray.length; i++){
        let sItem = sArray[i];
        sMap.set(sItem, sMap.get(sItem)? sMap.get(sItem) + 1 : 1);
    }
    sMap.forEach((value,key)=>{
        maxLen += value%2? value - value%2 : value;
    });
    return maxLen >= sArray.length?maxLen : maxLen + 1;
};
```