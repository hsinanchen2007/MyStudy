### 解题思路
根据题解给出的提示，js没有堆栈，假设放进数组中，将出现的属于左边的放入数组中，下一个出现的右边，能将数组中最后一个左边元素抵消掉，直到数组内元素全都抵消掉，那么则是有效闭合的括号。
借助map，将括号左边以右边存入，以便能和括号右边的进行比较。

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let map = new Map();
    map.set('(', ')');
    map.set('{', '}');
    map.set('[', ']');

    let tmp = [];
    for(let i = 0; i < s.length; i++){
        // 如果当前元素不等于数组中的最后一个元素
        if(s[i] != tmp[tmp.length - 1]){
            // 如果是在map中存在的，则为左边的元素，反之，则不闭合
            if(map.has(s[i])){
                // 将相对应的右边存入数组
                tmp.push(map.get(s[i]));
            }else{
                return false;
            }
        }else{ // 如果该元素等于数组中最后一个元素，删除数组中最后一个元素
            tmp.pop(tmp.length - 1);
        }
    }
    return tmp.length == 0 ? true : false;
};
```