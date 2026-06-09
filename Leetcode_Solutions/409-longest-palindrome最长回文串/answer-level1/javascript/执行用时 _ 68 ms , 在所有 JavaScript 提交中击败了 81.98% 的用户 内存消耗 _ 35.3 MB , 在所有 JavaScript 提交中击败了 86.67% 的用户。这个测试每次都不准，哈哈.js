### 解题思路
为了速度和内存性能着想，本着作为一个彩笔的想法，尽量少循环遍历，少增加变量。就有了以下算法。
具体思想是：哈希搭配for of遍历，每个字母出现两次的时候归零，然后在max中加2，最后只需要比较max和s的长度即可。代码一次完成，希望大家给改进下

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    const map = new Map()
    let max = 0
    for(let char of s){
        if(!map.has(char)){
            map.set(char,1)
        }else{
            map.set(char,map.get(char) + 1)
        }

        if(map.get(char)==2){
            max += 2
            map.set(char,0)
        }
    }

    return max == s.length? max: max+1
};
```