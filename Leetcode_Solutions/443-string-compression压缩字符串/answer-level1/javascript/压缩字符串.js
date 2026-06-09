### 解题思路

1. 找到与当前元素一样的数量，直到下一个元素与当前元素不相等时跳出；
2. 只有数量大于1时才要去修改数据；
3. 将数量 `count` 处理为数组；
4. 使用 `splice` 去删除下一个元素，删除 `count - 1`(把当前元素减去)，并把 `countArr` 添加到删除的位置；
5. 修改指针。

### 代码

```javascript
/**
 * @param {character[]} chars
 * @return {number}
 */
var compress = function(chars) {
    let { length } = chars;
    for(let i = 0, j = 0; i < length; i++){
        let count = 0;
        chars[i] = chars[i].toString();
        while(j < length){
            if(chars[i] != chars[j]){
                break;
            };
            count++;
            j++;
        }
        if(count > 1){
            let countArr = count.toString().split('');
            chars.splice(i + 1, count - 1, ...countArr);
            length = chars.length;
            i += countArr.length;
            j = i + 1;
        }
    }
    return chars.length;
};
```