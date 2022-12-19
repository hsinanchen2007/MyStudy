### 解题思路
首先，我们理清思路，明确有两个任务：1.检测`words`中的单词是否由`chars`中的组成；2.保证`chars`中的每个字母在每个单词查询中只使用一次。

针对第一个任务，我们可以采用双重循环的方式，并且使用`includes()`函数进行辨别，会返回布尔型的值。只要出现`false`，就跳出循环，当循环到单词最后一个时，且能在`chars`中找到，那么就记录（加上单词长度）。

对于第二个任务，因为`chars`是一个值类型变量，直接可以赋值给另一个变量，那么我们每循环一次，就赋值一次，为了确保每个字母只使用一次，所以`replace()`函数，将出现过的字母去掉。

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    let count = 0;
    for (let i=0;i<words.length;i++){
        let char = chars;
        for (let x=0;x<words[i].length;x++){
            if (!char.includes(words[i][x])){
                break;
            }else if (x === words[i].length-1 && char.includes(words[i][x])){
                count +=words[i].length;
            }
            char=char.replace(words[i][x],"");
        }
    }
    return count;
};
```