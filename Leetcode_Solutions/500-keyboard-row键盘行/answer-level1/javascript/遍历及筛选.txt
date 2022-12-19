
## 遍历及筛选


- 按字母键盘分成三个串；
- 判断单词列表的首字符选择所属串行，并遍历单词列表；
- 有一个字母不满足当前列表内的单词，跳出内n遍历，不推进队列；

```
执行用时 :56 ms, 在所有 javascript 提交中击败了 90.84% 的用户
内存消耗 :34.2 MB, 在所有 javascript 提交中击败了 5.97% 的用户
```
```
/**
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(words) {
    var row1 = 'qwertyuiop',
        row2 = 'asdfghjkl',
        row3 = 'zxcvbnm',
        ws = words.map(m => m.toLowerCase()),
        res = []
    for(var i =0; i<ws.length; i++){
        var wd = ws[i]
        var curRow = row1.includes(wd[0]) ? row1 : row2.includes(wd[0]) ? row2 : row3
        var isInc = true
        for(var j=0; j<wd.length; j++){
            if(!curRow.includes(wd[j])){
                isInc = false
                break
            }
        }
        isInc && res.push(words[i])
    }
    return res
};
```


#### 时间复杂度 `O(n^2)`；

#### 空间复杂度 `O(n)`:
- `这里除了map和result结果，没有开辟另外的数组空间， 也没有做字符串和数组的转换。`


