### 解题思路
首先容错处理，如果长度不相等，直接false
然后思路就是确定两个字符串中每个字符出现的次数是一样的
把字母当做key，出现此处为value
如果可以直接判断两个对象相等就好了
### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    let d1 ={}
    let d2 ={}
    if(s.length !==t.length){
        return false
    }
    for(let temp of s){
        d1[temp] = (d1[temp] == null ? 1 :++d1[temp]);
    }
    for(let temp of t){
        if(!d1[temp]){
            return false
        }
        d1[temp] = --d1[temp];
        if(d1[temp] < 0){
            return false
        }
    }

    return true
};


```