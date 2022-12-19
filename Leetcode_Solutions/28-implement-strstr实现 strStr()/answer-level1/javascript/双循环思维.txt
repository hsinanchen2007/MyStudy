### 解题思路
循环haystack 暂存循环数temp 为了能直接返回下表
while循环needle k1复制i为了在后面+1上不影响haystack的循环
做符合neele的第一项 则双方继续匹配第二项 知道不符合 或k2循环完needle
若不符合 重置needle循环 haystack 继续

### 代码

```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    if (needle.length ==0) return 0
    for(let i=0;i<haystack.length;i++){
        let temp = i
        let k1 = i
        let k2 = 0
        while(haystack[k1] == needle[k2]){
                if(k2+1 == needle.length){
                    return temp
                }
            k1++
            k2++
            
        }
    }
    return -1
};
```