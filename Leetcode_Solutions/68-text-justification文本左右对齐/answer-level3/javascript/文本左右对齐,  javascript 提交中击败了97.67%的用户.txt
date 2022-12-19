### 思路

题目要求我们将字符数组中的字符，按照左右对齐的规则，重新排列组合后输出。根据其规则，我们可以用递归调用的方式，每次处理一行的数据，在处理每一行的时候我们需要考虑以下条件:

* 每一行中至少有一个单词。
* 每一行根据其长度塞入尽量多的单词，属于的空位由空格填充。空格的分布根据行数有区别:
    * 除最后一行外，空格填充在单词之间，先平均填充空格，多的空格再依次填充于前面的单词之间。例如`'a  computer.  Art is'`，先每个单词间填充一个空格，多余的两个空格填充于前两个单词间。
    * 对于最后一行，单词间均填充一个空格，多余的空格填充于末端。如`'shall be        '`
### 完整题解
```
执行用时 :56 ms, 在所有 javascript 提交中击败了97.67%的用户
内存消耗 :33.8 MB, 在所有 javascript 提交中击败了19.44%的用户
```
```JavaScript []
var fullJustify = function (words, maxWidth) {

    const appendLine = (words, maxWidth, res, start) => {
        if (start >= words.length) {
            return res;
        }
        // 存储本行的单词
        let rowArr = [words[start]],
        // 记录当前的单词以及单词间至少一个空格的总长度。
            count = words[start].length,
            i = start + 1;
        // i < words.length 且 count 加上最新的单词长度小于 maxWidth
        while (i < words.length && count + words[i].length < maxWidth) {
            // 记录单词及单个空格的长度
            count += words[i].length + 1;
            rowArr.push(words[i]);
            i++;
        }

        let rowStr = '';
        if (i < words.length) {
            // 总共的空格数
            let space = maxWidth - count + rowArr.length - 1;
            // 每一个单词间的空格数
            let eachSpace = parseInt(space / (rowArr.length - 1));
            // 多余的空格数
            let extSpace = space % (rowArr.length - 1);
            for (let j = 0; j < rowArr.length; j++) {
                rowStr += rowArr[j];
                if (j !== rowArr.length - 1) {
                    let space = eachSpace;
                    // 多余的空格依次填充于前面的单词之间
                    if (extSpace > 0) {
                        space += 1;
                        extSpace--;
                    }
                    while (space-- > 0) {
                        rowStr += ' '
                    }
                }
            }
        } else {
            // 若为最后一行，单词间仅有一个空格。
            for (let j = 0; j < rowArr.length; j++) {
                if (j < rowArr.length - 1) {
                    rowStr += rowArr[j] + ' ';
                } else {
                    rowStr += rowArr[j];
                }
            }
        }
        // 填充空格于单行字符串末尾，处理最后一行以及单行只有一个单词的情况。
        while (rowStr.length < maxWidth) {
            rowStr += ' ';
        }

        res.push(rowStr);
        return appendLine(words, maxWidth, res, i);
    }

    return appendLine(words, maxWidth, [], 0);
};
```